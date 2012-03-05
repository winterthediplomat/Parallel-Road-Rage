/****************************************************************************
** Meta object code from reading C++ file 'diagramwindow.h'
**
** Created: Mon 27. Feb 13:02:33 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../diagramwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diagramwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DiagramWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      25,   14,   14,   14, 0x08,
      41,   35,   14,   14, 0x08,
      68,   14,   14,   14, 0x28,
      74,   14,   14,   14, 0x08,
      80,   14,   14,   14, 0x08,
      87,   14,   14,   14, 0x08,
      95,   14,   14,   14, 0x08,
     110,   14,   14,   14, 0x08,
     123,   14,   14,   14, 0x08,
     136,   14,   14,   14, 0x08,
     152,   14,   14,   14, 0x08,
     169,   14,   14,   14, 0x08,
     183,   14,   14,   14, 0x08,
     195,   14,   14,   14, 0x08,
     207,   14,   14,   14, 0x08,
     221,   14,   14,   14, 0x08,
     239,   14,   14,   14, 0x08,
     257,   14,   14,   14, 0x08,
     270,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DiagramWindow[] = {
    "DiagramWindow\0\0addNode()\0addLink()\0"
    "items\0del(QList<QGraphicsItem*>)\0del()\0"
    "cut()\0copy()\0paste()\0bringToFront()\0"
    "sendToBack()\0properties()\0updateActions()\0"
    "generateReport()\0updateLinks()\0"
    "openGraph()\0saveGraph()\0selectNodes()\0"
    "switchNodesSlot()\0getDistanceSlot()\0"
    "getTSPSlot()\0chooseConstraintSlot()\0"
};

const QMetaObject DiagramWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DiagramWindow,
      qt_meta_data_DiagramWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DiagramWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DiagramWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DiagramWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DiagramWindow))
        return static_cast<void*>(const_cast< DiagramWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DiagramWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addNode(); break;
        case 1: addLink(); break;
        case 2: del((*reinterpret_cast< QList<QGraphicsItem*>(*)>(_a[1]))); break;
        case 3: del(); break;
        case 4: cut(); break;
        case 5: copy(); break;
        case 6: paste(); break;
        case 7: bringToFront(); break;
        case 8: sendToBack(); break;
        case 9: properties(); break;
        case 10: updateActions(); break;
        case 11: generateReport(); break;
        case 12: updateLinks(); break;
        case 13: openGraph(); break;
        case 14: saveGraph(); break;
        case 15: selectNodes(); break;
        case 16: switchNodesSlot(); break;
        case 17: getDistanceSlot(); break;
        case 18: getTSPSlot(); break;
        case 19: chooseConstraintSlot(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
