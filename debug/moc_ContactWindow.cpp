/****************************************************************************
** Meta object code from reading C++ file 'ContactWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ContactWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContactWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSContactWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSContactWindowENDCLASS = QtMocHelpers::stringData(
    "ContactWindow",
    "searchContacts",
    "",
    "openOrphansInfo",
    "goBackToLogin",
    "openDonationForm",
    "openAdoptionForm",
    "openWeeklySportsActivities",
    "openContact"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSContactWindowENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[14];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[14];
    char stringdata5[17];
    char stringdata6[17];
    char stringdata7[27];
    char stringdata8[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSContactWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSContactWindowENDCLASS_t qt_meta_stringdata_CLASSContactWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ContactWindow"
        QT_MOC_LITERAL(14, 14),  // "searchContacts"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 15),  // "openOrphansInfo"
        QT_MOC_LITERAL(46, 13),  // "goBackToLogin"
        QT_MOC_LITERAL(60, 16),  // "openDonationForm"
        QT_MOC_LITERAL(77, 16),  // "openAdoptionForm"
        QT_MOC_LITERAL(94, 26),  // "openWeeklySportsActivities"
        QT_MOC_LITERAL(121, 11)   // "openContact"
    },
    "ContactWindow",
    "searchContacts",
    "",
    "openOrphansInfo",
    "goBackToLogin",
    "openDonationForm",
    "openAdoptionForm",
    "openWeeklySportsActivities",
    "openContact"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSContactWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ContactWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSContactWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSContactWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSContactWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ContactWindow, std::true_type>,
        // method 'searchContacts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openOrphansInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goBackToLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openDonationForm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openAdoptionForm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openWeeklySportsActivities'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ContactWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContactWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->searchContacts(); break;
        case 1: _t->openOrphansInfo(); break;
        case 2: _t->goBackToLogin(); break;
        case 3: _t->openDonationForm(); break;
        case 4: _t->openAdoptionForm(); break;
        case 5: _t->openWeeklySportsActivities(); break;
        case 6: _t->openContact(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ContactWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSContactWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ContactWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
