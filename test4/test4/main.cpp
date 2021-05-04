#include "test4.h"
#include <QTextCodec>
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFile qss("spin.qss");
       if( qss.open(QFile::ReadOnly))
       {
           qDebug("open success");
           QString style = QLatin1String(qss.readAll());
           a.setStyleSheet(style);
           qss.close();

       }
       else
       {
          qDebug("Open failed");
 }

	QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

	test4 w;
	w.show();
	return a.exec();
}
