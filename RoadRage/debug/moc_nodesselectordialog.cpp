/****************************************************************************
** Meta object code from reading C++ file 'nodesselectordialog.h'
**
** Created: Fri 9. Mar 17:01:27 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nodesselectordialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodesselectordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NodesSelectorDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   21,   20,   20, 0x08,
      79,   21,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NodesSelectorDialog[] = {
    "NodesSelectorDialog\0\0currentRow\0"
    "on_secondNodeListWidget_currentRowChanged(int)\0"
    "on_firstNodeListWidget_currentRowChanged(int)\0"
};

const QMetaObject NodesSelectorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NodesSelectorDialog,
      qt_meta_data_NodesSelectorDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NodesSelectorDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NodesSelectorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NodesSelectorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NodesSelectorDialog))
        return static_cast<void*>(const_cast< NodesSelectorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NodesSelectorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_secondNodeListWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_firstNodeListWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
