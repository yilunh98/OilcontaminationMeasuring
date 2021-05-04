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
	SerialPort *myComyb;	//油泵的串口对象
	SerialPort *myComjc;	//检测仪的串口对象
	SerialPort *myComdy;	//打印机的串口对象
	para_set pset;
	QSqlDatabase db; //数据库的对象
	static QString receive; //接收存储全局变量
	QElapsedTimer timer;
	//char* str2multibyte(std::string str);
	char* QString2byte(QString str);
	void set_parameter();
	BOOL data_process(QString);	//数据处理函数
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
	void readMyComjc(const QString&);//接收数据分析函数
	void change_liusu();//油泵流速改变
	void showdatetime();


signals:
	void mySignal2();

private:
	Ui::Form2 *ui;
	QTimer *time1;
	int flag_yb;	//油泵标志
	int flag_jc;	//检测仪标志
	int flag_sj;	//数据分析标志
	//QSqlDatabase db2;

};


#endif //CHILD_WINDOW1_H