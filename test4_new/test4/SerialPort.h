#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <windows.h>
#include <QThread>
#include <QString>
//#include "MyThread.h"
typedef void (CALLBACK* ONSERIESREAD)(void * pOwner /*父对象指针*/
,char* buf /*接收到的缓冲区*/
,DWORD dwBufLen /*接收到的缓冲区长度*/);
//extern QString data_receive;
class SerialPort : public QObject
{
    Q_OBJECT
	friend class MyThread;
public:
	
    SerialPort(void);
    ~SerialPort(void);
	static SerialPort& getInstance(void);
	//打开串口
	BOOL OpenPort(void* pOwner,/*指向父指针*/
	UINT portNo = 1, /*串口号*/
	UINT baud = 9600, /*波特率*/
	UINT parity = NOPARITY, /*奇偶校验*/
	UINT databits = 8, /*数据位*/
	UINT stopbits = 1 /*停止位*/
	);
	//关闭串口
	void ClosePort();
	//同步写入数据
	BOOL WriteSyncPort(const char *buf , DWORD bufLen);
	//设置串口读取、写入超时
	BOOL SetSeriesTimeouts(COMMTIMEOUTS CommTimeOuts);
	//得到串口是否打开
	BOOL GetComOpened();
	MyThread * overlapThread; 
public:
	//串口读线程函数，该函数被定义成私有静态。
	DWORD WINAPI ReadThreadFunc();
private:
	//关闭读线程，当使用完串口后，便调用这个函数退出串口数据接收线程。
	void CloseReadThread();
	//已打开的串口句柄
	// HANDLE m_hComm;
	//读线程句柄
	HANDLE m_hReadThread;
	//读线程ID标识
	DWORD m_dwReadThreadID;
	//读线程退出事件
	HANDLE m_hReadCloseEvent;
	BOOL m_bOpened; //串口是否打开
	void * m_pOwner; //指定父对象指针
public:
	ONSERIESREAD m_OnSeriesRead; //串口读取回调函数
	HANDLE m_hComm;
signals:
	void writeText(const QString&); 
	//void writeText(); 
private:
};
class MyThread:public QThread
{
	SerialPort *qesp;
public:
	MyThread(SerialPort *qesp);
	~MyThread(void);
	bool terminate;
	void stop();
	
protected:
	//overriden
	virtual void run();
	
};
#endif // SERIALPORT_H