#include"SerialPort.h"
#include <sstream>
#include<iostream>
#include <windows.h>
#include <QString>
#include <QDebug>

Q_GLOBAL_STATIC(SerialPort, m_pMyClass)
//���캯������m_hComm��ʼ��Ϊ��Ч�ľ��
SerialPort::SerialPort():QObject(NULL)
{
	//��ʼ���ڲ�����
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

//���������������������Ǵ򿪵ģ���رմ���
SerialPort::~SerialPort()
{
	if (m_bOpened)
	{
		//�رմ���
		ClosePort();
	}
}
//���ڶ��̺߳��������߳������첽���մ������ݡ����Ӧ��ϸ�����̵߳ľ���ʵ�ֹ��̣�
//���߳�ͨ��ѭ������WaitCommEvent��������⴮��״̬��������������ʱ������ReadFile
//������ȡ���ݣ��������ص��������ɴ�ʵ�ִ������ݵ�ʵʱ�첽��ȡ��
DWORD SerialPort::ReadThreadFunc()
{
	
	//SerialPort& ceSeries = getInstance();
	DWORD evtMask=0;
	char * readBuf = NULL;//��ȡ���ֽ�
	DWORD actualReadLen=0;//ʵ�ʶ�ȡ���ֽ���
	DWORD willReadLen;
	DWORD dwReadErrors;
	COMSTAT cmState;
	// ��ջ��壬����鴮���Ƿ�򿪡�
	ASSERT(m_hComm !=INVALID_HANDLE_VALUE);
	//��մ���
	PurgeComm(m_hComm, PURGE_RXCLEAR | PURGE_TXCLEAR );
	SetCommMask (m_hComm, EV_RXCHAR | EV_CTS | EV_DSR );
	
	while (TRUE)
	{	
		if (WaitCommEvent(m_hComm,&evtMask,0))
		{
			SetCommMask (m_hComm, EV_RXCHAR | EV_CTS | EV_DSR );
			//��ʾ�����յ��ַ�
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
				//�����ڴ�
				readBuf = new char[willReadLen];
				ZeroMemory(readBuf,willReadLen);
				//��ȡ��������
				ReadFile(m_hComm, readBuf, willReadLen,&actualReadLen,0);
				//�����ȡ�����ݴ��ڣ�
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

					////������ȡ�ص�����
					//if (ceSeries->m_OnSeriesRead)
					//{
					//	ceSeries->m_OnSeriesRead(ceSeries->m_pOwner,readBuf,actualReadLen);
					//}
				}
				//�ͷ��ڴ�
				delete[] readBuf;
				readBuf = NULL;
			}
		}
		//����յ����߳��˳��źţ����˳��߳�
		if (WaitForSingleObject(m_hReadCloseEvent,500) == WAIT_OBJECT_0)
		{
			qDebug()<<"go out of thread read func";
			break;
		}
	}
	return 0;
}

//�رն��߳�
void SerialPort::CloseReadThread()
{
	//���ö��߳��˳��ź�
	SetEvent(m_hReadCloseEvent);
	//���������¼���Ч��Ч
	SetCommMask(m_hComm, 0);
	//������н�Ҫ��������
	PurgeComm( m_hComm, PURGE_RXCLEAR );
	//�ȴ��룬������߳�û���˳�����ǿ���˳�

	qDebug()<<"close read thread";
	
	//if (WaitForSingleObject(m_hReadThread,4000) == WAIT_TIMEOUT)
	//{
	//	TerminateThread(m_hReadThread,0);
	//}
	//m_hReadThread = NULL;
}
/*
*�������ܣ��򿪴���
*��ڲ�����pPortOwner :ʹ�ô˴�����Ĵ�����
portNo :���ں�
baud :������
parity :��żУ��
databits :����λ
stopbits :ֹͣλ
*���ڲ�����(��)
*����ֵ��TRUE:�ɹ��򿪴���;FALSE:�򿪴���ʧ��
*/
//���ⲿ���ô˷����򿪴��ڣ��ú����������ƶ��Ĳ����򿪴��ڣ��������˴��ڵĶ��߳�
//��ʵ�ִ�������ʵʱ�첽��������
BOOL SerialPort::OpenPort(void * pOwner,
						UINT portNo , /*���ں�*/
						UINT baud , /*������*/
						UINT parity , /*��żУ��*/
						UINT databits , /*����λ*/
						UINT stopbits /*ֹͣλ*/	
						)
{
	DCB commParam;
	TCHAR szPort[15];
	ASSERT(pOwner!=NULL);
	m_pOwner = pOwner;
	// �Ѿ��򿪵Ļ���ֱ�ӷ���
	if (m_hComm != INVALID_HANDLE_VALUE)
	{
		return TRUE;
	}
	//���ô�����
	wsprintf(szPort, L"COM%d:", portNo);
	//�򿪴���
	m_hComm = CreateFile(szPort,
						 GENERIC_READ | GENERIC_WRITE, //�������д
						 0, //��ռ��ʽ������ģʽ��
						 NULL,
						 OPEN_EXISTING, //�򿪶����Ǵ�����������ʽ��
						 0,
						 NULL
						);
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		// ��Ч���,���ء�
		//TRACE(_T("CreateFile ������Ч���\n"));
		return FALSE;
	}
	// �õ��򿪴��ڵĵ�ǰ���Բ������޸ĺ����������ô��ڡ�
	if (!GetCommState(m_hComm,&commParam))
	{
		//�رմ���
		CloseHandle (m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
		return FALSE;
	}
	//���ô��ڲ���
	commParam.BaudRate = baud; // ���ò�����
	commParam.fBinary = TRUE; // ���ö�����ģʽ���˴���������
	//TRUE
	commParam.fParity = TRUE; // ֧����żУ��
	commParam.ByteSize = databits; // ����λ,��Χ:4-8
	commParam.Parity = parity; // У��ģʽ
	commParam.StopBits = stopbits; // ֹͣλ
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
	commParam.fAbortOnError = FALSE; // �����ڷ������󣬲�����ֹ����
	//��д
	//���ô��ڲ���
	if (!SetCommState(m_hComm, &commParam))
	{
		//TRACE(_T("SetCommState error"));
		//�رմ���
		CloseHandle (m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
		return FALSE;
	}
	//���ô��ڶ�дʱ��
	COMMTIMEOUTS CommTimeOuts;
	GetCommTimeouts (m_hComm, &CommTimeOuts);
	CommTimeOuts.ReadIntervalTimeout = MAXDWORD;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = 0;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 10;
	CommTimeOuts.WriteTotalTimeoutConstant = 1000;
	if(!SetCommTimeouts( m_hComm, &CommTimeOuts ))
	{
		//TRACE( _T("SetCommTimeouts ���ش���") );
		//�رմ���
		CloseHandle (m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
		return FALSE;
	}
	//ָ���˿ڼ����¼���
	SetCommMask (m_hComm, EV_RXCHAR);
	//���䴮���豸������
	SetupComm(m_hComm,512,512);
	//��ʼ���������е���Ϣ
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
	//�������ڶ����ݼ����߳�
	//m_hReadThread =
	//CreateThread(NULL,0,ReadThreadFunc,this,0,&m_dwReadThreadID);
	//TRACE(_T("���ڴ򿪳ɹ�"));
	m_bOpened = TRUE;
	return TRUE;
}
/*
*�������ܣ��رմ���
*��ڲ�����(��)
*���ڲ�����(��)
*����ֵ�� (��)
*/
//�ú������˳����ڶ��̣߳����رմ��ھ����
void SerialPort::ClosePort()
{
	//��ʾ���ڻ�û�д�
	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		return ;
	}
	//�رն��߳�
	//CloseReadThread();
	overlapThread->stop();
	//if (overlapThread->isRunning()) {
	//	overlapThread->stop();
	//	if (QThread::currentThread() != overlapThread)
	//		overlapThread->wait();}
	//�رմ���
	CloseHandle (m_hComm);
	//�ر��¼�
	CloseHandle(m_hReadCloseEvent);
	qDebug()<<"close handle event successfuly";
	m_hComm = INVALID_HANDLE_VALUE;
	m_bOpened = FALSE;
}
/*
*�������ܣ�������д������
*��ڲ�����buf ����д�����ݻ�����
bufLen : ��д�뻺��������
*���ڲ�����(��)
*����ֵ��TRUE:���óɹ�;FALSE:����ʧ��
*/
//���ⲿ�������򴮿ڷ������ݡ�
BOOL SerialPort::WriteSyncPort(const char *buf , DWORD bufLen)
{
	DWORD dwNumBytesWritten;
	DWORD dwHaveNumWritten =0 ; //�Ѿ�д�����
	int iInc = 0; //�����д�벻�ɹ�������FALSE
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);
	do
	{
		if (WriteFile (m_hComm, //���ھ��
					   buf+dwHaveNumWritten, //��д���ݻ�����
					   bufLen - dwHaveNumWritten, //��д���ݻ�������С
					   &dwNumBytesWritten, //����ִ�гɹ��󣬷���ʵ���򴮿�д�ĸ���
					   NULL)) //�˴���������NULL
		{
			dwHaveNumWritten = dwHaveNumWritten + dwNumBytesWritten;
			//д�����
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
*�������ܣ����ô��ڶ�ȡ��д�볬ʱ
*��ڲ�����CommTimeOuts : ָ��COMMTIMEOUTS�ṹ
*���ڲ�����(��)
*����ֵ��TRUE:���óɹ�;FALSE:����ʧ��
*/
//���ⲿ���������ô��ڶ�ȡ��д�볬ʱ��
BOOL SerialPort::SetSeriesTimeouts(COMMTIMEOUTS CommTimeOuts)
{
	ASSERT(m_hComm != INVALID_HANDLE_VALUE);
	return SetCommTimeouts(m_hComm,&CommTimeOuts);
}
//�õ������Ƿ��
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