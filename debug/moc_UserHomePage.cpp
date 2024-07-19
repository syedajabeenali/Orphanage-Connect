/****************************************************************************
** Meta object code from reading C++ file 'UserHomePage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UserHomePage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserHomePage.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSUserHomePageENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUserHomePageENDCLASS = QtMocHelpers::stringData(
    "UserHomePage",
    "openOrphansInfo",
    "",
    "goBackToLogin",
    "openDonationForm",
    "openAdoptionForm",
    "openWeeklySportsActivities",
    "openContact"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUserHomePageENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[17];
    char stringdata5[17];
    char stringdata6[27];
    char stringdata7[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUserHomePageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUserHomePageENDCLASS_t qt_meta_stringdata_CLASSUserHomePageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "UserHomePage"
        QT_MOC_LITERAL(13, 15),  // "openOrphansInfo"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 13),  // "goBackToLogin"
        QT_MOC_LITERAL(44, 16),  // "openDonationForm"
        QT_MOC_LITERAL(61, 16),  // "openAdoptionForm"
        QT_MOC_LITERAL(78, 26),  // "openWeeklySportsActivities"
        QT_MOC_LITERAL(105, 11)   // "openContact"
    },
    "UserHomePage",
    "openOrphansInfo",
    "",
    "goBackToLogin",
    "openDonationForm",
    "openAdoptionForm",
    "openWeeklySportsActivities",
    "openContact"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserHomePageENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UserHomePage::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserHomePageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserHomePageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserHomePageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserHomePage, std::true_type>,
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

void UserHomePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserHomePage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openOrphansInfo(); break;
        case 1: _t->goBackToLogin(); break;
        case 2: _t->openDonationForm(); break;
        case 3: _t->openAdoptionForm(); break;
        case 4: _t->openWeeklySportsActivities(); break;
        case 5: _t->openContact(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *UserHomePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserHomePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserHomePageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UserHomePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
