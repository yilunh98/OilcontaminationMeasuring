#include "para_set.h"
#include "ui_para_set.h"

para_set::para_set(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
}

para_set::~para_set()
{
	delete ui;
}

QString para_set::getinput()
{
	QString s = "����׼:"+ui->comboBox1->currentText()+" ������ʽ:"+ui->comboBox2 ->currentText()+ "\n�������:"+ui->comboBox3->currentText()+" ����ֵ:"+ui->comboBox4->currentText()+"\n���ٷ�ʽ:"+ ui->comboBox5->currentText()+" ��ӡģʽ:"+ui->comboBox6->currentText();
	return s;
	
}