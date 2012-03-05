/****************************************************************************
** Meta object code from reading C++ file 'linkinfodialog.h'
**
** Created: Tue 22. Nov 17:17:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../linkinfodialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linkinfodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LinkInfoDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      34,   15,   15,   15, 0x08,
      53,   15,   15,   15, 0x08,
      79,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LinkInfoDialog[] = {
    "LinkInfoDialog\0\0setEnabledFirst()\0"
    "setEnabledSecond()\0updateFirstLinkDistance()\0"
    "updateSecondLinkDistance()\0"
};

const QMetaObject LinkInfoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LinkInfoDialog,
      qt_meta_data_LinkInfoDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LinkInfoDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LinkInfoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LinkInfoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LinkInfoDialog))
        return static_cast<void*>(const_cast< LinkInfoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LinkInfoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setEnabledFirst(); break;
        case 1: setEnabledSecond(); break;
        case 2: updateFirstLinkDistance(); break;
        case 3: updateSecondLinkDistance(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
