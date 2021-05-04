#include "test.h"
#include <QDateTime>
#include <QDebug>
#include <QDir>
test::test(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	db = QSqlDatabase::addDatabase("QSQLITE");//���ݿ�����
	
    db.setDatabaseName("TEST");//�������ӣ��Ѵ��ڼ����ӣ������ڼ���������
	QSqlQuery query;
    if(!query.exec("create table new("              //NAS1638�Լ�GJB420A-96
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
	model->setHeaderData(0,Qt::Horizontal,tr("����ʱ��"));
	model->setHeaderData(1,Qt::Horizontal,tr("Ŀ��ȼ�"));
	model->setHeaderData(2,Qt::Horizontal,tr("���ȵȼ�"));
	model->setHeaderData(3,Qt::Horizontal,tr("5~15um"));                  //420A-96����2um      420B-2006����1um(4um(c))
	model->setHeaderData(4,Qt::Horizontal,tr("15~25um"));                 //420A-96����5um      420B-2006����5um(6um(c))
	model->setHeaderData(5,Qt::Horizontal,tr("25~50um"));                 //420A-96����15um     420B-2006����15um(14um(c))
	model->setHeaderData(6,Qt::Horizontal,tr("50~100um"));                //420A-96����25um     420B-2006����25um(21um(c))
	model->setHeaderData(7,Qt::Horizontal,tr("��100um"));                 //420A-96����50um     420B-2006����50um(38um(c))
	//model->setHeaderData(8,Qt::Horizontal,tr("��100um(70um(c))"))       ������ͺ�420B-2006

    ui.tableView->setModel(model);
    model->select();

}
void test::on_clicked_createfile(){
	  ui.text->setText("is clicked");
      ReadDataFromSqlWriteToCSV("newnew","newnew.csv");
	 


}
void test::ReadDataFromSqlWriteToCSV(const QString &tableName,const QString &csvFileName)//������Ϊcsv��ʽ���
{

    QSqlTableModel *db = new QSqlTableModel();

    db->setTable(tableName);

    db->select();

    QStringList strList;//��¼���ݿ��е�һ�б�������

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

                strList.insert(j,db->data(db->index(i,j)).toString());//��ÿһ�е�ÿһ�����ݶ�ȡ��strList��
            }

            strString = strList.join(", ")+"\n";//������������֮ǰ�ӡ�,���ţ�һ������ĩβ�ӻس�

            strList.clear();//��¼һ�����ݺ���գ��ټ���һ������

            csvFile.write(strString.toUtf8());//ʹ�÷�����ת��ΪUtf8��ʽ����windows�µ�excel��������,������notepad++�򿪲�ת��Ϊunicode���ٴ���excel�򿪼��ɡ�

            qDebug()<<strString.toUtf8();

        }

        csvFile.close();

    }
 } 
test::~test()
{

}
