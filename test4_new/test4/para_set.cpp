#include "para_set.h"
#include "ui_para_set.h"
#include "Globals.h"
para_set::para_set(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

	//���ñ���
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
	QString s = "����׼:"+ui->comboBox1->currentText()+" \r\n\r\n������ʽ:"+ui->comboBox2 ->currentText()+ "\r\n\r\n�������:"+ui->comboBox3->currentText()+"\r\n\r\n����ֵ:"+ui->comboBox4->currentText()+"\r\n\r\n���ٷ�ʽ:"+ ui->comboBox5->currentText()+" \r\n\r\n��ӡģʽ:"+ui->comboBox6->currentText();
	return s;
	
}
