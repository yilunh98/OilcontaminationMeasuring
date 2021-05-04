/****************************************************************************
** Meta object code from reading C++ file 'child_window1.h'
**
** Created: Sun Jan 24 11:42:32 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../child_window1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'child_window1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_child_window1[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   14,   14,   14, 0x08,
      39,   14,   14,   14, 0x08,
      53,   14,   14,   14, 0x08,
      63,   14,   14,   14, 0x08,
      75,   14,   14,   14, 0x08,
      94,   14,   14,   14, 0x08,
     114,   14,   14,   14, 0x08,
     125,   14,   14,   14, 0x08,
     136,   14,   14,   14, 0x08,
     147,   14,   14,   14, 0x08,
     158,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_child_window1[] = {
    "child_window1\0\0mySignal()\0changeSlot()\0"
    "setstandard()\0setdate()\0setdate_2()\0"
    "on_excel_clicked()\0on_setsql_clicked()\0"
    "teststa1()\0teststa2()\0teststa3()\0"
    "teststa4()\0teststa5()\0"
};

const QMetaObject child_window1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_child_window1,
      qt_meta_data_child_window1, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &child_window1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *child_window1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *child_window1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_child_window1))
        return static_cast<void*>(const_cast< child_window1*>(this));
    return QWidget::qt_metacast(_clname);
}

int child_window1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mySignal(); break;
        case 1: changeSlot(); break;
        case 2: setstandard(); break;
        case 3: setdate(); break;
        case 4: setdate_2(); break;
        case 5: on_excel_clicked(); break;
        case 6: on_setsql_clicked(); break;
        case 7: teststa1(); break;
        case 8: teststa2(); break;
        case 9: teststa3(); break;
        case 10: teststa4(); break;
        case 11: teststa5(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void child_window1::mySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
