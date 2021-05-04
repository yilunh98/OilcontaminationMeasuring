#ifndef CHILD_WINDOW1_H
#define CHILD_WINDOW1_H

#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QDate>
#include <QDateEdit>
#include <QtSql>
#include <QtGui>
#include "para_set.h"
#include "ui_para_set.h"
#include "Globals.h"
namespace Ui{
	class Form;
}
class child_window1: public QWidget{
	Q_OBJECT

public:
	explicit child_window1(QWidget *parent = 0);
	~child_window1();
	para_set pset;
	//QFont ft1;

private:
	Ui::Form *ui;
	QSqlDatabase db;


private slots:
	void changeSlot();
	void setstandard();
	void setdate();
	void setdate_2();
	void on_excel_clicked();
	void on_setsql_clicked();
	void teststa1();
	void teststa2();
	//void teststa3();
	//void teststa4();
	//void teststa5();	

signals:
	void mySignal();

};


#endif //CHILD_WINDOW1_H