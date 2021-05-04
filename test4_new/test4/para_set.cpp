#include "para_set.h"
#include "ui_para_set.h"
#include "Globals.h"
para_set::para_set(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

	//设置背景
	//QPixmap pixmap = QPixmap(":/test4/Resources/bg6.png");
	//QPalette palette(this->palette());
	//palette.setBrush(QPalette::Background, QBrush(pixmap));
	//this->setPalette(palette);
	ui->spinBox->setStyleSheet("QSpinBox:down-button{width:20px;height:31px;subcontrol-position:left}QSpinBox:up-button{width:20px;height:31px;subcontrol-position:right}");
	
}

para_set::~para_set()
{
	delete ui;
}

QString para_set::getinput()
{
	biaozhun = ui->comboBox2 ->currentText();
	weimi = biaozhun.mid(0,2);
	qDebug()<<"weimi"<<weimi;
	QString s = "检测标准:"+ui->comboBox1->currentText()+" \r\n\r\n粒径形式:"+ui->comboBox2 ->currentText()+ "\r\n\r\n检测周期:"+ui->comboBox3->currentText()+"\r\n\r\n流速值:"+ui->comboBox4->currentText()+"\r\n\r\n流速方式:"+ ui->comboBox5->currentText()+" \r\n\r\n打印模式:"+ui->comboBox6->currentText();
	return s;
	
}
