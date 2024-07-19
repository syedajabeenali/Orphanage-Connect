/****************************************************************************
** Meta object code from reading C++ file 'AdminManageDonations.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AdminManageDonations.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdminManageDonations.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS = QtMocHelpers::stringData(
    "AdminManageDonations",
    "openOrphanRegistrationForm",
    "",
    "goBackToLogin",
    "openOrphansInfo",
    "openEmployeesInfo",
    "openAdoptionRequests",
    "openManageDonations"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[21];
    char stringdata1[27];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[16];
    char stringdata5[18];
    char stringdata6[21];
    char stringdata7[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS_t qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "AdminManageDonations"
        QT_MOC_LITERAL(21, 26),  // "openOrphanRegistrationForm"
        QT_MOC_LITERAL(48, 0),  // ""
        QT_MOC_LITERAL(49, 13),  // "goBackToLogin"
        QT_MOC_LITERAL(63, 15),  // "openOrphansInfo"
        QT_MOC_LITERAL(79, 17),  // "openEmployeesInfo"
        QT_MOC_LITERAL(97, 20),  // "openAdoptionRequests"
        QT_MOC_LITERAL(118, 19)   // "openManageDonations"
    },
    "AdminManageDonations",
    "openOrphanRegistrationForm",
    "",
    "goBackToLogin",
    "openOrphansInfo",
    "openEmployeesInfo",
    "openAdoptionRequests",
    "openManageDonations"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAdminManageDonationsENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject AdminManageDonations::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAdminManageDonationsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AdminManageDonations, std::true_type>,
        // method 'openOrphanRegistrationForm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goBackToLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openOrphansInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openEmployeesInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openAdoptionRequests'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openManageDonations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AdminManageDonations::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminManageDonations *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openOrphanRegistrationForm(); break;
        case 1: _t->goBackToLogin(); break;
        case 2: _t->openOrphansInfo(); break;
        case 3: _t->openEmployeesInfo(); break;
        case 4: _t->openAdoptionRequests(); break;
        case 5: _t->openManageDonations(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *AdminManageDonations::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminManageDonations::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAdminManageDonationsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AdminManageDonations::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
