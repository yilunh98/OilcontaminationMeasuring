#include "test4.h"
#include "ui_test4.h"

test4::test4(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::test4Class)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
	//this->setWindowFlags(Qt::Window); 

	QPixmap pixmap = QPixmap(":/test4/Resources/bg5.png").scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);
	
	connect(ui->search,SIGNAL(clicked()),this,SLOT(on_search_clicked()));
	connect(&cw1,SIGNAL(mySignal()),this,SLOT(on_back_clicked()));
	connect(&cw2,SIGNAL(mySignal2()),this,SLOT(on_back2_clicked()));

	//database_init();	//创建数据库
	delete_database();	//删除30天之前的结果
}

test4::~test4()
{
	delete ui;
}



void test4::on_search_clicked()
{
	//this->hide();
	cw1.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
	//cw1.setWindowFlags(Qt::Window);
	cw1.showFullScreen();
	//cw1.show();
}

void test4::on_back_clicked()
{
	this->showFullScreen();
	//this->show();
	
}

void test4::on_start_clicked()
{
	//this->hide();
	cw2.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
	//cw2.setWindowFlags(Qt::Window);
	cw2.showFullScreen();
	//cw2.show();
	qDebug()<<"start clicked";
}

void test4::on_back2_clicked()
{
	cw1.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
	//cw1.setWindowFlags(Qt::Window);
	cw1.showFullScreen();
	//cw1.show();

}
void test4::database_init(){
	QString name;
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
		db.setDatabaseName("TEST");//建立连接，已存在即连接，不存在即建立连接
		if(!db.open())//打开连接
		{
			QMessageBox::warning(this,"wrong",db.lastError().text());
			return;
		}
		QSqlQuery query;
		if(!query.exec("create table new8("  
			   "number integer,"
			   "date_time varchar,"
			   "target_level varchar,"
			   "contamination_level varchar,"
			   "range1 integer,"
			   "range2 integer,"
			   "range3 integer,"
			   "range4 integer,"
			   "range5 integer "
			   ")"))
			QMessageBox::warning(this,"wrong",query.lastError().text());
		if(!query.exec("create table new6("    
						   "number integer,"
						   "date_time varchar,"
						   "target_level varchar,"
						   "contamination_level varchar,"
						   "range1 integer,"
						   "range2 integer,"
						   "range3 integer "
						   ")"))
			QMessageBox::warning(this,"wrong",query.lastError().text());
	}
}
void test4::delete_database(){
	QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
	db2.setDatabaseName("/ResidentFlash/test4/TEST");//建立连接，已存在即连接，不存在即建立连接
	if(!db2.open())//打开连接
	{
		QMessageBox::warning(this,"wrong",db2.lastError().text());
		return;
	}
	QSqlQuery query;
	QDate qdate = QDate::currentDate();
	QDate qdate2 = qdate.addDays(-90);
	QString str8 = QString("delete from new8 where date_time< '%1'").arg(qdate2.toString("yyyy-MM-dd"));	
	QString str6 = QString("delete from new6 where date_time< '%1'").arg(qdate2.toString("yyyy-MM-dd"));	
	if(!query.exec(str8))
		QMessageBox::warning(this,"wrong",query.lastError().text());
	if(!query.exec(str6))
		QMessageBox::warning(this,"wrong",query.lastError().text());
}