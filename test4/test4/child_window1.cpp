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

	//setsql();
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
	ui->standard->setText("选择标准");

	QStandardItemModel *model = new QStandardItemModel;
	ui->tableView->setModel(model);

}

void child_window1::setstandard()
{
    QList<QAction*> lists;
    QAction *sta1 = new QAction("NAS1638", this);
	QAction *sta2 = new QAction("ISO4406", this);
	QAction *sta3 = new QAction("GJB420A-96", this);
	QAction *sta4 = new QAction("GJB420B-2006", this);
	QAction *sta5 = new QAction("ALL", this);
	QAction *sta6 = new QAction("ГOCT17216", this);

    QMenu *mfile = new QMenu;
    mfile->addAction(sta1);
    mfile->addAction(sta2);
	mfile->addAction(sta3);
	mfile->addAction(sta4);
	mfile->addAction(sta5);
	mfile->addAction(sta6);
	mfile->setStyleSheet("background-color:white;");
    ui->standard->setMenu(mfile);

	connect(sta1, SIGNAL(triggered()), this, SLOT(teststa1())); 
	connect(sta2, SIGNAL(triggered()), this, SLOT(teststa2())); 
	connect(sta3, SIGNAL(triggered()), this, SLOT(teststa3())); 
	connect(sta4, SIGNAL(triggered()), this, SLOT(teststa4())); 
	connect(sta5, SIGNAL(triggered()), this, SLOT(teststa5())); 
	connect(sta6, SIGNAL(triggered()), this, SLOT(teststa6())); 
	
}
void child_window1::teststa1(){ui->standard->setText("NAS1638");}
void child_window1::teststa2(){ui->standard->setText("ISO4406");}
void child_window1::teststa3(){ui->standard->setText("GJB420A-96");}
void child_window1::teststa4(){ui->standard->setText("GJB420B-2006");}
void child_window1::teststa5(){ui->standard->setText("ALL");}
void child_window1::teststa6(){ui->standard->setText("ГOCT17216");}

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
    QString filepath = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                                  QString(), tr("EXCEL files (*.xls);;HTML-Files (*.txt);;"));
 
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
            file.close();
			QToolTip::showText(mapToGlobal(n+QPoint(ui->excel->width()/5, ui->excel->height()/2)),"导出成功");
        }else{
           QToolTip::showText(mapToGlobal(n+QPoint(ui->excel->width()/5, ui->excel->height()/2)),"数据导出失败");
        }
    }
}



void child_window1::on_setsql_clicked()
{
	db = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
    db.setDatabaseName("TEST");//建立连接，已存在即连接，不存在即建立连接
    if(!db.open())//打开连接
    {
        QMessageBox::warning(this,"wrong",db.lastError().text());
        return;
    }
	QSqlQuery query;
    QSqlTableModel * model = new QSqlTableModel(this,db);
	
	QString stanin= ui->standard->text();
	
	if(stanin=="NAS1638"){
		model->setTable("new8");
		model->setHeaderData(0,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(1,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(2,Qt::Horizontal,tr("清洁度等级"));
		model->setHeaderData(3,Qt::Horizontal,tr("5~15um"));
		model->setHeaderData(4,Qt::Horizontal,tr("15~25um"));
		model->setHeaderData(5,Qt::Horizontal,tr("25~50um"));
		model->setHeaderData(6,Qt::Horizontal,tr("50~100um"));
		model->setHeaderData(7,Qt::Horizontal,tr("＞100um"));

		ui->tableView->setModel(model);
		ui->tableView->setColumnHidden(0,true);
		ui->tableView->verticalHeader()->setDefaultSectionSize(35);
		ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
		
	}
	else if(stanin=="ISO4406"){
		model->setTable("new6");
		model->setHeaderData(0,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(1,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(2,Qt::Horizontal,tr("清洁度等级"));
		model->setHeaderData(3,Qt::Horizontal,tr("＞4um(c)"));
		model->setHeaderData(4,Qt::Horizontal,tr("＞6um(c)"));
		model->setHeaderData(5,Qt::Horizontal,tr("＞14um(c)"));

		ui->tableView->setModel(model);
		ui->tableView->verticalHeader()->setDefaultSectionSize(35);
		ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	}
	else if(stanin=="GJB420A-96"){
		
		model->setTable("newA");
		model->setHeaderData(0,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(1,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(2,Qt::Horizontal,tr("清洁度等级"));
		model->setHeaderData(3,Qt::Horizontal,tr("＞2um"));
		model->setHeaderData(4,Qt::Horizontal,tr("＞5um"));
		model->setHeaderData(5,Qt::Horizontal,tr("＞15um"));
		model->setHeaderData(6,Qt::Horizontal,tr("＞25um"));
		model->setHeaderData(7,Qt::Horizontal,tr("＞50um"));

		ui->tableView->setModel(model);
		ui->tableView->verticalHeader()->setDefaultSectionSize(35);
		ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	}
	else if(stanin=="GJB420B-2006"){
		model->setTable("newB");
		model->setHeaderData(0,Qt::Horizontal,tr("日期时间"));
		model->setHeaderData(1,Qt::Horizontal,tr("目标等级"));
		model->setHeaderData(2,Qt::Horizontal,tr("清洁度等级"));
		model->setHeaderData(3,Qt::Horizontal,tr(">1um/4um(c)"));
		model->setHeaderData(4,Qt::Horizontal,tr(">5um/6um(c)"));
		model->setHeaderData(5,Qt::Horizontal,tr(">15um/14um(c)"));
		model->setHeaderData(6,Qt::Horizontal,tr(">25um/21um(c)"));
		model->setHeaderData(7,Qt::Horizontal,tr(">50um/38um(c)"));
		model->setHeaderData(8,Qt::Horizontal,tr(">100um/70um(c)")) ;

		ui->tableView->setModel(model);
		ui->tableView->verticalHeader()->setDefaultSectionSize(35);
		ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	}

	QString date1,date2;
	date1 = ui->date->text();
	date2 = ui->date_2->text();
	model->setFilter(QObject::tr("date_time>= '%1' and date_time<='%2'").arg(date1).arg(date2)); //根据日期进行筛选
    model->select();
	
	
}