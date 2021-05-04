#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <windows.h>
#include <QThread>
#include <QString>
//#include "MyThread.h"
typedef void (CALLBACK* ONSERIESREAD)(void * pOwner /*������ָ��*/
,char* buf /*���յ��Ļ�����*/
,DWORD dwBufLen /*���յ��Ļ���������*/);
//extern QString data_receive;
class SerialPort : public QObject
{
    Q_OBJECT
	friend class MyThread;
public:
	
    SerialPort(void);
    ~SerialPort(void);
	static SerialPort& getInstance(void);
	//�򿪴���
	BOOL OpenPort(void* pOwner,/*ָ��ָ��*/
	UINT portNo = 1, /*���ں�*/
	UINT baud = 9600, /*������*/
	UINT parity = NOPARITY, /*��żУ��*/
	UINT databits = 8, /*����λ*/
	UINT stopbits = 1 /*ֹͣλ*/
	);
	//�رմ���
	void ClosePort();
	//ͬ��д������
	BOOL WriteSyncPort(const char *buf , DWORD bufLen);
	//���ô��ڶ�ȡ��д�볬ʱ
	BOOL SetSeriesTimeouts(COMMTIMEOUTS CommTimeOuts);
	//�õ������Ƿ��
	BOOL GetComOpened();
	MyThread * overlapThread; 
public:
	//���ڶ��̺߳������ú����������˽�о�̬��
	DWORD WINAPI ReadThreadFunc();
private:
	//�رն��̣߳���ʹ���괮�ں󣬱������������˳��������ݽ����̡߳�
	void CloseReadThread();
	//�Ѵ򿪵Ĵ��ھ��
	// HANDLE m_hComm;
	//���߳̾��
	HANDLE m_hReadThread;
	//���߳�ID��ʶ
	DWORD m_dwReadThreadID;
	//���߳��˳��¼�
	HANDLE m_hReadCloseEvent;
	BOOL m_bOpened; //�����Ƿ��
	void * m_pOwner; //ָ��������ָ��
public:
	ONSERIESREAD m_OnSeriesRead; //���ڶ�ȡ�ص�����
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