/****************************************************************************
** Meta object code from reading C++ file 'test4.h'
**
** Created: Sat Jan 23 20:50:02 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test4.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_test4[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      27,    6,    6,    6, 0x08,
      46,    6,    6,    6, 0x08,
      64,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_test4[] = {
    "test4\0\0on_search_clicked()\0"
    "on_start_clicked()\0on_back_clicked()\0"
    "on_back2_clicked()\0"
};

const QMetaObject test4::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_test4,
      qt_meta_data_test4, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &test4::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *test4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *test4::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_test4))
        return static_cast<void*>(const_cast< test4*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int test4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_search_clicked(); break;
        case 1: on_start_clicked(); break;
        case 2: on_back_clicked(); break;
        case 3: on_back2_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
