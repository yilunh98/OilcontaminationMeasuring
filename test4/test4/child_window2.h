#ifndef CHILD_WINDOW2_H
#define CHILD_WINDOW2_H

#include <QWidget>
#include <QtSql>
#include <QtGui>
#include <QMovie>
#include "para_set.h"

namespace Ui{
	class Form2;
}
class child_window2: public QWidget{
	Q_OBJECT

public:
	explicit child_window2(QWidget *parent = 0);
	~child_window2();

private slots:
	void on_deviceon_clicked();
	void on_paraset_clicked();
	void on_starttest_clicked();
	void on_print_clicked();
	void changeSlot2();

signals:
	void mySignal2();

private:
	Ui::Form2 *ui;
	para_set pset;
	int flag;
	int flag2;
	QSqlDatabase db2;


};


#endif //CHILD_WINDOW1_H