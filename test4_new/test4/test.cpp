#include "test.h"
#include <QDateTime>
#include <QDebug>
#include <QDir>
test::test(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	db = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
	
    db.setDatabaseName("TEST");//建立连接，已存在即连接，不存在即建立连接
	QSqlQuery query;
    if(!query.exec("create table new("              //NAS1638以及GJB420A-96
                   "date_time varchar,"
                   "target_level varchar,"
                   "contamination_level varchar,"
				   "range1 integer,"
				   "range2 integer,"
				   "range3 integer,"
				   "range4 integer,"
                   "range5 integer "
                   ")"))

	/*if(!query.exec("create table new("              //GJB420B-2006
                   "date_time varchar,"
                   "target_level varchar,"
                   "contamination_level varchar,"
				   "range1 integer,"
				   "range2 integer,"
				   "range3 integer,"
				   "range4 integer,"
                   "range5 integer "
				   "range6 interger"
                   ")"))*/

        QMessageBox::warning(this,"wrong",query.lastError().text());

	QString str = QString("insert into new (date_time,target_level,contamination_level,range1,range2,range3,range4,range5) values ('%1','11/10/11/9/0','10/6/4/00/00',1440,19,1,0,0)").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	if(!query.exec(str))
        QMessageBox::warning(this,"wrong",query.lastError().text());

	QSqlTableModel * model = new QSqlTableModel(this,db);
    model->setTable("new");
	model->setHeaderData(0,Qt::Horizontal,tr("日期时间"));
	model->setHeaderData(1,Qt::Horizontal,tr("目标等级"));
	model->setHeaderData(2,Qt::Horizontal,tr("清洁度等级"));
	model->setHeaderData(3,Qt::Horizontal,tr("5~15um"));                  //420A-96：＞2um      420B-2006：＞1um(4um(c))
	model->setHeaderData(4,Qt::Horizontal,tr("15~25um"));                 //420A-96：＞5um      420B-2006：＞5um(6um(c))
	model->setHeaderData(5,Qt::Horizontal,tr("25~50um"));                 //420A-96：＞15um     420B-2006：＞15um(14um(c))
	model->setHeaderData(6,Qt::Horizontal,tr("50~100um"));                //420A-96：＞25um     420B-2006：＞25um(21um(c))
	model->setHeaderData(7,Qt::Horizontal,tr("＞100um"));                 //420A-96：＞50um     420B-2006：＞50um(38um(c))
	//model->setHeaderData(8,Qt::Horizontal,tr("＞100um(70um(c))"))       仅针对型号420B-2006

    ui.tableView->setModel(model);
    model->select();

}
void test::on_clicked_createfile(){
	  ui.text->setText("is clicked");
      ReadDataFromSqlWriteToCSV("newnew","newnew.csv");
	 


}
void test::ReadDataFromSqlWriteToCSV(const QString &tableName,const QString &csvFileName)//将表导出为csv格式表格
{

    QSqlTableModel *db = new QSqlTableModel();

    db->setTable(tableName);

    db->select();

    QStringList strList;//记录数据库中的一行报警数据

    QString strString;

    const QString FILE_PATH(csvFileName);

    QFile csvFile(FILE_PATH);

	qDebug("ready to open");
    if (csvFile.open(QIODevice::ReadWrite))
    {
        qDebug("open successful");
		for (int i=0;i<db->rowCount();i++)
        {
            for(int j=0;j<db->columnCount();j++) {

                strList.insert(j,db->data(db->index(i,j)).toString());//把每一行的每一列数据读取到strList中
            }

            strString = strList.join(", ")+"\n";//给两个列数据之前加“,”号，一行数据末尾加回车

            strList.clear();//记录一行数据后清空，再记下一行数据

            csvFile.write(strString.toUtf8());//使用方法：转换为Utf8格式后在windows下的excel打开是乱码,可先用notepad++打开并转码为unicode，再次用excel打开即可。

            qDebug()<<strString.toUtf8();

        }

        csvFile.close();

    }
 } 
test::~test()
{

}
