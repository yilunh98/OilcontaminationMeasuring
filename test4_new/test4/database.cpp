#include <database.h>
#include <string>
#include <QWidget>
void Database::database_process(QString stanin){
	db2 = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
	db2.setDatabaseName("TEST");//建立连接，已存在即连接，不存在即建立连接
	if(!db2.open())//打开连接
	{
		QMessageBox::warning(this,"wrong",db2.lastError().text());
		return;
	}
	QSqlQuery query;


	if(stanin=="8"){
			if(!query.exec("create table new8("            
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

			QString str = QString("insert into new8 (date_time,target_level,contamination_level,range1,range2,range3,range4,range5) values ('%1','11/10/11/9/0','10/6/4/00/00',1440,19,1,0,0)").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
			if(!query.exec(str))
				
				::warning(this,"wrong",query.lastError().text());

			QSqlTableModel * model = new QSqlTableModel(this,db2);
			model->setTable("new8");
	}
	else if(stanin=="6"){
		if(!query.exec("create table new6("           
					   "date_time varchar,"
					   "target_level varchar,"
					   "contamination_level varchar,"
					   "range1 integer,"
					   "range2 integer,"
					   "range3 integer "
					   ")"))
			QMessageBox::warning(this,"wrong",query.lastError().text());

			QString str = QString("insert into new6 (date_time,target_level,contamination_level,range1,range2,range3) values ('%1','11/10/11/9/0','10/6/4/00/00',1440,19,1)").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
			if(!query.exec(str))
				QMessageBox::warning(this,"wrong",query.lastError().text());

			QSqlTableModel * model = new QSqlTableModel(this,db2);
			model->setTable("new6");
	}
	else if(stanin=="A"){	
		if(!query.exec("create table newA("              
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

			QString str = QString("insert into newA (date_time,target_level,contamination_level,range1,range2,range3,range4,range5) values ('%1','11/10/11/9/0','10/6/4/00/00',1440,19,1,0,0)").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
			if(!query.exec(str))
				QMessageBox::warning(this,"wrong",query.lastError().text());

			QSqlTableModel * model = new QSqlTableModel(this,db2);
			model->setTable("newA");
	}
	else if(stanin=="B"){
			//query.exec("drop table newB");   
			if(!query.exec("create table newB("           
					   "date_time varchar,"
					   "target_level varchar,"
					   "contamination_level varchar,"
					   "range1 integer,"
					   "range2 integer,"
					   "range3 integer,"
					   "range4 integer,"
					   "range5 integer,"
					   "range6 integer "
					   ")"))
			QMessageBox::warning(this,"wrong",query.lastError().text());

			QString str = QString("insert into newB (date_time,target_level,contamination_level,range1,range2,range3,range4,range5,range6) values ('%1','11/10/11/9/0','10/6/4/00/00',1440,19,1,0,0,0)").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
			if(!query.exec(str))
				QMessageBox::warning(this,"wrong",query.lastError().text());

			QSqlTableModel * model = new QSqlTableModel(this,db2);
			model->setTable("newB");
	}
	else if(stanin=="2"){	
		if(!query.exec("create table new2("              
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

			QString str = QString("insert into new2 (date_time,target_level,contamination_level,range1,range2,range3,range4,range5) values ('%1','11/10/11/9/0','10/6/4/00/00',1440,19,1,0,0)").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
			if(!query.exec(str))
				QMessageBox::warning(this,"wrong",query.lastError().text());

			QSqlTableModel * model = new QSqlTableModel(this,db2);
			model->setTable("new2");
	}
	else{	
		if(!query.exec("create table newALL("              
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

			QString str = QString("insert into newALL (date_time,target_level,contamination_level,range1,range2,range3,range4,range5) values ('%1','11/10/11/9/0','10/6/4/00/00',1440,19,1,0,0)").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
			if(!query.exec(str))
				QMessageBox::warning(this,"wrong",query.lastError().text());

			QSqlTableModel * model = new QSqlTableModel(this,db2);
			model->setTable("newALL");
	}
}