/****************************************************************************
** Meta object code from reading C++ file 'maxlengthconstraintdialog.h'
**
** Created: Fri 9. Mar 17:01:30 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../constraints/MaxLength/maxlengthconstraintdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maxlengthconstraintdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaxLengthConstraintDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxLengthConstraintDialog[] = {
    "MaxLengthConstraintDialog\0\0"
    "buttonBoxAcceptedSlot()\0"
};

const QMetaObject MaxLengthConstraintDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MaxLengthConstraintDialog,
      qt_meta_data_MaxLengthConstraintDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxLengthConstraintDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxLengthConstraintDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxLengthConstraintDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxLengthConstraintDialog))
        return static_cast<void*>(const_cast< MaxLengthConstraintDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MaxLengthConstraintDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: buttonBoxAcceptedSlot(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
