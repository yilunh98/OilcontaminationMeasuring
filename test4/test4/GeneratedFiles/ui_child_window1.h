/********************************************************************************
** Form generated from reading UI file 'child_window1.ui'
**
** Created: Sun Jan 24 11:15:52 2021
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILD_WINDOW1_H
#define UI_CHILD_WINDOW1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *backtomainwindow;
    QPushButton *date;
    QPushButton *standard;
    QPushButton *excel;
    QTextBrowser *textBrowser;
    QPushButton *date_2;
    QPushButton *setsql;
    QTextEdit *textEdit;
    QTableView *tableView;
    QCalendarWidget *calendarWidget;
    QCalendarWidget *calendarWidget_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(798, 480);
        Form->setStyleSheet(QString::fromUtf8(""));
        backtomainwindow = new QPushButton(Form);
        backtomainwindow->setObjectName(QString::fromUtf8("backtomainwindow"));
        backtomainwindow->setGeometry(QRect(640, 60, 101, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        backtomainwindow->setFont(font);
        backtomainwindow->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(252, 252, 252);"));
        backtomainwindow->setInputMethodHints(Qt::ImhNone);
        backtomainwindow->setCheckable(false);
        date = new QPushButton(Form);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(160, 60, 100, 40));
        date->setFont(font);
        date->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(250, 250, 250);"));
        date->setInputMethodHints(Qt::ImhNone);
        date->setCheckable(false);
        standard = new QPushButton(Form);
        standard->setObjectName(QString::fromUtf8("standard"));
        standard->setGeometry(QRect(50, 60, 101, 40));
        standard->setFont(font);
        standard->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(248, 248, 248);"));
        standard->setInputMethodHints(Qt::ImhNone);
        standard->setCheckable(false);
        standard->setFlat(false);
        excel = new QPushButton(Form);
        excel->setObjectName(QString::fromUtf8("excel"));
        excel->setGeometry(QRect(530, 60, 100, 40));
        excel->setFont(font);
        excel->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(250, 250, 250);"));
        excel->setInputMethodHints(Qt::ImhNone);
        excel->setCheckable(false);
        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 3000, 25));
        QFont font1;
        font1.setPointSize(11);
        textBrowser->setFont(font1);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        date_2 = new QPushButton(Form);
        date_2->setObjectName(QString::fromUtf8("date_2"));
        date_2->setGeometry(QRect(270, 60, 100, 40));
        date_2->setFont(font);
        date_2->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(252, 252, 252);"));
        date_2->setInputMethodHints(Qt::ImhNone);
        date_2->setCheckable(false);
        setsql = new QPushButton(Form);
        setsql->setObjectName(QString::fromUtf8("setsql"));
        setsql->setGeometry(QRect(380, 60, 101, 40));
        setsql->setFont(font);
        setsql->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(248, 248, 248);"));
        setsql->setInputMethodHints(Qt::ImhNone);
        setsql->setCheckable(false);
        setsql->setFlat(false);
        textEdit = new QTextEdit(Form);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(340, 240, 104, 64));
        tableView = new QTableView(Form);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 120, 711, 351));
        calendarWidget = new QCalendarWidget(Form);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(80, 100, 248, 169));
        calendarWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(248, 248, 248);"));
        calendarWidget_2 = new QCalendarWidget(Form);
        calendarWidget_2->setObjectName(QString::fromUtf8("calendarWidget_2"));
        calendarWidget_2->setGeometry(QRect(190, 100, 248, 169));
        calendarWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);\n"
"color: rgb(248, 248, 248);"));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        backtomainwindow->setText(QApplication::translate("Form", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
        date->setText(QApplication::translate("Form", "\345\274\200\345\247\213\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        standard->setText(QApplication::translate("Form", "\351\200\211\346\213\251\346\240\207\345\207\206", 0, QApplication::UnicodeUTF8));
        excel->setText(QApplication::translate("Form", "\347\224\237\346\210\220excel", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#f5f5f5;\">\344\270\212\346\265\267\350\210\252\345\250\201\346\234\272\347\224\265\350\256\276\345\244\207\346\234\211\351\231\220\345\205\254\345\217\270</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        date_2->setText(QApplication::translate("Form", "\347\273\223\346\235\237\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
        setsql->setText(QApplication::translate("Form", "\345\274\200\345\247\213\346\243\200\347\264\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILD_WINDOW1_H
