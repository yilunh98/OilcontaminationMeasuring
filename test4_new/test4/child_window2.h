#ifndef CHILD_WINDOW2_H
#define CHILD_WINDOW2_H
#include <QtGui/QMainWindow>
#include <QtGui>
#include <QWidget>
#include "para_set.h"
#include "ui_para_set.h"
#include <string>
#include <iostream>
#include<Qtimer>
#include <QtSql>
#include "Globals.h"
#include "SerialPort.h"
namespace Ui{
	class Form2;
}
class child_window2: public QWidget{
	Q_OBJECT

public:
	explicit child_window2(QWidget *parent = 0);
	~child_window2();
	SerialPort *myComyb;	//�ͱõĴ��ڶ���
	SerialPort *myComjc;	//����ǵĴ��ڶ���
	SerialPort *myComdy;	//��ӡ���Ĵ��ڶ���
	para_set pset;
	QSqlDatabase db; //���ݿ�Ķ���
	static QString receive; //���մ洢ȫ�ֱ���
	QElapsedTimer timer;
	//char* str2multibyte(std::string str);
	char* QString2byte(QString str);
	void set_parameter();
	BOOL data_process(QString);	//���ݴ�����
	void database_process(QString sta);
	QByteArray tongdaoresult(QString stanin);
	void ui_init();
	void clear_result();
	void print_message();
	//JIANCE *receive1;
	//JIANCE *receive2;
	//JIANCE *receive3;


private slots:
	void on_deviceon_clicked();
	void on_paraset_clicked();
	void on_starttest_clicked();
	void on_print_clicked();
	void changeSlot2();
	void readMyComjc(const QString&);//�������ݷ�������
	void change_liusu();//�ͱ����ٸı�
	void showdatetime();


signals:
	void mySignal2();

private:
	Ui::Form2 *ui;
	QTimer *time1;
	int flag_yb;	//�ͱñ�־
	int flag_jc;	//����Ǳ�־
	int flag_sj;	//���ݷ�����־
	//QSqlDatabase db2;

};


#endif //CHILD_WINDOW1_H