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
	QString s = "检测标准:"+ui->comboBox1->currentText()+" 粒径形式:"+ui->comboBox2 ->currentText()+ "\n检测周期:"+ui->comboBox3->currentText()+" 流速值:"+ui->comboBox4->currentText()+"\n流速方式:"+ ui->comboBox5->currentText()+" 打印模式:"+ui->comboBox6->currentText();
	return s;
	
}