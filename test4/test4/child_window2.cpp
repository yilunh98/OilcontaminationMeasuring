#include "child_window2.h"
#include "ui_child_window2.h"

child_window2::child_window2(QWidget *parent):
	QWidget(parent),
	ui(new Ui::Form2)
{
	ui->setupUi(this);

	ui->lbl_text->hide();
	ui->lbl_gif->hide();
    QMovie *movie = new QMovie(":/test4/Resources/loading.gif");
	ui->lbl_gif->setMovie(movie);
	movie->start();

	QPixmap pixmap = QPixmap(":/test4/Resources/bg5.png").scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);

	connect(ui->backtomainwindow2,SIGNAL(clicked()),this,SLOT(changeSlot2()));
}

child_window2::~child_window2()
{
	delete ui;
}


void child_window2::on_deviceon_clicked()
{
	if(!flag){
		ui->deviceon->setText("开启油泵");
		flag=1;
	}
	else{
		ui->deviceon->setText("关闭油泵");
		flag=0;

        //等串口发送完开启信息给个回复
		QToolTip::showText(mapToGlobal(ui->deviceon->pos()+QPoint(ui->deviceon->width()/2, ui->deviceon->height()/2)),"设备连接成功");
	}

}

void child_window2::on_paraset_clicked()
{
	pset.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); 
    bool para_set_ok = pset.exec();
	if(para_set_ok) 
	{ 
		//加载gif图片
		ui->lbl_gif->show();
		ui->lbl_text->show();

		//等待设置好之后把gif和文字隐藏掉,并显示设置成功
		//ui->lbl_text->hide();
		//ui->lbl_gif->hide();
		  
		QFont ft;
		ft.setPointSize(12);
		QFont ft2;
		ft2.setPointSize(14);
			
		ui->label_2->setFont(ft);
		ui->label_2->setStyleSheet("color:rgb(0,0,127)");
	
		ui->label_2->setText(pset.getinput());	

		ui->spinBox_1->setStyleSheet("QSpinBox:down-button:pressed{subcontrol-position:left;QSpinBox:up-button:pressed{subcontrol-position:right}");

	
		ui->plainTextEdit4->show();
		ui->plainTextEdit5->show();
		ui->plainTextEdit6->show();
		ui->plainTextEdit7->show();
		ui->plainTextEdit11->show();
		ui->plainTextEdit12->show();
		ui->plainTextEdit13->show();
		ui->plainTextEdit14->show();
		ui->spinBox_4->show();
		ui->spinBox_5->show();
		ui->spinBox_6->show();
		ui->spinBox_7->show();
		ui->label4->show();
		ui->label5->show();
		ui->label6->show();
		ui->label7->show();
		
		
		QString parain = ui->label_2->text();	    
		QString stanin = parain[11];
		if(stanin=="8"){
			ui->plainTextEdit6->hide();
			ui->plainTextEdit7->hide();
			ui->plainTextEdit13->hide();
			ui->plainTextEdit14->hide();
			ui->spinBox_6->hide();
			ui->spinBox_7->hide();
			ui->label6->hide();
			ui->label7->hide();
			//其他label的值也要相应改变
			//ui->label_4->setFont(ft2);
			//ui->label_4->setStyleSheet("color:rgb(253,253,253)");
			//ui->label_4->setText("4um");
		}
		else if(stanin=="6"){
			ui->plainTextEdit4->hide();
			ui->plainTextEdit5->hide();
			ui->plainTextEdit6->hide();
			ui->plainTextEdit7->hide();
			ui->plainTextEdit11->hide();
			ui->plainTextEdit12->hide();
			ui->plainTextEdit13->hide();
			ui->plainTextEdit14->hide();
			ui->spinBox_4->hide();
			ui->spinBox_5->hide();
			ui->spinBox_6->hide();
			ui->spinBox_7->hide();
			ui->label4->hide();
			ui->label5->hide();
			ui->label6->hide();
			ui->label7->hide();
			//其他label的值
			
		}
		else if(stanin=="A"){
			ui->plainTextEdit6->hide();
			ui->plainTextEdit7->hide();
			ui->plainTextEdit13->hide();
			ui->plainTextEdit14->hide();
			ui->spinBox_6->hide();
			ui->spinBox_7->hide();
			ui->label6->hide();
			ui->label7->hide();
		   //其他label的值

		}
		else if(stanin=="B"){
			ui->plainTextEdit7->hide();
			ui->plainTextEdit14->hide();
			ui->spinBox_7->hide();
			ui->label7->hide();
			
			//其他label的值

		}
		else if(stanin=="2"){
			

			//其他label的值
		}
		

		//QMessageBox::about(this,"提示","设置成功");

		QMessageBox mess(QMessageBox::NoIcon,tr("提示"),tr("设置成功!   "));
		mess.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); 
		QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
		mess.setStyleSheet("background-color: rgb(253, 253, 253)");
		mess.exec();
	}

}

void child_window2::on_starttest_clicked()
{
	if(flag2){
		ui->starttest->setText("停止检测");
		flag2 = 0;

		db2 = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
		db2.setDatabaseName("TEST");//建立连接，已存在即连接，不存在即建立连接
		if(!db2.open())//打开连接
		{
			QMessageBox::warning(this,"wrong",db2.lastError().text());
			return;
		}
		QSqlQuery query;
		
		QString parain = ui->label_2->text();	    
		QString stanin = parain[11];

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
					QMessageBox::warning(this,"wrong",query.lastError().text());

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
	else{ 
		//if(serial_sig){flag2 = 1; ui->starttest->setText("开始检测");}  //如果串口接收数据已经结束，则直接结束，显示开始检测
		//else{
			//否则就是中途点击停止检测 跳出提示框，yes就停止检测，no就重新继续检测
			QMessageBox mess(QMessageBox::NoIcon,tr("_new"),tr("检测未结束，确定停止吗 ？"));
			QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::YesRole));
			QPushButton *cancelbutton = (mess.addButton(tr("取消"),QMessageBox::NoRole));
			mess.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint); 
	        mess.setStyleSheet("background-color: rgb(253, 253, 253)");
			
			int reply; 
			reply = mess.exec();
			if (reply == 0) { 
				flag2 = 1;
				ui->starttest->setText("开始检测");
			}
			else if (reply == 1)  {
				flag2 = 0;
		    }
		//}
	}

}

void child_window2::on_print_clicked()
{

}

void child_window2::changeSlot2()
{
	emit mySignal2();

}