/****************************************************************************
** Meta object code from reading C++ file 'editsearchusr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Client/UI/TrainUI/editsearchusr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editsearchusr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_editSearchUsr_t {
    QByteArrayData data[8];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_editSearchUsr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_editSearchUsr_t qt_meta_stringdata_editSearchUsr = {
    {
QT_MOC_LITERAL(0, 0, 13), // "editSearchUsr"
QT_MOC_LITERAL(1, 14, 24), // "on_myticketBtn_2_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 24), // "on_myinformBtn_2_clicked"
QT_MOC_LITERAL(4, 65, 38), // "on_stationToStationSearchBtn_..."
QT_MOC_LITERAL(5, 104, 27), // "on_trainSearchBtn_2_clicked"
QT_MOC_LITERAL(6, 132, 29), // "on_stationSearchBtn_2_clicked"
QT_MOC_LITERAL(7, 162, 23) // "on_deleteUsrBtn_clicked"

    },
    "editSearchUsr\0on_myticketBtn_2_clicked\0"
    "\0on_myinformBtn_2_clicked\0"
    "on_stationToStationSearchBtn_2_clicked\0"
    "on_trainSearchBtn_2_clicked\0"
    "on_stationSearchBtn_2_clicked\0"
    "on_deleteUsrBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_editSearchUsr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void editSearchUsr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        editSearchUsr *_t = static_cast<editSearchUsr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_myticketBtn_2_clicked(); break;
        case 1: _t->on_myinformBtn_2_clicked(); break;
        case 2: _t->on_stationToStationSearchBtn_2_clicked(); break;
        case 3: _t->on_trainSearchBtn_2_clicked(); break;
        case 4: _t->on_stationSearchBtn_2_clicked(); break;
        case 5: _t->on_deleteUsrBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject editSearchUsr::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_editSearchUsr.data,
      qt_meta_data_editSearchUsr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *editSearchUsr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *editSearchUsr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_editSearchUsr.stringdata0))
        return static_cast<void*>(const_cast< editSearchUsr*>(this));
    return QDialog::qt_metacast(_clname);
}

int editSearchUsr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
