#include <windows.h>
#pragma once
//定义串口接收数据函数类型
//这是一个回调函数，执行该函数时，表示串口接收到了数据。
typedef void (CALLBACK* ONSERIESREAD)(void * pOwner /*父对象指针*/
,char* buf /*接收到的缓冲区*/
,DWORD dwBufLen /*接收到的缓冲区长度*/);
class CCESeries
{
public:
	CCESeries(void); //CCESeries类的构造函数
	~CCESeries(void); //CCESeries类的析构函数
public:
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
private:
	//串口读线程函数，该函数被定义成私有静态。
	static DWORD WINAPI ReadThreadFunc(LPVOID lparam);
private:
	//关闭读线程，当使用完串口后，便调用这个函数退出串口数据接收线程。
	void CloseReadThread();
private:
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
};