#ifndef TEST4_H
#define TEST4_H

#include <QtGui/QMainWindow>
#include "child_window1.h"
#include "child_window2.h"

namespace Ui{
	class test4Class;
}

class test4 : public QMainWindow
{
	Q_OBJECT

public:
	explicit test4(QWidget *parent = 0);
	~test4();
	void database_init();
	void delete_database();

private slots:
	void on_search_clicked();
	void on_start_clicked();
	void on_back_clicked();
	void on_back2_clicked();

private: 
	Ui::test4Class *ui;
	child_window1 cw1;
	child_window2 cw2;
};

#endif // TEST4_H
