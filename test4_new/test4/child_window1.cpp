#include "child_window1.h"
#include "ui_child_window1.h"

child_window1::child_window1(QWidget *parent):
	QWidget(parent),
	ui(new Ui::Form)
{
	ui->setupUi(this);

	QPixmap pixmap = QPixmap(":/test4/Resources/bg5.png").scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);

	ui->calendarWidget->hide();
	connect(ui->date,SIGNAL(clicked()),ui->calendarWidget,SLOT(show()));
	ui->calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
	connect(ui->calendarWidget,SIGNAL(clicked(const QDate &)),this,SLOT(setdate()));

	ui->calendarWidget_2->hide();
	connect(ui->date_2,SIGNAL(clicked()),ui->calendarWidget_2,SLOT(show()));
	ui->calendarWidget_2->setSelectionMode(QCalendarWidget::SingleSelection);
	connect(ui->calendarWidget_2,SIGNAL(clicked(const QDate &)),this,SLOT(setdate_2()));
	
	setstandard();
	connect(ui->backtomainwindow,SIGNAL(clicked()),this,SLOT(changeSlot()));

}

child_window1::~child_window1()
{
	delete ui;
}


void child_window1::changeSlot()
{
	emit mySignal();
	QFont ft0("Arial",16,75);
	ui->date->setFont(ft0);
	ui->date_2->setFont(ft0);
	ui->date->setText("开始日期");
	ui->date_2->setText("结束日期");
	ui->standard->setFont(ft0);
	ui->standard->setText("选择标准");

	QStandardItemModel *model = new QStandardItemModel;
	ui->tableView->horizontalHeader()->setVisible(false);
	ui->tableView->verticalHeader()->setVisible(false);
	ui->tableView->setModel(model);
	//ui->tableView->clearSpans();


}

void child_window1::setstandard()
{
    QList<QAction*> lists;
    QAction *sta1 = new QAction("NAS1638", this);
	QAction *sta2 = new QAction("ISO4406", this);
	//QAction *sta3 = new QAction("GJB420A", this);
	//QAction *sta4 = new QAction("GJB420B", this);
	//QAction *sta5 = new QAction("ГOCT17216", this);

    QMenu *mfile = new QMenu;
	
    mfile->addAction(sta1);
    mfile->addAction(sta2);
	//mfile->addAction(sta3);
	//mfile->addAction(sta4);
	//mfile->addAction(sta5);
	mfile->setStyleSheet(
		"QMenu::item{\
		padding:8px 32px;\
		font-size:16px;\
		background-color:white;}"
		);
    ui->standard->setMenu(mfile);

	connect(sta1, SIGNAL(triggered()), this, SLOT(teststa1())); 
	connect(sta2, SIGNAL(triggered()), this, SLOT(teststa2())); 
	//connect(sta3, SIGNAL(triggered()), this, SLOT(teststa3())); 
	//connect(sta4, SIGNAL(triggered()), this, SLOT(teststa4())); 
	//connect(sta5, SIGNAL(triggered()), this, SLOT(teststa5())); 
	
}
void child_window1::teststa1(){QFont ft1("Arial",13,75);ui->standard->setFont(ft1);ui->standard->setText("NAS1638");}
void child_window1::teststa2(){QFont ft1("Arial",13,75);ui->standard->setFont(ft1);ui->standard->setText("ISO4406");}
//void child_window1::teststa3(){QFont ft1("Arial",13,75);ui->standard->setFont(ft1);ui->standard->setText("GJB420A");}
//void child_window1::teststa4(){QFont ft1("Arial",13,75);ui->standard->setFont(ft1);ui->standard->setText("GJB420B");}
//void child_window1::teststa5(){QFont ft1("Arial",13,75);ui->standard->setFont(ft1);ui->standard->setText("ГOCT17216");}

void child_window1::setdate()
{	
	QFont ft1("Arial",13,75);
	ui->date->setFont(ft1);
	ui->date->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
	ui->calendarWidget->hide();


}

void child_window1::setdate_2()
{	
	QFont ft2("Arial",13,75);
	ui->date_2->setFont(ft2);
	ui->date_2->setText(ui->calendarWidget_2->selectedDate().toString("yyyy-MM-dd"));
	ui->calendarWidget_2->hide();

}

void child_window1::on_excel_clicked()
{
    QString filepath = "/硬盘/data-";
	filepath.append(ui->standard->text());
	filepath.append(".xls");
	/*QString filepath = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                                  QString(), tr("EXCEL files (*.xls);;HTML-Files (*.txt);;"));*/
    if (filepath != "")
    {
        int row = ui->tableView->model()->rowCount();
        int col = ui->tableView->model()->columnCount();
        QList<QString> list;
		        QString HeaderRow;
        for (int i = 0; i < col; i++)
        {
            HeaderRow.append(ui->tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\t");
        }
        list.push_back(HeaderRow);
        for (int i = 0; i < row; i++)
        {
            QString rowStr = "";
            for (int j = 0; j < col; j++){
                QModelIndex index = ui->tableView->model()->index(i, j);
                rowStr += ui->tableView->model()->data(index).toString() + "\t";
            }
            list.push_back(rowStr);
        }
		qDebug()<<"list"<<list;
		        QTextEdit textEdit;
        for (int i = 0; i < list.size(); i++)
        {
            textEdit.append(list.at(i));
        }
		
        QFile file(filepath);
		QPoint n = ui->excel->pos();
        if (file.open(QFile::WriteOnly | QIODevice::Text))
        {
            QTextStream ts(&file);
            ts.setCodec("GB2312");
            ts << textEdit.document()->toPlainText();
			qDebug()<<textEdit.document()->toPlainText();
            file.close();
            QToolTip::showText(n,"生成成功");
        }else{
           QToolTip::showText(n,"数据导出失败");
        }
    }
}



void child_window1::on_setsql_clicked()
{
	db = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
    db.setDatabaseName("/ResidentFlash/test4/TEST");//建立连接，已存在即连接，不存在即建立连接
    if(!db.open())//打开连接
    {
        QMessageBox::warning(this,"wrong",db.lastError().text());
        return;
    }
	QSqlQuery query;
    QSqlTableModel * model = new QSqlTableModel(this,db);
	ui->tableView->clearSpans();
	ui->tableView->horizontalHeader()->setVisible(true);
	ui->tableView->verticalHeader()->setVisible(true);
	ui->tableView->setModel(model);
	ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Interactive);
	//ui->tableView->verticalHeader()->setDefaultSectionSize(35);


	QString str = "μm";
	QByteArray temp1 = str.toLocal8Bit().toHex();
	qDebug()<<"temp1"<<temp1;
	QByteArray temp2 = biaozhun.toLocal8Bit().toHex();
	qDebug()<<"temp2"<<temp2;
	qDebug()<<"biaozhun"<<biaozhun;

	QString stanin= ui->standard->text();
	if(stanin=="NAS1638"){

		model->setTable("new8");
		model->setHeaderData(0,Qt::Horizontal,tr("编号"));
		model->setHeaderData(1,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(2,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(3,Qt::Horizontal,tr("清洁度等级"));
		if (biaozhun.toLocal8Bit().toHex()==temp1){
			model->setHeaderData(4,Qt::Horizontal,tr("5~15 μm"));
			model->setHeaderData(5,Qt::Horizontal,tr("15~25 μm"));
			model->setHeaderData(6,Qt::Horizontal,tr("25~50 μm"));
			model->setHeaderData(7,Qt::Horizontal,tr("50~100 μm"));
			model->setHeaderData(8,Qt::Horizontal,tr(">100 μm"));
		}
		else{
			model->setHeaderData(4,Qt::Horizontal,tr("6~14μm(c)"));
			model->setHeaderData(5,Qt::Horizontal,tr("14~21μm(c)"));
			model->setHeaderData(6,Qt::Horizontal,tr("21~38μm(c)"));
			model->setHeaderData(7,Qt::Horizontal,tr("38~70μm(c)"));
			model->setHeaderData(8,Qt::Horizontal,tr(">70μm(c)"));
		}	
		//ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);	
	
	}
	else if(stanin=="ISO4406"){
		model->setTable("new6");
		model->setHeaderData(0,Qt::Horizontal,tr("编号"));
		model->setHeaderData(1,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(2,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(3,Qt::Horizontal,tr("清洁度等级"));
		if (biaozhun.toLocal8Bit().toHex()==temp1){
			model->setHeaderData(4,Qt::Horizontal,tr(">1 μm"));
			model->setHeaderData(5,Qt::Horizontal,tr(">5 μm"));
			model->setHeaderData(6,Qt::Horizontal,tr(">15 μm"));
		}
		else{
			model->setHeaderData(4,Qt::Horizontal,tr(">4 μm(c)"));
			model->setHeaderData(5,Qt::Horizontal,tr(">6 μm(c)"));
			model->setHeaderData(6,Qt::Horizontal,tr(">14 μm(c)"));
		}
		ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);		
	}
	/*else if(stanin=="GJB420A"){
		model->setTable("newA");
		model->setHeaderData(0,Qt::Horizontal,tr("编号"));
		model->setHeaderData(1,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(2,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(3,Qt::Horizontal,tr("清洁度等级"));
		if (biaozhun.toLocal8Bit().toHex()==temp1){
			model->setHeaderData(4,Qt::Horizontal,tr(">2 μm"));
			model->setHeaderData(5,Qt::Horizontal,tr(">5 μm"));
			model->setHeaderData(6,Qt::Horizontal,tr(">15 μm"));
			model->setHeaderData(7,Qt::Horizontal,tr(">25 μm"));
			model->setHeaderData(8,Qt::Horizontal,tr(">50 μm"));
		}
		else{
			model->setHeaderData(4,Qt::Horizontal,tr(">4.6 μm(c)"));
			model->setHeaderData(5,Qt::Horizontal,tr(">6 μm(c)"));
			model->setHeaderData(6,Qt::Horizontal,tr(">14 μm(c)"));
			model->setHeaderData(7,Qt::Horizontal,tr(">21 μm(c)"));
			model->setHeaderData(8,Qt::Horizontal,tr(">38 μm(c)"));
		}
	}
	else if(stanin=="GJB420B"){
		model->setTable("newB");
		model->setHeaderData(0,Qt::Horizontal,tr("编号"));
		model->setHeaderData(1,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(2,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(3,Qt::Horizontal,tr("清洁度等级"));
		if (biaozhun.toLocal8Bit().toHex()==temp1){
			model->setHeaderData(4,Qt::Horizontal,tr(">1μm"));
			model->setHeaderData(5,Qt::Horizontal,tr(">5μm"));
			model->setHeaderData(6,Qt::Horizontal,tr(">15μm"));
			model->setHeaderData(7,Qt::Horizontal,tr(">25μm"));
			model->setHeaderData(8,Qt::Horizontal,tr(">50μm"));
			model->setHeaderData(9,Qt::Horizontal,tr(">100μm")) ;
		}
		else{
			model->setHeaderData(4,Qt::Horizontal,tr(">4μm(c)"));
			model->setHeaderData(5,Qt::Horizontal,tr(">6μm(c)"));
			model->setHeaderData(6,Qt::Horizontal,tr(">14μm(c)"));
			model->setHeaderData(7,Qt::Horizontal,tr(">21μm(c)"));
			model->setHeaderData(8,Qt::Horizontal,tr(">38μm(c)"));
			model->setHeaderData(9,Qt::Horizontal,tr(">70μm(c)"));
		}
	}
		else if(stanin=="ГOCT17216"){
		model->setTable("new2");
		model->setHeaderData(0,Qt::Horizontal,tr("编号"));
		model->setHeaderData(1,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(2,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(3,Qt::Horizontal,tr("清洁度等级"));
		if (biaozhun.toLocal8Bit().toHex()==temp1){
			model->setHeaderData(4,Qt::Horizontal,tr(">1μm"));
			model->setHeaderData(5,Qt::Horizontal,tr(">2μm"));
			model->setHeaderData(6,Qt::Horizontal,tr(">5μm"));
			model->setHeaderData(7,Qt::Horizontal,tr(">10μm"));
			model->setHeaderData(8,Qt::Horizontal,tr(">25μm"));
			model->setHeaderData(9,Qt::Horizontal,tr(">50μm"));
			model->setHeaderData(10,Qt::Horizontal,tr(">100μm"));
		}
		else{
			model->setHeaderData(4,Qt::Horizontal,tr(">4μm(c)"));
			model->setHeaderData(5,Qt::Horizontal,tr(">4.6μm(c)"));
			model->setHeaderData(6,Qt::Horizontal,tr(">6μm(c)"));
			model->setHeaderData(7,Qt::Horizontal,tr(">10μm(c)"));
			model->setHeaderData(8,Qt::Horizontal,tr(">21μm(c)"));
			model->setHeaderData(9,Qt::Horizontal,tr(">38μm(c)"));
			model->setHeaderData(10,Qt::Horizontal,tr(">70μm(c)"));
		}	
	}*/
	else{
		QMessageBox mess2(QMessageBox::NoIcon,tr("提示"),tr("请选择标准  "));
		mess2.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
		QPushButton *okbutton2 = (mess2.addButton(tr("确定"),QMessageBox::AcceptRole));
		mess2.setStyleSheet("font:14px");
		mess2.exec();
	}
	if ((ui->date->text()=="开始日期")||(ui->date_2->text()=="结束日期")){
		QMessageBox mess2(QMessageBox::NoIcon,tr("提示"),tr("请选择日期  "));
		mess2.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
		QPushButton *okbutton2 = (mess2.addButton(tr("确定"),QMessageBox::AcceptRole));
		mess2.setStyleSheet("font:14px");
		mess2.exec();
	}
	else{
		//model->select();
		QString date1,date2;
		date1 = ui->date->text();
		date2 = ui->date_2->text();
		qDebug()<<"origin_date2"<<date2;
		QDateTime qdate2 = QDateTime::fromString(date2,"yyyy-MM-dd");
		qdate2 = qdate2.addDays(1);
		date2 = qdate2.toString("yyyy-MM-dd");
		qDebug()<<"later date2"<<date2;
		model->setFilter(QObject::tr("date_time>= '%1' and date_time<='%2'").arg(date1).arg(date2)); //根据日期进行筛选
		model->select();
	}

	
}