#include "child_window2.h"
#include "ui_child_window2.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <QElapsedTimer>
#include "Globals.h"
QString child_window2::receive = " ";
child_window2::child_window2(QWidget *parent):
	QWidget(parent),
	ui(new Ui::Form2)
{
	ui->setupUi(this);
	//初始化参数
	flag_sj=0;
	flag_yb=0;
	flag_jc=1;
	memset(jiance->td,0,sizeof(jiance->td));		//通道检测结果
	memset(jiance->dj,0,sizeof(jiance->dj));		//等级结果

	//receive1 = new JIANCE;
	//receive2 = new JIANCE;
	//receive3 = new JIANCE;
	//memset(receive1->td,0,sizeof(receive1->td));		//通道检测结果
	//memset(receive1->dj,0,sizeof(receive1->dj));		//等级结果
	//memset(receive2->td,0,sizeof(receive2->td));		//通道检测结果
	//memset(receive2->dj,0,sizeof(receive2->dj));		//等级结果
	//memset(receive3->td,0,sizeof(receive3->td));		//通道检测结果
	//memset(receive3->dj,0,sizeof(receive3->dj));		//等级结果


	//设置背景
	/*QPixmap pixmap = QPixmap(":/test4/Resources/bg5.png").scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);*/
	connect(ui->backtomainwindow2,SIGNAL(clicked()),this,SLOT(changeSlot2()));
	connect(ui->spinBox_9,SIGNAL(valueChanged(int)),this,SLOT(change_liusu()));

	ui_init();

	//开启检测仪串口，波特率9600，485协议COM3，无校验位，8数据位，1停止位
	myComjc = new SerialPort();
	myComjc->OpenPort(this,3,9600,0,8,0);
	connect(myComjc,SIGNAL(writeText(const QString&)),this,SLOT(readMyComjc(const QString&)),Qt::QueuedConnection);

	//开启油泵串口，波特率9600，232，COM4，无校验位，8数据位，1停止位
	myComyb = new SerialPort();
	myComyb->OpenPort(this,4,9600,0,8,0);

	//开启打印机串口，波特率9600，485，COM1，无校验位，8数据位，1停止位
	myComdy = new SerialPort();
	myComdy->OpenPort(this,1,9600,0,8,0);

	time1=new QTimer();
	time1->start(1000);
	connect(time1,SIGNAL(timeout()),this,SLOT(showdatetime()));
	timer.start();
}

child_window2::~child_window2()
{
	delete ui;
	myComjc->ClosePort();
	myComjc->ClosePort();
	myComdy->ClosePort();
	delete time1;


}
void child_window2::ui_init(){

	QFont ft4;
	ft4.setPointSize(14);
	QFont ft2;
	ft2.setPointSize(12);
	QFont ft6;
	ft6.setPointSize(16);
	QFont ft8;
	ft8.setPointSize(18);
	ft8.setBold(true);
	ui->spinBox_1->setStyleSheet("QSpinBox:down-button{width:20px;height:37px;subcontrol-position:left}QSpinBox:up-button{width:20px;height:37px;subcontrol-position:right}");
	ui->spinBox_2->setStyleSheet("QSpinBox:down-button{width:20px;height:37px;subcontrol-position:left}QSpinBox:up-button{width:20px;height:37px;subcontrol-position:right}");
	ui->spinBox_3->setStyleSheet("QSpinBox:down-button{width:20px;height:37px;subcontrol-position:left}QSpinBox:up-button{width:20px;height:37px;subcontrol-position:right}");
	ui->spinBox_4->setStyleSheet("QSpinBox:down-button{width:20px;height:37px;subcontrol-position:left}QSpinBox:up-button{width:20px;height:37px;subcontrol-position:right}");
	ui->spinBox_5->setStyleSheet("QSpinBox:down-button{width:20px;height:37px;subcontrol-position:left}QSpinBox:up-button{width:20px;height:37px;subcontrol-position:right}");
	ui->spinBox_9->setStyleSheet("QSpinBox:down-button{width:20px;height:31px;subcontrol-position:left}QSpinBox:up-button{width:20px;height:31px;subcontrol-position:right}");
	ui->textBrowser->setAlignment(Qt::AlignLeft);
	ui->textBrowser->setAlignment(Qt::AlignVCenter);
	ui->label_2->setFont(ft4);ui->label_2->setStyleSheet("color:rgb(0,0,127)");
	ui->label_3->setFont(ft8);ui->label_3->setStyleSheet("color:rgb(0,0,127)");
	ui->label_4->setFont(ft4);ui->label_4->setStyleSheet("color:rgb(0,0,127)");
	ui->label_5->setFont(ft4);ui->label_5->setStyleSheet("color:white");
	ui->label_6->setFont(ft4);ui->label_6->setStyleSheet("color:white");
	ui->label_2->setText(pset.getinput());	
	ui->label_3->setText("NAS1638");
	qDebug()<<"pset.getinput"<<ui->label_2->text();
	ui->label1->setFont(ft4);ui->label1->setStyleSheet("color:rgb(0,0,127)");
	ui->label2->setFont(ft4);ui->label2->setStyleSheet("color:rgb(0,0,127)");
	ui->label3->setFont(ft4);ui->label3->setStyleSheet("color:rgb(0,0,127)");
	ui->label4->setFont(ft4);ui->label4->setStyleSheet("color:rgb(0,0,127)");
	ui->label5->setFont(ft4);ui->label5->setStyleSheet("color:rgb(0,0,127)");
	ui->textEdit1->setAlignment(Qt:: AlignCenter);ui->textEdit1->setFont(ft4);
	ui->textEdit2->setAlignment(Qt:: AlignCenter);ui->textEdit2->setFont(ft4);
	ui->textEdit3->setAlignment(Qt:: AlignCenter);ui->textEdit3->setFont(ft4);
	ui->textEdit4->setAlignment(Qt:: AlignCenter);ui->textEdit4->setFont(ft4);
	ui->textEdit5->setAlignment(Qt:: AlignCenter);ui->textEdit5->setFont(ft4);
	ui->textEdit8->setAlignment(Qt:: AlignCenter);ui->textEdit8->setFont(ft4);
	ui->textEdit9->setAlignment(Qt:: AlignCenter);ui->textEdit9->setFont(ft4);
	ui->textEdit10->setAlignment(Qt:: AlignCenter);ui->textEdit10->setFont(ft4);
	ui->textEdit11->setAlignment(Qt:: AlignCenter);ui->textEdit11->setFont(ft4);
	ui->textEdit12->setAlignment(Qt:: AlignCenter);ui->textEdit12->setFont(ft4);
	ui->label1->setText(" 5~15  "+biaozhun);
	ui->label2->setText("15~25  "+biaozhun);
	ui->label3->setText("25~50  "+biaozhun);
	ui->label4->setText("50~100 "+biaozhun);
	ui->label5->setText("  >100 "+biaozhun);
	QFile file("/ResidentFlash/test4/NAS1638.txt");
    file.open(QFile::ReadOnly | QIODevice::Text);
	QTextStream stream(&file);
    QString str = stream.readAll();
	qDebug()<<"nas1638 origin"<<str;
	QStringList strlist = str.split(" ");
	ui->spinBox_1->setValue((strlist[0]).toInt());
	ui->spinBox_2->setValue((strlist[1]).toInt());
	ui->spinBox_3->setValue((strlist[2]).toInt());
	ui->spinBox_4->setValue((strlist[3]).toInt());
	ui->spinBox_5->setValue((strlist[4]).toInt());
	pset.ui->spinBox->setValue(0);

}
void child_window2::showdatetime(){
	QString datetime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QStringList strList = datetime.split(" ");
	ui->label_5->setText(strList[0]);
	ui->label_6->setText(strList[1]);
}
void child_window2::change_liusu(){
	qDebug()<<"liusu is changing";
	if(!flag_yb){
		int liusu = (ui->spinBox_9->text()).toInt();
		//输出为通道2
		unsigned char lpOutBuffer[8]={0x01,0x06,0x00,0x01};
		if (liusu==0){lpOutBuffer[4]=0x00;lpOutBuffer[5]=0x00;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x0A;}
		else if (liusu==1){lpOutBuffer[4]=0x00;lpOutBuffer[5]=0x64;lpOutBuffer[6]=0xD9;lpOutBuffer[7]=0xE1;}
		else if (liusu==2){lpOutBuffer[4]=0x00;lpOutBuffer[5]=0xC8;lpOutBuffer[6]=0xD9;lpOutBuffer[7]=0x9C;}
		else if (liusu==3){lpOutBuffer[4]=0x01;lpOutBuffer[5]=0x2C;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x47;}
		else if (liusu==4){lpOutBuffer[4]=0x01;lpOutBuffer[5]=0x90;lpOutBuffer[6]=0xD9;lpOutBuffer[7]=0xF6;}
		else if (liusu==5){lpOutBuffer[4]=0x01;lpOutBuffer[5]=0xF4;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x1D;}
		else if (liusu==6){lpOutBuffer[4]=0x02;lpOutBuffer[5]=0x58;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x90;}
		else if (liusu==7){lpOutBuffer[4]=0x02;lpOutBuffer[5]=0xBC;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0xDB;}
		else if (liusu==8){lpOutBuffer[4]=0x03;lpOutBuffer[5]=0x20;lpOutBuffer[6]=0xD9;lpOutBuffer[7]=0x22;}
		else if (liusu==9){lpOutBuffer[4]=0x03;lpOutBuffer[5]=0x84;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x99;}
		else if (liusu==10){lpOutBuffer[4]=0x03;lpOutBuffer[5]=0xE8;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0xB4;}
		myComyb->WriteSyncPort(reinterpret_cast<const char*>(lpOutBuffer),8);
	}
}
void child_window2::readMyComjc(const QString &str){
	receive = str;
	qDebug("s3%d",flag_sj);
	if (!flag_jc){
			
		if (flag_sj==0){
			if (data_process(str)==1){
				//memcpy(receive1->td,jiance->td,sizeof(receive1->td));
				//memcpy(receive1->dj,jiance->dj,sizeof(receive1->dj));
				flag_sj=1;
				ui->label_4->setText("完成检测1");	
			} 
		}
		else if(flag_sj==1){
			if (data_process(str)==1){
				//memcpy(receive2->td,jiance->td,sizeof(receive2->td));
				//memcpy(receive2->dj,jiance->dj,sizeof(receive2->dj));
				flag_sj=2;
				ui->label_4->setText("完成检测2");	
			} 
		}
		else if(flag_sj==2){
			if (data_process(str)==1){
				//memcpy(receive3->td,jiance->td,sizeof(receive3->td));
				//memcpy(receive3->dj,jiance->dj,sizeof(receive3->dj));
				//bool tiaojian = abs(receive1->td[0]-receive2->td[0])<5 && abs(receive2->td[0]-receive3->td[0]<5);
				if(true){
					//连续发送两次，防止没有收到
					QString end = "WG\r";
					myComjc->WriteSyncPort(QString2byte(end),3);
					Sleep(1000);
					myComjc->WriteSyncPort(QString2byte(end),3);
					ui->starttest->setText("开始检测");
					ui->starttest->setStyleSheet("background:rgb(101,111,177);color: rgb(252, 252, 252)");
					ui->label_4->setText("检测未开始");	
					flag_jc=1;
					flag_sj=0;
					QString parain = ui->label_2->text();	    
					QString stanin = parain[11];
					//数据库数据存储
					database_process(stanin);
					if (pset.ui->comboBox6->currentText()=="自动")print_message();
					if (stanin=="8"){
						QFile file("/ResidentFlash/test4/NAS1638.txt");
						file.open(QFile::WriteOnly | QIODevice::Text);
						QTextStream stream(&file);
						stream<< ui->spinBox_1->text() << " "<< ui->spinBox_2->text()<<" "\
							<<ui->spinBox_3->text()<<" "<< ui->spinBox_4->text()<<" "<<ui->spinBox_5->text();}
					else if (stanin=="6"){
						QFile file("/ResidentFlash/test4/ISO4406.txt");
						file.open(QFile::WriteOnly | QIODevice::Text);
						QTextStream stream(&file);
						stream<< ui->spinBox_1->text() << " "<< ui->spinBox_2->text()<<" "\
						<<ui->spinBox_3->text();
						file.close();}
		
				}
				flag_sj=0;	//不满足停止条件则开始继续检测
			} 
			
		}
	}

}
//油泵相关处理函数(已经测试过为正常)
void child_window2::on_deviceon_clicked()
{
	if(!flag_yb){
		//油泵此时为关闭状态
		unsigned char lpOutBuffer[8]={0x01,0x06,0x00,0x01,0x00,0x00,0xD8,0x0A};
		myComyb->WriteSyncPort(reinterpret_cast<const char*>(lpOutBuffer),8);
		ui->deviceon->setText("开启油泵");
		ui->deviceon->setStyleSheet("background:rgb(101,111,177);color: rgb(252, 252, 252)");
		flag_yb=1;
	}
	else{
		//此时油泵为开启状态
		ui->deviceon->setText("关闭油泵");
		ui->deviceon->setStyleSheet("background:rgb(0,0,127);color: rgb(252, 252, 252)");
		flag_yb=0;
		////关闭油泵串口
		//m_serial_yb.ClosePort();
		int liusu = (ui->spinBox_9->text()).toInt();
		//输出为通道2
		qDebug()<<liusu;
		unsigned char lpOutBuffer[8]={0x01,0x06,0x00,0x01};
		if (liusu==0){lpOutBuffer[4]=0x00;lpOutBuffer[5]=0x00;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x0A;}
		else if (liusu==1){lpOutBuffer[4]=0x00;lpOutBuffer[5]=0x64;lpOutBuffer[6]=0xD9;lpOutBuffer[7]=0xE1;}
		else if (liusu==2){lpOutBuffer[4]=0x00;lpOutBuffer[5]=0xC8;lpOutBuffer[6]=0xD9;lpOutBuffer[7]=0x9C;}
		else if (liusu==3){lpOutBuffer[4]=0x01;lpOutBuffer[5]=0x2C;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x47;}
		else if (liusu==4){lpOutBuffer[4]=0x01;lpOutBuffer[5]=0x90;lpOutBuffer[6]=0xD9;lpOutBuffer[7]=0xF6;}
		else if (liusu==5){lpOutBuffer[4]=0x01;lpOutBuffer[5]=0xF4;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x1D;}
		else if (liusu==6){lpOutBuffer[4]=0x02;lpOutBuffer[5]=0x58;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x90;}
		else if (liusu==7){lpOutBuffer[4]=0x02;lpOutBuffer[5]=0xBC;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0xDB;}
		else if (liusu==8){lpOutBuffer[4]=0x03;lpOutBuffer[5]=0x20;lpOutBuffer[6]=0xD9;lpOutBuffer[7]=0x22;}
		else if (liusu==9){lpOutBuffer[4]=0x03;lpOutBuffer[5]=0x84;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0x99;}
		else if (liusu==10){lpOutBuffer[4]=0x03;lpOutBuffer[5]=0xE8;lpOutBuffer[6]=0xD8;lpOutBuffer[7]=0xB4;}
		qDebug()<<lpOutBuffer;
		myComyb->WriteSyncPort(reinterpret_cast<const char*>(lpOutBuffer),8);
		//等串口发送完开启信息给个回复
		QToolTip::showText(mapToGlobal(ui->deviceon->pos()+QPoint(ui->deviceon->width()/2, ui->deviceon->height()/2)),"设备连接成功");
	}

}
//点击参数设置按钮
void child_window2::on_paraset_clicked()
{
	if(!flag_jc)
	{
		//此时机器正在检测，不能设置
		QMessageBox mess(QMessageBox::NoIcon,tr("提示"),tr("机器正在检测中,无法设置!   "));
		mess.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
		//mess.setGeometry(40,60,500,310);
		QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
		mess.setStyleSheet("background-color: rgb(201,210,189);font:14px");
		mess.exec();

	}
	else{
		pset.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
		pset.setGeometry(20,60,520,320);
		//bool para_setok = pset.exec();
		//ui->lbl_text_2->show();
		if (pset.exec()==QDialog::Accepted){
			//清空之前显示结果
			
			clear_result();
			QFont ft;
			ft.setPointSize(12);
			QFont ft2;
			ft2.setPointSize(14);

				
			ui->label_2->setFont(ft2);
			ui->label_2->setStyleSheet("color:rgb(0,0,127)");
			ui->label_2->setText(pset.getinput());	
		
			//pset.close();			
			QString parain = ui->label_2->text();	    
			QString stanin = parain[11];
			qDebug()<<"stanin"<<stanin;
			QString str = "μm";
			QByteArray temp1 = str.toLocal8Bit().toHex();
			if(stanin=="8"){
				ui->textEdit4->show();
				ui->textEdit5->show();
				ui->textEdit11->show();
				ui->textEdit12->show();
				ui->spinBox_4->show();
				ui->spinBox_5->show();
				ui->label4->show();
				ui->label5->show();
				ui->label_3->setText("NAS1638");
				QFile file("/ResidentFlash/test4/NAS1638.txt");
				file.open(QFile::ReadOnly | QIODevice::Text);
				QTextStream stream(&file);
				str = stream.readAll();
				QStringList strlist = str.split(" ");
				ui->spinBox_1->setValue((strlist[0]).toInt());
				ui->spinBox_2->setValue((strlist[1]).toInt());
				ui->spinBox_3->setValue((strlist[2]).toInt());
				ui->spinBox_4->setValue((strlist[3]).toInt());
				ui->spinBox_5->setValue((strlist[4]).toInt());
				if (biaozhun.toLocal8Bit().toHex()==temp1){
					ui->label1->setText(" 5~15  "+biaozhun);
					ui->label2->setText("15~25  "+biaozhun);
					ui->label3->setText("25~50  "+biaozhun);
					ui->label4->setText("50~100 "+biaozhun);
					ui->label5->setText("  >100 "+biaozhun);}
				else{
					ui->label1->setText(" 6~14 "+biaozhun);
					ui->label2->setText("14~21 "+biaozhun);
					ui->label3->setText("21~38 "+biaozhun);
					ui->label4->setText("38~70 "+biaozhun);
					ui->label5->setText("  >70 "+biaozhun);
				}
				
			}
			else if(stanin=="6"){
				QFile file("/ResidentFlash/test4/ISO4406.txt");
				file.open(QFile::ReadOnly | QIODevice::Text);
				QTextStream stream(&file);
				str = stream.readAll();
				QStringList strlist = str.split(" ");
				ui->spinBox_1->setValue((strlist[0]).toInt());
				ui->spinBox_2->setValue((strlist[1]).toInt());
				ui->spinBox_3->setValue((strlist[2]).toInt());
				ui->label_3->setText("ISO4406");
				ui->textEdit4->hide();
				ui->textEdit5->hide();
				ui->textEdit11->hide();
				ui->textEdit12->hide();
				ui->spinBox_4->hide();
				ui->spinBox_5->hide();
				ui->label4->hide();
				ui->label5->hide();
				//其他label的值
				if (biaozhun.toLocal8Bit().toHex()==temp1){
					ui->label1->setText(">1  "+biaozhun);
					ui->label2->setText(">5  "+biaozhun);
					ui->label3->setText(">15 "+biaozhun);}
				else{
					ui->label1->setText(">4  "+biaozhun);
					ui->label2->setText(">6  "+biaozhun);
					ui->label3->setText(">14 "+biaozhun);
				}	
			}
			//发送标准设置
			QMessageBox mess1(QMessageBox::NoIcon,tr("提示"),tr("正在设置参数中"));
			mess1.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
			QPushButton *okbutton1 = (mess1.addButton(tr("确定"),QMessageBox::AcceptRole));
			mess1.setStyleSheet("background-color: rgb(201,210,189);font:14px");
			mess1.show();
			set_parameter();
			//ui->lbl_text_2->hide();
			QMessageBox mess2(QMessageBox::NoIcon,tr("提示"),tr("参数设置成功!  "));
			mess2.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
			QPushButton *okbutton2 = (mess2.addButton(tr("确定"),QMessageBox::AcceptRole));
			mess2.setStyleSheet("background-color: rgb(201,210,189);font:14px");
			mess2.exec();
		}
	}

}
//开始检测按钮
void child_window2::on_starttest_clicked()
{
	if(flag_jc){
		clear_result();
		ui->label_4->setText("正在检测中...");
		QString start = "WK\r";
		myComjc->WriteSyncPort(QString2byte(start),3);
		Sleep(1000);
		myComjc->WriteSyncPort(QString2byte(start),3);
		//发送两次防止没有结果接收到
		ui->starttest->setText("停止检测");
		ui->starttest->setStyleSheet("background:rgb(0,0,127);color: rgb(252, 252, 252)");
		flag_jc = 0;
		
		QString parain = ui->label_2->text();	    
		QString stanin = parain[11];
		//数据库数据存储

	}
	else{ 
		//否则就是中途点击停止检测 跳出提示框，yes就停止检测，no就重新继续检测
		QMessageBox mess(QMessageBox::NoIcon,tr("提示"),tr("检测未结束,确定停止吗?"));
		QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::YesRole));
		QPushButton *cancelbutton = (mess.addButton(tr("取消"),QMessageBox::NoRole));
		mess.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
		mess.setStyleSheet("background-color: rgb(201,210,189);font:14px;");
		int reply; 
		reply = mess.exec();
		if (reply == 0) { 
			flag_jc = 1;
			QString end = "WG\r";
			myComjc->WriteSyncPort(QString2byte(end),3);
			Sleep(1000);
			myComjc->WriteSyncPort(QString2byte(end),3);
			ui->starttest->setText("开始检测");
			ui->starttest->setStyleSheet("background:rgb(101,111,177);color: rgb(252, 252, 252)");
			ui->label_4->setText("检测未开始");	
		}
		else if (reply == 1)  {
			flag_jc = 0;}
		
	}
}

void child_window2::on_print_clicked()
{
if(!flag_jc)
	{
		//此时机器正在检测，不能设置
		QMessageBox mess(QMessageBox::NoIcon,tr("提示"),tr("机器正在检测中,无法设置!   "));
		mess.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
		//mess.setGeometry(40,60,500,310);
		QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
		mess.setStyleSheet("background-color: rgb(201,210,189);font:14px");
		mess.exec();
	}
else{	
	print_message();

	}
		
}
void child_window2::print_message(){
	//QByteArray qb1;
	//QString tmp;
	//unsigned char HexDataBuf1[10]={0x1B,0x40,0x1D,0x21,0x00,0x1C,0x26,0x1B,0x39,0x01};
	//qb1.append(reinterpret_cast<char*>(HexDataBuf1),10);
	//tmp = "上海航威机电设备有限公司\r\n颗粒度检测结果\r\n--------------------------------\r\n日期时间:";
	//QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	//QString biaozhun = pset.ui->comboBox1->currentText();
	//tmp = tmp+date+"\r\n"+"检测标准:"+biaozhun+"\r\n";
	//qb1.append(tmp.toLocal8Bit());
	//unsigned char HexDataBuf3[14] = {0x1B,0x40,0x1D,0x21,0x00,0x1C,0x26,0x1B,0x39,0x01,0x1B,0x24,0x00,0x00};
	//qb1.append(reinterpret_cast<char*>(HexDataBuf3),14);
	//tmp = "粒径";
	//qb1.append(tmp.toLocal8Bit());
	//unsigned char HexDataBuf4[4]={0x1B,0x24,0xAA,0x00};
	//qb1.append(reinterpret_cast<char*>(HexDataBuf4),4);
	//tmp = "颗粒数/ml";
	//qb1.append(tmp.toLocal8Bit());
	//unsigned char HexDataBuf5[4]={0x1B,0x24,0x40,0x01};
	//qb1.append(reinterpret_cast<char*>(HexDataBuf5),4);
	//tmp = "等级\r\n";
	//qb1.append(tmp.toLocal8Bit());
	//QString parain = ui->label_2->text();	    
	//QString stanin = parain[11];
	////qb1.append(tongdaoresult(stanin));
	//tmp = "\r\n\r\n\r\n";
	//qb1.append(tmp);
	//myComdy->WriteSyncPort(qb1.data(),qb1.size());
	QByteArray qb1;
	QString parain = ui->label_2->text();	    
	QString stanin = parain[11];
	QByteArray tdresult = tongdaoresult(stanin);
	qb1.append(tdresult);
	unsigned char ziti[2]={0x1B,0x40};
	qb1.append(reinterpret_cast<char*>(ziti),2);
	unsigned char jcdj[8]={0xBC,0xEC,0xB2,0xE2,0xB5,0xC8,0xBC,0xB6};
	qb1.append(reinterpret_cast<char*>(jcdj),8);
	QString dj;
	if (stanin=="8"){dj = ui->textEdit8->toPlainText();}
	if (stanin=="6"){dj = ui->textEdit9->toPlainText();}
	dj = ":"+dj+"\n";
	qb1.append(dj.toLocal8Bit());
	unsigned char jcsj[8]={0xBC,0xEC,0xB2,0xE2,0xCA,0xB1,0xBC,0xE4};
	qb1.append(reinterpret_cast<char*>(jcsj),8);
	QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	date = ":"+date+"\n";
	qb1.append(date.toLocal8Bit());
	unsigned char jcbz[8]={0xBC,0xEC,0xB2,0xE2,0xB1,0xEA,0xD7,0xBC};
	qb1.append(reinterpret_cast<char*>(jcbz),8);
	QString biaozhun = pset.ui->comboBox1->currentText();
	biaozhun = ":"+biaozhun+"\n\n";
	qb1.append(biaozhun.toLocal8Bit());
	//unsigned char ziti2[6]={0x1B,0x55,0x02,0x1B,0x61,0x01};
	//qb1.append(reinterpret_cast<char*>(ziti2),6);
	unsigned char qk[2] = {0x1B,0x40};
	QString hunahang= "==============================\n";
	qb1.append(reinterpret_cast<char*>(qk),2);
	qb1.append(hunahang.toLocal8Bit());
	unsigned char shhw[26] = {0xC9,0xCF,0xBA,0xA3,0xBA,0xBD,0xCD,0xFE,\
								0xBB,0xFA,0xB5,0xE7,0xC9,0xE8,0xB1,0xB8,\
								0xD3,0xD0,0xCF,0xDE,0xB9,0xAB,0xCB,0xBE,0x0D,0x0A}; 
	qb1.append(reinterpret_cast<char*>(shhw),26);
	unsigned char kldjc[16]={0xBF,0xC5,0xC1,0xA3,0xB6,0xC8,0xBC,0xEC,0xB2,0xE2,0xBD,0xE1,0xB9,0xFB,0x0D,0x0A};
	qb1.append(reinterpret_cast<char*>(kldjc),16);
	qb1.append(hunahang.toLocal8Bit());
	qb1.append(reinterpret_cast<char*>(qk),2);
	QString hh = "\r\n\r\n\r\n\r\n";
	qb1.append(hh.toLocal8Bit());
	myComdy->WriteSyncPort(qb1.data(),qb1.size());

}

void child_window2::changeSlot2()
{
	if(!flag_jc)
	{
		//此时机器正在检测，不能设置
		QMessageBox mess(QMessageBox::NoIcon,tr("提示"),tr("机器正在检测中,无法设置!   "));
		mess.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
		//mess.setGeometry(40,60,500,310);
		QPushButton *okbutton = (mess.addButton(tr("确定"),QMessageBox::AcceptRole));
		mess.setStyleSheet("background-color: rgb(201,210,189);font:14px");
		mess.exec();

	}
	else{
		clear_result();
		emit mySignal2();
	}
	 
}
char* child_window2::QString2byte(QString str){
	QByteArray ba = str.toLatin1(); // must
	return ba.data();
}
void child_window2::set_parameter(){	
	QString bz = pset.ui->comboBox1->currentText();
	QString bz_send;
	if (bz =="NAS1638")
		bz_send = "WH0\r";
	else if(bz =="ISO4406")
		bz_send = "WH3\r";
	qDebug()<<"bz_send"<<bz_send;
	myComjc->WriteSyncPort(QString2byte(bz_send),4);
	Sleep(1000);
	qDebug()<<"bz_send"<<receive;
	//设置粒径
	QString lj_send;
	QString str = "μm";
	QByteArray temp1 = str.toLocal8Bit().toHex();
	if(biaozhun.toLocal8Bit().toHex()==temp1)
		lj_send = "WU0\r";
	else{lj_send = "WU1\r";}
	qDebug()<<"lj_send"<<lj_send;
	myComjc->WriteSyncPort(QString2byte(lj_send),4);
	Sleep(1000);
	qDebug()<<"lj_send"<<receive;
	//设置流速
	QString liusu = pset.ui->comboBox4->currentText();
	QString liusu2 = liusu.mid(0,2);
	QString lsfangshi = pset.ui->comboBox5->currentText();
	QString ls_send;
	if (lsfangshi=="设置")
		ls_send = "WV1"+liusu2+'\r';
	if (lsfangshi=="自动")
		ls_send = "WV0\r";
	qDebug()<<"ls_send"<<ls_send;
	myComjc->WriteSyncPort(QString2byte(ls_send),strlen(QString2byte(ls_send)));
	Sleep(1000);
	qDebug()<<"ls_send"<<receive;
	//设置间隔时间
	QString jiange = pset.ui->comboBox3->currentText();
	QString jiange2 = jiange.mid(0,2);
	int shiji = jiange2.toInt()/5;
	QString send=QString::number(shiji);
	if (shiji<10)
		send = '0'+send;
	QString jg_send="WD"+send+'\r';
	qDebug()<<"jg_send"<<jg_send;
	myComjc->WriteSyncPort(QString2byte(jg_send),5);
	Sleep(1000);
	qDebug()<<"jg_send"<<receive;
	
}
//"H22015-10-29 15: 1:12 DAT   10000T    3654T    2189T     156T      56T       7L111112111212"
int child_window2::data_process(QString data_receive){
	if (data_receive.at(0) == 'H'){
		
		int dat_pos,dj_pos;
		dat_pos = data_receive.indexOf("DAT")+3; //从T结束下一个位置开始
		QString tds,djs;
		int channel=0;
		int sub;
		QString parain = ui->label_2->text();	    
		QChar stanin = parain[11];
		qDebug()<<data_receive.at(1);
		qDebug()<<stanin;
		if(data_receive.at(1)=='0'&&stanin!='8'||(data_receive.at(1)=='3'&&stanin!='6')){
			flag_jc = 1;
			QString end = "WG\r";
			myComjc->WriteSyncPort(QString2byte(end),3);
			Sleep(1000);
			myComjc->WriteSyncPort(QString2byte(end),3);
			ui->starttest->setText("开始检测");
			ui->starttest->setStyleSheet("background:rgb(101,111,177);color: rgb(252, 252, 252)");
			ui->label_4->setText("检测未开始");	
			QMessageBox mess2(QMessageBox::NoIcon,tr("提示"),tr("标准选择错误,请重新设置"));
			mess2.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); 
			QPushButton *okbutton2 = (mess2.addButton(tr("确定"),QMessageBox::AcceptRole));
			mess2.setStyleSheet("font:14px");
			mess2.exec();
			return false;
		}
		//NAS1638协议，5通道
		if (data_receive.at(1)=='0'){
			channel = 5;
			sub = 1;}
		//ISO4406，3通道
		else if (data_receive.at(1)=='3'){
			channel = 3;
			sub = 0;}
		dj_pos = dat_pos + 9*channel;
		for (int i=0;i<channel;i++){
			tds= data_receive.mid(dat_pos+9*i,8);
			jiance->td[i] = (tds.remove(QRegExp("\\s"))).toInt();
			jiance->dj[i] = data_receive.mid(dj_pos+2*i,2).toInt();
			jiance->dj[i] = (jiance->dj[i])?(jiance->dj[i]-sub):0;}

		ui->textEdit1->setPlainText(QString("%1").arg(jiance->td[0],5,10,QLatin1Char(' ')));
		ui->textEdit2->setPlainText(QString("%1").arg(jiance->td[1],5,10,QLatin1Char(' ')));
		ui->textEdit3->setPlainText(QString("%1").arg(jiance->td[2],5,10,QLatin1Char(' ')));
		ui->textEdit4->setPlainText(QString("%1").arg(jiance->td[3],5,10,QLatin1Char(' ')));
		ui->textEdit5->setPlainText(QString("%1").arg(jiance->td[4],5,10,QLatin1Char(' ')));
		//ui->textEdit1->setPlainText(QString::number(jiance->td[0]));
		//ui->textEdit2->setPlainText(QString::number(jiance->td[1]));
		//ui->textEdit3->setPlainText(QString::number(jiance->td[2]));
		//ui->textEdit4->setPlainText(QString::number(jiance->td[3]));
		//ui->textEdit5->setPlainText(QString::number(jiance->td[4]));

		ui->textEdit8->setPlainText(QString("%1").arg(jiance->dj[0],2,10,QLatin1Char(' ')));
		ui->textEdit9->setPlainText(QString("%1").arg(jiance->dj[1],2,10,QLatin1Char(' ')));
		ui->textEdit10->setPlainText(QString("%1").arg(jiance->dj[2],2,10,QLatin1Char(' ')));
		ui->textEdit11->setPlainText(QString("%1").arg(jiance->dj[3],2,10,QLatin1Char(' ')));
		ui->textEdit12->setPlainText(QString("%1").arg(jiance->dj[4],2,10,QLatin1Char(' ')));
		//ui->textEdit8->setPlainText(QString::number(jiance->dj[0]));
		//ui->textEdit9->setPlainText(QString::number(jiance->dj[1]));
		//ui->textEdit10->setPlainText(QString::number(jiance->dj[2]));
		//ui->textEdit11->setPlainText(QString::number(jiance->dj[3]));
		//ui->textEdit12->setPlainText(QString::number(jiance->dj[4]));

		if (jiance->dj[0]>(ui->spinBox_1->text()).toInt())
			ui->textEdit8->setStyleSheet("background:rgb(127,127,127)");
		qDebug()<<"检测结果"<<jiance->dj[0]<<"预期设定值"<<ui->spinBox_1->text().toInt();
		if (jiance->dj[1]>(ui->spinBox_2->text()).toInt())
			ui->textEdit9->setStyleSheet("background:rgb(127,127,127)");
		if (jiance->dj[2]>(ui->spinBox_3->text()).toInt())
			ui->textEdit10->setStyleSheet("background:rgb(127,127,127)");
		if (jiance->dj[3]>(ui->spinBox_4->text()).toInt())
			ui->textEdit11->setStyleSheet("background:rgb(127,127,127)");
		if (jiance->dj[4]>(ui->spinBox_5->text()).toInt())
			ui->textEdit12->setStyleSheet("background:rgb(127,127,127)");
		return 1;
		}
		return 0;
}
void child_window2::database_process(QString stanin){
	QString name;
	{
		QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");//数据库类型
		db2.setDatabaseName("/ResidentFlash/test4/TEST");//建立连接，已存在即连接，不存在即建立连接
		if(!db2.open())//打开连接
		{
			QMessageBox::warning(this,"wrong",db2.lastError().text());
			return;
		}
		QSqlQuery query;
		//机器编号
		QString num = pset.ui->spinBox->text();

		QString tl1 = ui->spinBox_1->text();
		QString tl2 = ui->spinBox_2->text();
		QString tl3 = ui->spinBox_3->text();
		QString tl4 = ui->spinBox_4->text();
		QString tl5 = ui->spinBox_5->text();

		QString td1=ui->textEdit1->toPlainText();
		QString td2=ui->textEdit2->toPlainText();
		QString td3=ui->textEdit3->toPlainText();
		QString td4=ui->textEdit4->toPlainText();
		QString td5=ui->textEdit5->toPlainText();

		QString dj1=ui->textEdit8->toPlainText();
		QString dj2=ui->textEdit9->toPlainText();
		QString dj3=ui->textEdit10->toPlainText();
		QString dj4=ui->textEdit11->toPlainText();
		QString dj5=ui->textEdit12->toPlainText();
		if(stanin=="8"){
				QString t1 = tl1+"/"+tl2+"/"+tl3+"/"+tl4+"/"+tl5;
				QString c1= dj1+"/"+dj2+"/"+dj3+"/"+dj4+"/"+dj5;
				qDebug()<<t1;
				qDebug()<<c1;
				QString str = QString("insert into new8 " 
					"values ('%1','%2','%3','%4','%5','%6','%7','%8','%9')").arg(num).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))\
					.arg(t1).arg(c1).arg(td1).arg(td2).arg(td3).arg(td4).arg(td5);
				qDebug()<<str;
				if(!query.exec(str))
					QMessageBox::warning(this,"wrong",query.lastError().text());
				QSqlTableModel * model = new QSqlTableModel(this,db2);
				model->setTable("new8");

		}
		else if(stanin=="6"){
				QString t1 = tl1+"/"+tl2+"/"+tl3;
				QString c1= dj1+"/"+dj2+"/"+dj3;
				QString str = QString("insert into new6 " 
					"values ('%1','%2','%3','%4','%5','%6','%7')").arg(num).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))\
					.arg(t1).arg(c1).arg(td1).arg(td2).arg(td3);
				if(!query.exec(str))
					QMessageBox::warning(this,"wrong",query.lastError().text());

				QSqlTableModel * model = new QSqlTableModel(this,db2);
				model->setTable("new6");
		}
		name = QSqlDatabase::database().connectionName();
		
	}

}
void child_window2::clear_result(){
	ui->textEdit1->clear();
	ui->textEdit2->clear();
	ui->textEdit3->clear();
	ui->textEdit4->clear();
	ui->textEdit5->clear();

	ui->textEdit8->clear();ui->textEdit8->setStyleSheet(0);//ui->textEdit8->setStyleSheet("background-color:white");
	ui->textEdit9->clear();ui->textEdit9->setStyleSheet(0);//ui->textEdit9->setStyleSheet("background-color:white");
	ui->textEdit10->clear();ui->textEdit10->setStyleSheet(0);//ui->textEdit10->setStyleSheet("background-color:white");
	ui->textEdit11->clear();ui->textEdit11->setStyleSheet(0);//ui->textEdit11->setStyleSheet("background-color:white");
	ui->textEdit12->clear();ui->textEdit12->setStyleSheet(0);//ui->textEdit12->setStyleSheet("background-color:white");
}
QByteArray child_window2::tongdaoresult(QString stanin){
	QByteArray data;
	unsigned char zbf[1] = {0x09};

	QStringList label;
	label<<ui->label1->text()<<ui->label2->text()<<ui->label3->text()
	<<ui->label4->text()<<ui->label5->text();
	
	QStringList td;
	td<<ui->textEdit1->toPlainText()<<ui->textEdit2->toPlainText()
	<<ui->textEdit3->toPlainText()<<ui->textEdit4->toPlainText()
	<<ui->textEdit5->toPlainText();
	
	QStringList dj;
	dj<<ui->textEdit8->toPlainText()<<ui->textEdit9->toPlainText()
	<<ui->textEdit10->toPlainText()<<ui->textEdit11->toPlainText()
	<<ui->textEdit12->toPlainText();
	int channel;
	qDebug()<<stanin;
	if (stanin =="8")channel=5;
	else if (stanin=="6")channel=3;
	unsigned char qswz[8] = {0x1B,0x40,0x1B,0x44,0x02,0x11,0x1B,0x00};
	data.append(reinterpret_cast<char*>(qswz),8);
	for (int i=channel-1;i>=0;i--){
		qDebug()<<"no result"<<td.at(i);
		data.append(reinterpret_cast<char*>(zbf),1);
		data.append(label.at(i).toLocal8Bit());
		data.append(reinterpret_cast<char*>(zbf),1);
		data.append(td.at(i).toLocal8Bit());
		data.append(reinterpret_cast<char*>(zbf),1);
		data.append(dj.at(i).toLocal8Bit());
		unsigned char dayin[2] = {0x0D,0x0A};
		data.append(reinterpret_cast<char*>(dayin),2);
	}
	unsigned char ljkldj[22]={0x09,0xC1,0xA3,0xBE,0xB6,0x09,0xBF,0xC5,\
							0xC1,0xA3,0xCA,0xFD,0x2F,0x6D,0x6C,0x09,\
							0xB5,0xC8,0xBC,0xB6,0x0D,0x0D};
	data.append(reinterpret_cast<char*>(ljkldj),22);
	QString hunahang= "------------------------------\n";
	data.append(hunahang.toLocal8Bit());
	qDebug()<<"data"<< data.size();
	return data;
}