#include <windows.h>
#pragma once
//���崮�ڽ������ݺ�������
//����һ���ص�������ִ�иú���ʱ����ʾ���ڽ��յ������ݡ�
typedef void (CALLBACK* ONSERIESREAD)(void * pOwner /*������ָ��*/
,char* buf /*���յ��Ļ�����*/
,DWORD dwBufLen /*���յ��Ļ���������*/);
class CCESeries
{
public:
	CCESeries(void); //CCESeries��Ĺ��캯��
	~CCESeries(void); //CCESeries�����������
public:
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
private:
	//���ڶ��̺߳������ú����������˽�о�̬��
	static DWORD WINAPI ReadThreadFunc(LPVOID lparam);
private:
	//�رն��̣߳���ʹ���괮�ں󣬱������������˳��������ݽ����̡߳�
	void CloseReadThread();
private:
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
};