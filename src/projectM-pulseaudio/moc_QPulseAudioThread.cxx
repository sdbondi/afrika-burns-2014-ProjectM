/****************************************************************************
** Meta object code from reading C++ file 'QPulseAudioThread.hpp'
**
** Created: Fri Dec 20 13:22:40 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QPulseAudioThread.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPulseAudioThread.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QPulseAudioThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      35,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   18,   18,   18, 0x0a,
      71,   60,   18,   18, 0x0a,
      97,   18,   18,   18, 0x0a,
     113,  107,   18,   18, 0x0a,
     140,   18,   18,   18, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_QPulseAudioThread[] = {
    "QPulseAudioThread\0\0deviceChanged()\0"
    "threadCleanedUp()\0cork()\0index,name\0"
    "insertSource(int,QString)\0cleanup()\0"
    "index\0connectDevice(QModelIndex)\0"
    "connectDevice()\0"
};

void QPulseAudioThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QPulseAudioThread *_t = static_cast<QPulseAudioThread *>(_o);
        switch (_id) {
        case 0: _t->deviceChanged(); break;
        case 1: _t->threadCleanedUp(); break;
        case 2: _t->cork(); break;
        case 3: _t->insertSource((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->cleanup(); break;
        case 5: _t->connectDevice((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->connectDevice(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QPulseAudioThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QPulseAudioThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QPulseAudioThread,
      qt_meta_data_QPulseAudioThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QPulseAudioThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QPulseAudioThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QPulseAudioThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPulseAudioThread))
        return static_cast<void*>(const_cast< QPulseAudioThread*>(this));
    return QThread::qt_metacast(_clname);
}

int QPulseAudioThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QPulseAudioThread::deviceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QPulseAudioThread::threadCleanedUp()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
