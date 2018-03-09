/****************************************************************************
** Meta object code from reading C++ file 'test_runner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test_runner/test_runner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_runner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_test_runner_t {
    QByteArrayData data[5];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_test_runner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_test_runner_t qt_meta_stringdata_test_runner = {
    {
QT_MOC_LITERAL(0, 0, 11), // "test_runner"
QT_MOC_LITERAL(1, 12, 20), // "find_by_credits_test"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 30), // "remove_divisible_students_test"
QT_MOC_LITERAL(4, 65, 33) // "count_students_starting_with_..."

    },
    "test_runner\0find_by_credits_test\0\0"
    "remove_divisible_students_test\0"
    "count_students_starting_with_test"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_test_runner[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void test_runner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        test_runner *_t = static_cast<test_runner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->find_by_credits_test(); break;
        case 1: _t->remove_divisible_students_test(); break;
        case 2: _t->count_students_starting_with_test(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject test_runner::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_test_runner.data,
      qt_meta_data_test_runner,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *test_runner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *test_runner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_test_runner.stringdata0))
        return static_cast<void*>(const_cast< test_runner*>(this));
    return QObject::qt_metacast(_clname);
}

int test_runner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
