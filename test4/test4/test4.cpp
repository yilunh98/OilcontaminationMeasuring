#include "test4.h"
#include "ui_test4.h"

test4::test4(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::test4Class)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
	this->setWindowState(Qt::WindowMaximized);

	QPixmap pixmap = QPixmap(":/test4/Resources/bg5.png").scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);
	
	connect(ui->search,SIGNAL(clicked()),this,SLOT(on_search_clicked()));
	connect(&cw1,SIGNAL(mySignal()),this,SLOT(on_back_clicked()));
	connect(&cw2,SIGNAL(mySignal2()),this,SLOT(on_back2_clicked()));
	

}

test4::~test4()
{
	delete ui;
}



void test4::on_search_clicked()
{
	//this->hide();
	cw1.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
	//cw1.setWindowState(Qt::WindowMaximized);
	cw1.showFullScreen();
}

void test4::on_back_clicked()
{
	this->show();
	cw1.close();
}

void test4::on_start_clicked()
{
	//this->hide();
	cw2.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
	//cw2.setWindowState(Qt::WindowMaximized);
	cw2.showFullScreen();
}

void test4::on_back2_clicked()
{
	this->show();
	cw2.close();

}