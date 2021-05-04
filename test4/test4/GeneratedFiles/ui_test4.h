/********************************************************************************
** Form generated from reading UI file 'test4.ui'
**
** Created: Sun Jan 24 11:15:51 2021
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST4_H
#define UI_TEST4_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test4Class
{
public:
    QWidget *centralWidget;
    QPushButton *start;
    QPushButton *search;
    QTextBrowser *textBrowser;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test4Class)
    {
        if (test4Class->objectName().isEmpty())
            test4Class->setObjectName(QString::fromUtf8("test4Class"));
        test4Class->resize(800, 480);
        test4Class->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(test4Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(190, 180, 161, 91));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        start->setFont(font);
        start->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(248, 248, 248);"));
        search = new QPushButton(centralWidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(450, 180, 161, 91));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        search->setFont(font1);
        search->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(243, 243, 243);"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 3000, 25));
        QFont font2;
        font2.setPointSize(11);
        textBrowser->setFont(font2);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        test4Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(test4Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        test4Class->setStatusBar(statusBar);

        retranslateUi(test4Class);

        QMetaObject::connectSlotsByName(test4Class);
    } // setupUi

    void retranslateUi(QMainWindow *test4Class)
    {
        test4Class->setWindowTitle(QApplication::translate("test4Class", "test4", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("test4Class", "\345\274\200\345\247\213\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        search->setText(QApplication::translate("test4Class", "\346\225\260\346\215\256\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("test4Class", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#f5f5f5;\">\344\270\212\346\265\267\350\210\252\345\250\201\346\234\272\347\224\265\350\256\276\345\244\207\346\234\211\351\231\220\345\205\254\345\217\270</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class test4Class: public Ui_test4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST4_H
