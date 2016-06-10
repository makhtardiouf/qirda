/****************************************************************************
** Meta object code from reading C++ file 'qirda.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qirda.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qirda.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qirda[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      18,    6,    6,    6, 0x0a,
      30,    6,    6,    6, 0x0a,
      51,    6,    6,    6, 0x0a,
      87,   75,   67,    6, 0x0a,
     118,  116,    6,    6, 0x0a,
     132,    6,    6,    6, 0x0a,
     145,    6,    6,    6, 0x0a,
     163,    6,    6,    6, 0x0a,
     178,    6,    6,    6, 0x0a,
     185,    6,    6,    6, 0x0a,
     201,    6,    6,    6, 0x0a,
     224,  216,    6,    6, 0x0a,
     253,  249,    6,    6, 0x0a,
     275,  249,    6,    6, 0x0a,
     296,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Qirda[] = {
    "Qirda\0\0AddFiles()\0TellAbout()\0"
    "ClearSelectedFiles()\0DetectDevices()\0"
    "QString\0container,i\0GetFileName(QStringList,int)\0"
    "i\0Progress(int)\0QuitNicely()\0"
    "ResetLocaleLang()\0SelectRcvDir()\0"
    "Send()\0SetLocaleLang()\0StartSending()\0"
    "process\0ShowDebugData(QProcess*)\0msg\0"
    "ShowDebugMsg(QString)\0ShowStatMsg(QString)\0"
    "ToggleReceiving()\0"
};

void Qirda::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Qirda *_t = static_cast<Qirda *>(_o);
        switch (_id) {
        case 0: _t->AddFiles(); break;
        case 1: _t->TellAbout(); break;
        case 2: _t->ClearSelectedFiles(); break;
        case 3: _t->DetectDevices(); break;
        case 4: { QString _r = _t->GetFileName((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: _t->Progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->QuitNicely(); break;
        case 7: _t->ResetLocaleLang(); break;
        case 8: _t->SelectRcvDir(); break;
        case 9: _t->Send(); break;
        case 10: _t->SetLocaleLang(); break;
        case 11: _t->StartSending(); break;
        case 12: _t->ShowDebugData((*reinterpret_cast< QProcess*(*)>(_a[1]))); break;
        case 13: _t->ShowDebugMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->ShowStatMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->ToggleReceiving(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Qirda::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Qirda::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Qirda,
      qt_meta_data_Qirda, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Qirda::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Qirda::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Qirda::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qirda))
        return static_cast<void*>(const_cast< Qirda*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Qirda::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
