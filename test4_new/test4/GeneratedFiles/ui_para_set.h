/********************************************************************************
** Form generated from reading UI file 'para_set.ui'
**
** Created: Sat Mar 13 17:31:36 2021
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARA_SET_H
#define UI_PARA_SET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox6;
    QComboBox *comboBox1;
    QComboBox *comboBox5;
    QComboBox *comboBox3;
    QComboBox *comboBox2;
    QComboBox *comboBox4;
    QSpinBox *spinBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(497, 357);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(280, 260, 191, 41));
        buttonBox->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox6 = new QComboBox(Dialog);
        comboBox6->setObjectName(QString::fromUtf8("comboBox6"));
        comboBox6->setGeometry(QRect(340, 140, 101, 31));
        QPalette palette;
        QBrush brush(QColor(101, 111, 177, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(253, 253, 253, 253));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        comboBox6->setPalette(palette);
        QFont font;
        font.setPointSize(12);
        comboBox6->setFont(font);
        comboBox1 = new QComboBox(Dialog);
        comboBox1->setObjectName(QString::fromUtf8("comboBox1"));
        comboBox1->setGeometry(QRect(130, 25, 101, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        comboBox1->setPalette(palette1);
        comboBox1->setFont(font);
        comboBox1->setContextMenuPolicy(Qt::NoContextMenu);
        comboBox1->setInsertPolicy(QComboBox::InsertAtBottom);
        comboBox5 = new QComboBox(Dialog);
        comboBox5->setObjectName(QString::fromUtf8("comboBox5"));
        comboBox5->setGeometry(QRect(130, 140, 101, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        comboBox5->setPalette(palette2);
        comboBox5->setFont(font);
        comboBox3 = new QComboBox(Dialog);
        comboBox3->setObjectName(QString::fromUtf8("comboBox3"));
        comboBox3->setGeometry(QRect(130, 85, 101, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        comboBox3->setPalette(palette3);
        comboBox3->setFont(font);
        comboBox2 = new QComboBox(Dialog);
        comboBox2->setObjectName(QString::fromUtf8("comboBox2"));
        comboBox2->setGeometry(QRect(340, 25, 101, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        comboBox2->setPalette(palette4);
        comboBox2->setFont(font);
        comboBox4 = new QComboBox(Dialog);
        comboBox4->setObjectName(QString::fromUtf8("comboBox4"));
        comboBox4->setGeometry(QRect(340, 85, 101, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        comboBox4->setPalette(palette5);
        comboBox4->setFont(font);
        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(130, 190, 101, 31));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimumSize(QSize(51, 0));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        spinBox->setPalette(palette6);
        spinBox->setFont(font);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMaximum(10);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 25, 120, 30));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 85, 120, 30));
        QFont font2;
        font2.setPointSize(14);
        label_4->setFont(font2);
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 140, 120, 30));
        label_5->setFont(font2);
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 190, 120, 30));
        label_6->setFont(font2);
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(240, 25, 120, 30));
        label_8->setFont(font1);
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(240, 85, 120, 30));
        label_9->setFont(font1);
        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(240, 140, 120, 30));
        label_10->setFont(font1);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        comboBox6->clear();
        comboBox6->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\346\211\213\345\212\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\350\207\252\345\212\250", 0, QApplication::UnicodeUTF8)
        );
        comboBox1->clear();
        comboBox1->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "NAS1638", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO4406", 0, QApplication::UnicodeUTF8)
        );
        comboBox5->clear();
        comboBox5->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\350\207\252\345\212\250", 0, QApplication::UnicodeUTF8)
        );
        comboBox3->clear();
        comboBox3->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "05s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "10s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "15s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "20s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "25s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "30s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "35s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "40s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "45s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "50s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "55s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "60s", 0, QApplication::UnicodeUTF8)
        );
        comboBox2->clear();
        comboBox2->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\302\265m", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\302\265m(c)", 0, QApplication::UnicodeUTF8)
        );
        comboBox4->clear();
        comboBox4->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "25ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "05ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "10ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "15ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "20ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "30ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "35ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "40ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "45ml/min", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "50ml/min", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">\346\243\200\346\265\213\346\240\207\345\207\206:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#00007f;\">\346\243\200\346\265\213\345\221\250\346\234\237:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#00007f;\">\346\265\201\351\200\237\346\226\271\345\274\217:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#00007f;\">\346\234\272\345\231\250\347\274\226\345\217\267:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">\347\262\222\345\276\204\345\275\242\345\274\217:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">\346\265\201\351\200\237\345\200\274:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00007f;\">\346\211\223\345\215\260\346\250\241\345\274\217:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARA_SET_H
