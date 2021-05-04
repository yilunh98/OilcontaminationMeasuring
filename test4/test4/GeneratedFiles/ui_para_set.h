/********************************************************************************
** Form generated from reading UI file 'para_set.ui'
**
** Created: Sun Jan 24 11:15:51 2021
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

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox6;
    QComboBox *comboBox1;
    QComboBox *comboBox5;
    QLabel *label;
    QComboBox *comboBox3;
    QLabel *label_2;
    QComboBox *comboBox2;
    QComboBox *comboBox4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(497, 275);
        Dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 253, 253);"));
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(260, 220, 191, 41));
        buttonBox->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 111, 177);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox6 = new QComboBox(Dialog);
        comboBox6->setObjectName(QString::fromUtf8("comboBox6"));
        comboBox6->setGeometry(QRect(340, 130, 101, 31));
        QFont font;
        font.setPointSize(12);
        comboBox6->setFont(font);
        comboBox1 = new QComboBox(Dialog);
        comboBox1->setObjectName(QString::fromUtf8("comboBox1"));
        comboBox1->setGeometry(QRect(140, 30, 101, 31));
        comboBox1->setFont(font);
        comboBox5 = new QComboBox(Dialog);
        comboBox5->setObjectName(QString::fromUtf8("comboBox5"));
        comboBox5->setGeometry(QRect(140, 130, 101, 31));
        comboBox5->setFont(font);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 0, 91, 191));
        label->setFont(font);
        comboBox3 = new QComboBox(Dialog);
        comboBox3->setObjectName(QString::fromUtf8("comboBox3"));
        comboBox3->setGeometry(QRect(140, 80, 101, 31));
        comboBox3->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 30, 71, 131));
        label_2->setFont(font);
        comboBox2 = new QComboBox(Dialog);
        comboBox2->setObjectName(QString::fromUtf8("comboBox2"));
        comboBox2->setGeometry(QRect(340, 30, 101, 31));
        comboBox2->setFont(font);
        comboBox4 = new QComboBox(Dialog);
        comboBox4->setObjectName(QString::fromUtf8("comboBox4"));
        comboBox4->setGeometry(QRect(340, 80, 101, 31));
        comboBox4->setFont(font);

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
         << QApplication::translate("Dialog", "GJB420A-96", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "GJB420B-2006", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\320\223OCT17216", 0, QApplication::UnicodeUTF8)
        );
        comboBox5->clear();
        comboBox5->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\350\207\252\345\212\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("Dialog", "\346\243\200\346\265\213\346\240\207\345\207\206:\n"
"\n"
"\n"
"\346\243\200\346\265\213\345\221\250\346\234\237:\n"
"\n"
"\n"
"\346\265\201\351\200\237\346\226\271\345\274\217:", 0, QApplication::UnicodeUTF8));
        comboBox3->clear();
        comboBox3->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "10s", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "05s", 0, QApplication::UnicodeUTF8)
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
        label_2->setText(QApplication::translate("Dialog", "\347\262\222\345\276\204\345\275\242\345\274\217:\n"
"\n"
"\n"
"\346\265\201\351\200\237\345\200\274:\n"
"\n"
"\n"
"\346\211\223\345\215\260\346\250\241\345\274\217:", 0, QApplication::UnicodeUTF8));
        comboBox2->clear();
        comboBox2->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "um(c)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "um", 0, QApplication::UnicodeUTF8)
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
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARA_SET_H
