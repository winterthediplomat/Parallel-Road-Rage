/****************************************************************************
** Meta object code from reading C++ file 'constraintchooserdialog.h'
**
** Created: Mon 27. Feb 13:02:40 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../constraintchooserdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'constraintchooserdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConstraintChooserDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   25,   24,   24, 0x08,
      81,   25,   24,   24, 0x08,
     131,   24,   24,   24, 0x08,
     154,   24,   24,   24, 0x08,
     177,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConstraintChooserDialog[] = {
    "ConstraintChooserDialog\0\0currentRow\0"
    "currentRowChangedInConstraintListWidget(int)\0"
    "currentRowChangedInSetUpConstraintListWidget(int)\0"
    "createConstraintSlot()\0deleteConstraintSlot()\0"
    "updateConstraintSlot()\0"
};

const QMetaObject ConstraintChooserDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConstraintChooserDialog,
      qt_meta_data_ConstraintChooserDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConstraintChooserDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConstraintChooserDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConstraintChooserDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConstraintChooserDialog))
        return static_cast<void*>(const_cast< ConstraintChooserDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConstraintChooserDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentRowChangedInConstraintListWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: currentRowChangedInSetUpConstraintListWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: createConstraintSlot(); break;
        case 3: deleteConstraintSlot(); break;
        case 4: updateConstraintSlot(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
