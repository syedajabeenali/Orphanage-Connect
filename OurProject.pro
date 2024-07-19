QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AccountCreationwindow.cpp \
    AdminHomePage.cpp \
    AdminManageDonations.cpp \
    Admin_AdoptionRequest.cpp \
    ClickableLabel.cpp \
    ContactWindow.cpp \
    EmployeesInfoWindow.cpp \
    Login.cpp \
    OrphanRegistrationForm.cpp \
    OrphansInfoWindow.cpp \
    UserAdoptionForm.cpp \
    UserDonationForm.cpp \
    UserHomePage.cpp \
    User_OrphansInfoWindow.cpp \
    WeeklySportsActivities.cpp \
    WelcomeWindow.cpp \
    main.cpp

HEADERS += \
    AccountCreationWindow.h \
    AdminHomePage.h \
    AdminManageDonations.h \
    Admin_AdoptionRequest.h \
    ClickableLabel.h \
    ContactWindow.h \
    EmployeesInfoWindow.h \
    Login.h \
    OrphanRegistrationForm.h \
    OrphansInfoWindow.h \
    UserAdoptionForm.h \
    UserHomePage.h \
    User_OrphansInfoWindow.h \
    UserdonationForm.h \
    WeeklySportsActivities.h \
    WelcomeWindow.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resoources.qrc
