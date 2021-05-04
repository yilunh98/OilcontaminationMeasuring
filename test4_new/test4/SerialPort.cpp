#include"SerialPort.h"
#include <sstream>
#include<iostream>
#include <windows.h>
#include <QString>
#include <QDebug>

Q_GLOBAL_STATIC(SerialPort, m_pMyClass)
//构造函数，将m_hComm初始化为无效的句柄
SerialPort::SerialPort():QObject(NULL)
{
	//初始化内部变量
	m_hComm = INVALID_HANDLE_VALUE;
	m_OnSeriesRead = NULL;
	m_bOpened = 0;
	overlapThread = new MyThread(this);
	//data_receive = "";

}
SerialPort& SerialPort::getInstance()
{
    static SerialPort instance;
    return instance;
}

//析构函数，检测如果串口是打开的，则关闭串口
SerialPort::~SerialPort()
{
	if (m_bOpened)
	{
		//关闭串口
		ClosePort();
	}
}
//串口读线程函数，该线程用于异步接收串口数据。大家应仔细理解该线程的具体实现过程，
//该线程通过循环调用WaitCommEvent函数来检测串口状态，当发现有数据时，调用ReadFile
//函数读取数据，并触发回调函数，由此实现串口数据的实时异步读取。
DWORD SerialPort::ReadThreadFunc()
{
	
	//SerialPort& ceSeries = getInstance();
	DWORD evtMask=0;
	char * readBuf = NULL;//读取的字节
	DWORD actualReadLen=0;//实际读取的字节数
	DWORD willReadLen;
	DWORD dwReadErrors;
	COMSTAT cmState;
	// 清空缓冲，并检查串口是否打开。
	ASSERT(m_hComm !=INVALID_HANDLE_VALUE);
	//清空串口
	PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR );
	SetCommMask (m_hComm, EV_RXCHAR | EV_CTS | EV_DSR );
	
	while (TRUE)
	{	
		if (WaitCommEvent(m_hComm,&evtMask,0))
		{
			SetCommMask (m_hComm, EV_RXCHAR | EV_CTS | EV_DSR );
			//表示串口收到字符
			qDebug()<<"get something";
			Sleep(200);
			if (evtMask & EV_RXCHAR)
			{
				ClearCommError(m_hComm,&dwReadErrors,&cmState);
				willReadLen = cmState.cbInQue ;
				if (willReadLen <= 0)
				{
					continue;
				}
				//分配内存
				readBuf = new char[willReadLen];
				ZeroMemory(readBuf,willReadLen);
				//读取串口数据
				ReadFile(m_hComm, readBuf, willReadLen,&actualReadLen,0);
				//如果读取的数据大于，
				if (actualReadLen>0)
				{
					int len=MultiByteToWideChar(CP_ACP,0,readBuf, -1, NULL,0);
					wchar_t *w_buf = new wchar_t[len];
					memset(w_buf,0,sizeof(wchar_t)*len);
					MultiByteToWideChar(CP_ACP, 0, readBuf,-1,w_buf, len);
					QString str = QString::fromWCharArray(w_buf);
					//data_receive = str;
					//emit getdata(10);
					emit writeText(str);
					qDebug()<<"call:"<<str;

					////触发读取回调函数
					//if (ceSeries->m_OnSeriesRead)
					//{
					//	ceSeries->m_OnSeriesRead(ceSeries->m_pOwner,readBuf,actualReadLen);
					//}
				}
				//释放内存
				delete[] readBuf;
				readBuf = NULL;
			}
		}
		//如果收到读线程退出信号，则退出线程
		if (WaitForSingleObject(m_hReadCloseEvent,500) == WAIT_OBJECT_0)
		{
			qDebug()<<"go out of thread read func";
			break;
		}
	}
	return 0;
}

//关闭读线程
void SerialPort::CloseReadThread()
{
	//设置读线程退出信号
	SetEvent(m_hReadCloseEvent);
	//设置所有事件无效无效
	SetCommMask(m_hComm, 0);
	//清空所有将要读的数据
	PurgeComm( m_hComm, PURGE_RXCLEAR );
	//等待秒，如果读线程没有退出，则强制退出

	qDebug()<<"close read thread";
	
	//if (WaitForSingleObject(m_hReadThread,4000) == WAIT_TIMEOUT)
	//{
	//	TerminateThread(m_hReadThread,0);
	//}
	//m_hReadThread = NULL;
}
/*
*函数介绍：打开串口
*入口参数：pPortOwner :使用此串口类的窗体句柄
portNo :串口号
baud :波特率
parity :奇偶校验
databits :数据位
stopbits :停止位
*出口参数：(无)
*返回值：TRUE:成功打开串口;FALSE:打开串口失败
*/
//供外部调用此方法打开串口，该函数将根据制定的参数打开串口，并创建此串口的读线程
//以实现串口数据实时异步读操作。
BOOL SerialPort::OpenPort(void * pOwner,
						UINT portNo , /*串口号*/
						UINT baud , /*波特率*/
						UINT parity , /*奇偶校验*/
						UINT databits , /*数据位*/
						UINT stopbits /*停止位*/	
						)
{
	DCB commParam;
	TCHAR szPort[15];
	ASSERT(pOwner!=NULL);
	m_pOwner = pOwner;
	// 已经打开的话，直接返回
	if (m_hComm != INVALID_HANDLE_VALUE)
	{
		return TRUE;
	}
	//设置串口名
	wsprintf(szPort, L"COM%d:", portNo);
	//打开串口
	m_hComm = CreateFile(szPort,
						 GENERIC_READ | GENERIC_WRITE, //允许读和写
						 0, //独占方式（共享模式）
						 NULL,
						 OPEN_EXISTING, //打开而不是创建（创建方式）
						 0,
						 NULL
						);
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		// 无效句柄,返回。
		//TRACE(_T("CreateFile 返回无效句柄\n"));
		return FALSE;
	}
	// 得到打开串口的当前属性参数，修改后再重新设置串口。
	if (!GetCommState(m_hComm,&commParam))
	{
		//关闭串口
		CloseHandle (m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
		return FALSE;
	}
	//设置串口参数
	commParam.BaudRate = baud; // 设置波特率
	commParam.fBinary = TRUE; // 设置二进制模式，此处必须设置
	//TRUE
	commParam.fParity = TRUE; // 支持奇偶校验
	commParam.ByteSize = databits; // 数据位,范围:4-8
	commParam.Parity = parity; // 校验模式
	commParam.StopBits = stopbits; // 停止位
	commParam.fOutxCtsFlow = FALSE; // No CTS output flow control
	commParam.fOutxDsrFlow = FALSE; // No DSR output flow control
	commParam.fDtrControl = DTR_CONTROL_ENABLE;
	// DTR flow control type
	commParam.fDsrSensitivity = FALSE; // DSR sensitivity
	commParam.fTXContinueOnXoff = TRUE; // XOFF continues Tx
	commParam.fOutX = FALSE; // No XON/XOFF out flow control
	commParam.fInX = FALSE; // No XON/XOFF in flow control
	commParam.fErrorChar = FALSE; // Disable error replacement
	commParam.fNull = FALSE; // Disable null stripping
	commParam.fRtsControl = RTS_CONTROL_ENABLE;
	// RTS flow control
	commParam.fAbortOnError = FALSE; // 当串口发生错误，并不终止串口
	//读写
	//设置串口参数
	if (!SetCommState(m_hComm, &commParam))
	{
		//TRACE(_T("SetCommState error"));
		//关闭串口
		CloseHandle (m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
		return FALSE;
	}
	//设置串口读写时间
	COMMTIMEOUTS CommTimeOuts;
	GetCommTimeouts (m_hComm, &CommTimeOuts);
	CommTimeOuts.ReadIntervalTimeout = MAXDWORD;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = 0;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 10;
	CommTimeOuts.WriteTotalTimeoutConstant = 1000;
	if(!SetCommTimeouts( m_hComm, &CommTimeOuts ))
	{
		//TRACE( _T("SetCommTimeouts 返回错误") );
		//关闭串口
		CloseHandle (m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
		return FALSE;
	}
	//指定端口监测的事件集
	SetCommMask (m_hComm, EV_RXCHAR);
	//分配串口设备缓冲区
	SetupComm(m_hComm,512,512);
	//初始化缓冲区中的信息
	PurgeComm(m_hComm,PURGE_TXCLEAR|PURGE_RXCLEAR);
	//CString strEvent;
	//strEvent.Format(L"Com_ReadCloseEvent%d",portNo);
	LPCWSTR astrEvent;
	std::string strEvent;
	std::stringstream ss;
	qDebug()<<"open port success";
	ss<<"Com_ReadCloseEvent"<<portNo<<"tuxiang";
	ss>>strEvent;
	astrEvent = (LPCWSTR)strEvent.c_str();
	m_hReadCloseEvent = CreateEvent(NULL,TRUE,FALSE,astrEvent);
	overlapThread->start();
	//创建串口读数据监听线程
	//m_hReadThread =
	//CreateThread(NULL,0,ReadThreadFunc,this,0,&m_dwReadThreadID);
	//TRACE(_T("串口打开成功"));
	m_bOpened = TRUE;
	return TRUE;
}
/*
*函数介绍：关闭串口
*入口参数：(无)
*出口参数：(无)
*返回值： (无)
*/
//该函数将退出串口读线程，并关闭串口句柄。
void SerialPort::ClosePort()
{
	//表示串口还没有打开
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		return ;
	}
	//关闭读线程
	//CloseReadThread();
	overlapThread->stop();
	//if (overlapThread->isRunning()) {
	//	overlapThread->stop();
	//	if (QThread::currentThread() != overlapThread)
	//		overlapThread->wait();}
	//关闭串口
	CloseHandle (m_hComm);
	//关闭事件
	CloseHandle(m_hReadCloseEvent);
	qDebug()<<"close handle event successfuly";
	m_hComm = INVALID_HANDLE_VALUE;
	m_bOpened = FALSE;
}
/*
*函数介绍：往串口写入数据
*入口参数：buf ：待写入数据缓冲区
bufLen : 待写入缓冲区长度
*出口参数：(无)
*返回值：TRUE:设置成功;FALSE:设置失败
*/
//供外部调用来向串口发送数据。
BOOL SerialPort::WriteSyncPort(const char *buf , DWORD bufLen)
{
	DWORD dwNumBytesWritten;
	DWORD dwHaveNumWritten =0 ; //已经写入多少
	int iInc = 0; //如果次写入不成功，返回FALSE
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);
	do
	{
		if (WriteFile (m_hComm, //串口句柄
					   buf+dwHaveNumWritten, //被写数据缓冲区
					   bufLen - dwHaveNumWritten, //被写数据缓冲区大小
					   &dwNumBytesWritten, //函数执行成功后，返回实际向串口写的个数
					   NULL)) //此处必须设置NULL
		{
			dwHaveNumWritten = dwHaveNumWritten + dwNumBytesWritten;
			//写入完成
			if (dwHaveNumWritten == bufLen)
			{
				break;
			}
			iInc++;
			if (iInc >= 3)
			{
				return FALSE;
			}
			Sleep(10);
		}
		else
		{
			return FALSE;
		}
	}while (TRUE);
	return TRUE;
}
/*
*函数介绍：设置串口读取、写入超时
*入口参数：CommTimeOuts : 指向COMMTIMEOUTS结构
*出口参数：(无)
*返回值：TRUE:设置成功;FALSE:设置失败
*/
//供外部调用来设置串口读取，写入超时。
BOOL SerialPort::SetSeriesTimeouts(COMMTIMEOUTS CommTimeOuts)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);
	return SetCommTimeouts(m_hComm,&CommTimeOuts);
}
//得到串口是否打开
BOOL SerialPort::GetComOpened()
{
	return m_bOpened;
}

MyThread::MyThread(SerialPort *qesp):
    QThread()
{
	this->qesp = qesp;
	terminate = false;
}
MyThread::~MyThread(){
}
void MyThread::run()
{
	qDebug()<<"start threading";
    while (!terminate)
		qesp->ReadThreadFunc();
	terminate = false;
}
void MyThread::stop(){
	terminate = true;
	qDebug()<<"trying to terminate";
	qesp->CloseReadThread();
}