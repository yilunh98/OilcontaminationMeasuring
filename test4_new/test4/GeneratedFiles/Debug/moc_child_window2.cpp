/****************************************************************************
** Meta object code from reading C++ file 'child_window2.h'
**
** Created: Fri Jan 29 21:19:56 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../child_window2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'child_window2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_child_window2[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   14,   14,   14, 0x08,
      49,   14,   14,   14, 0x08,
      70,   14,   14,   14, 0x08,
      93,   14,   14,   14, 0x08,
     112,   14,   14,   14, 0x08,
     126,   14,   14,   14, 0x08,
     147,   14,   14,   14, 0x08,
     162,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_child_window2[] = {
    "child_window2\0\0mySignal2()\0"
    "on_deviceon_clicked()\0on_paraset_clicked()\0"
    "on_starttest_clicked()\0on_print_clicked()\0"
    "changeSlot2()\0readMyComjc(QString)\0"
    "change_liusu()\0showdatetime()\0"
};

const QMetaObject child_window2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_child_window2,
      qt_meta_data_child_window2, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &child_window2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *child_window2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *child_window2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_child_window2))
        return static_cast<void*>(const_cast< child_window2*>(this));
    return QWidget::qt_metacast(_clname);
}

int child_window2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mySignal2(); break;
        case 1: on_deviceon_clicked(); break;
        case 2: on_paraset_clicked(); break;
        case 3: on_starttest_clicked(); break;
        case 4: on_print_clicked(); break;
        case 5: changeSlot2(); break;
        case 6: readMyComjc((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: change_liusu(); break;
        case 8: showdatetime(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void child_window2::mySignal2()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
