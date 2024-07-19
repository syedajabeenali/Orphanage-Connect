#include "AdminHomepage.h"
#include "Login.h"
#include "OrphanRegistrationForm.h"
#include "OrphansInfoWindow.h"
#include "EmployeesInfoWindow.h"
#include "Admin_AdoptionRequest.h"
#include "AdminManageDonations.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

AdminHomepage::AdminHomepage(QWidget *parent) : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    setWindowIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"));

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Header layout
    QHBoxLayout *headerLayout = new QHBoxLayout();

    QLabel *iconLabel = new QLabel(this);
    QPixmap iconPixmap("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png");
    iconLabel->setPixmap(iconPixmap);
    iconLabel->setScaledContents(true);
    iconLabel->setFixedSize(50, 50);
    headerLayout->addWidget(iconLabel);

    QLabel *titleLabel = new QLabel("Orphanage Connect", this);
    titleLabel->setStyleSheet("font-family: 'Arial'; font-size: 40px; color: #333; text-shadow: 2px 2px 2px rgba(0, 0, 0, 0.5);");
    titleLabel->setAlignment(Qt::AlignCenter);
    headerLayout->addWidget(titleLabel);

    QString gradientStyle = "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;";
    titleLabel->setStyleSheet(gradientStyle + "font-family: Arial; font-size: 40px; color: #fff; text-shadow: 2px 2px 2px rgba(0, 0, 0, 0.5);");
    titleLabel->setAlignment(Qt::AlignCenter);

    mainLayout->addLayout(headerLayout);

    // Sidebar layout
    sidebarLayout = new QVBoxLayout();
    sidebarLayout->setSpacing(70);
    sidebarLayout->setAlignment(Qt::AlignTop);

    QWidget *sidebar = new QWidget(this);
    sidebar->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;");
    sidebar->setLayout(sidebarLayout);
    sidebarLayout->setSpacing(70);
    sidebarLayout->setAlignment(Qt::AlignTop);
    sidebar->setFixedWidth(180);
    mainLayout->addWidget(sidebar);

    QPushButton *button1 = createSidebarButton("Orphan Registration","C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Register Orphan menu.png" );
    QPushButton *button2 = createSidebarButton("Registered Orphans", "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Orphans info icon.png");
    QPushButton *button3 = createSidebarButton("Donations","C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Manage Donations Icon.png");
    QPushButton *button4 = createSidebarButton("Adoption Requests","C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Adoption_Icon.png" );
    QPushButton *button5 = createSidebarButton("Employees Data", "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Employees_InfoIcon.png");

    sidebarLayout->addWidget(button1);
    sidebarLayout->addWidget(button2);
    sidebarLayout->addWidget(button3);
    sidebarLayout->addWidget(button4);
    sidebarLayout->addWidget(button5);

    backButton = new QPushButton(this);
    backButton->setIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/IconBackArrow.png"));
    backButton->setIconSize(QSize(24, 24));
    backButton->setFixedSize(40, 40);
    backButton->setCursor(Qt::PointingHandCursor);
    connect(backButton, &QPushButton::clicked, this, &AdminHomepage::goBackToLogin);
    sidebarLayout->addWidget(backButton);

    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    setWindowTitle("Home Page");
    setMinimumSize(800, 650);

    int animationDuration = 3000;
    qreal startOpacity = 0.0;
    qreal endOpacity = 1.0;

    applyAnimation(button1, animationDuration, startOpacity, endOpacity);
    applyAnimation(button2, animationDuration, startOpacity, endOpacity);
    applyAnimation(button3, animationDuration, startOpacity, endOpacity);
    applyAnimation(button4, animationDuration, startOpacity, endOpacity);
    applyAnimation(button5, animationDuration, startOpacity, endOpacity);
}

QPushButton* AdminHomepage::createSidebarButton(const QString &text, const QString &iconPath)
{
    QPushButton *button = new QPushButton(text);
    button->setFixedSize(180, 40);
    button->setStyleSheet("QPushButton {"
                          "background-color: #800000;"
                          "border-radius: 20px;"
                          "border: 2px solid #800000;"
                          "color: white;"
                          "text-align: left;"
                          "padding: 5px 10px;"
                          "margin: 0px;"
                          "}"
                          "QPushButton:hover {"
                          "background-color: #a52a2a;"
                          "border: 2px solid #a52a2a;"
                          "}"
                          "QPushButton:pressed {"
                          "background-color: #800000;"
                          "border: 2px solid #800000;"
                          "}");
    QIcon icon(iconPath);
    button->setIcon(icon);
    button->setIconSize(QSize(24, 24));
    button->setCursor(Qt::PointingHandCursor);

    if (text == "Orphan Registration") {
        connect(button, &QPushButton::clicked, this, &AdminHomepage::openOrphanRegistrationForm);
    } else if (text == "Registered Orphans") {
        connect(button, &QPushButton::clicked, this, &AdminHomepage::openOrphansInfo);
    } else if (text == "Donations") {
        connect(button, &QPushButton::clicked, this, &AdminHomepage::openManageDonations);
    } else if (text == "Adoption Requests") {
        connect(button, &QPushButton::clicked, this, &AdminHomepage::openAdoptionRequests);
    } else if (text == "Employees Data") {
        connect(button, &QPushButton::clicked, this, &AdminHomepage::openEmployeesInfo);
    }

    return button;
}

void AdminHomepage::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}

void AdminHomepage::applyAnimation(QPushButton *button, int duration, qreal startOpacity, qreal endOpacity){
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(button);
    button->setGraphicsEffect(opacityEffect);

    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(duration);
    animation->setStartValue(startOpacity);
    animation->setEndValue(endOpacity);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void AdminHomepage::openOrphanRegistrationForm()
{
       this->close();
    OrphanRegistrationForm *orphanForm = new OrphanRegistrationForm(this);
    orphanForm->show();
}

void AdminHomepage::openOrphansInfo() {
       this->close();
    OrphansInfoWindow *orphansInfoWindow = new OrphansInfoWindow(this);
    orphansInfoWindow->show();
}

void AdminHomepage::openEmployeesInfo() {
       this->close();
    EmployeesInfoWindow *employeesInfoWindow = new EmployeesInfoWindow(this);
    employeesInfoWindow->show();
}

void AdminHomepage::openAdoptionRequests(){
       this->close();
    AdoptionRequest *adoptionRequest = new AdoptionRequest(this);
    adoptionRequest->show();
}

void AdminHomepage::openManageDonations(){
       this->close();
    AdminManageDonations *adminManageDonations = new AdminManageDonations(this);
    adminManageDonations->show();
}
