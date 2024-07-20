QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    WelcomeWindow.cpp \
    Login.cpp \
    AccountCreationwindow.cpp \
    AdminHomePage.cpp \
    ClickableLabel.cpp \
    UserHomePage.cpp \
    EmployeesInfoWindow.cpp \
    OrphanRegistrationForm.cpp \
    OrphansInfoWindow.cpp \
    AdminManageDonations.cpp \
    Admin_AdoptionRequest.cpp \
    main.cpp

HEADERS += \
    WelcomeWindow.h \
    Login.h \
    AccountCreationWindow.h \
    AdminHomePage.h \
    ClickableLabel.h \
    UserHomePage.h \
    AdminManageDonations.h \
    Admin_AdoptionRequest.h \
    EmployeesInfoWindow.h \
    OrphanRegistrationForm.h \
    OrphansInfoWindow.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resoources.qrc
