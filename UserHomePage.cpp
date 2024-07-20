#include "UserHomePage.h"
#include "Login.h"
#include "User_OrphansInfoWindow.h"
#include "WeeklySportsActivities.h"
#include "UserdonationForm.h"
#include "UserAdoptionForm.h"
#include "NutritionPlan.h"
#include "ContactWindow.h"
#include <QPushButton>
#include <QPalette>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QFont>
#include <QHBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

UserHomePage::UserHomePage(QWidget *parent) : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Header layout
    QHBoxLayout *headerLayout = new QHBoxLayout();

    // Add orphanage icon at the top-left corner
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
    QVBoxLayout *sidebarLayout = new QVBoxLayout();
    sidebarLayout->setSpacing(70);
    sidebarLayout->setAlignment(Qt::AlignTop);

    QWidget *sidebar = new QWidget(this);
    sidebar->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;");
    sidebar->setLayout(sidebarLayout);
    sidebarLayout->setSpacing(70);
    sidebarLayout->setAlignment(Qt::AlignTop);
    sidebar->setFixedWidth(180);
    mainLayout->addWidget(sidebar);

    // Adjust sidebar position
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    QPushButton *button1 = createSidebarButton("Registered Orphans", "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Orphans info icon.png");
    QPushButton *button2 = createSidebarButton("Donate", "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Manage Donations Icon.png");
    QPushButton *button3 = createSidebarButton("Adoption Request", "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Adoption_Icon.png");
    QPushButton *button4 = createSidebarButton("Weekly Sports Activities", "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/WeeklySportIcon.png");
    QPushButton *button5 = createSidebarButton("Contact", "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/ContactIcon.png");

    sidebarLayout->addWidget(button1);
    sidebarLayout->addWidget(button2);
    sidebarLayout->addWidget(button3);
    sidebarLayout->addWidget(button4);
    sidebarLayout->addWidget(button5);

    backButton = new QPushButton(this);
    backButton->setIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/IconBackArrow.png"));
    backButton->setIconSize(QSize(30, 30));
    backButton->setFixedSize(40, 40);
    backButton->setCursor(Qt::PointingHandCursor);
    connect(backButton, &QPushButton::clicked, this, &UserHomePage::goBackToLogin);
    sidebarLayout->addWidget(backButton);

    // Main content area
    QVBoxLayout *contentLayout = new QVBoxLayout();
    mainLayout->addLayout(contentLayout);

    setWindowTitle("Home Page");
    setMinimumSize(810, 650);

    // Animation properties
    int animationDuration = 3000;
    qreal startOpacity = 0.0;
    qreal endOpacity = 1.0;

    // Apply animation to each button
    applyAnimation(button1, animationDuration, startOpacity, endOpacity);
    applyAnimation(button2, animationDuration, startOpacity, endOpacity);
    applyAnimation(button3, animationDuration, startOpacity, endOpacity);
    applyAnimation(button4, animationDuration, startOpacity, endOpacity);
    applyAnimation(button5, animationDuration, startOpacity, endOpacity);
}

void UserHomePage::goBackToLogin()
{
     QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}


QPushButton* UserHomePage::createSidebarButton(const QString &text, const QString &iconPath)
{
    QPushButton *button = new QPushButton(text);
    button->setFixedSize(180, 40);
    button->setStyleSheet("QPushButton {"
                          "background-color: #800000;"
                          "border-radius: 20px;" // Set border-radius for rounded edges
                          "border: 2px solid #800000;" // Set border color
                          "color: white;"
                          "text-align: left;"
                          "padding: 5px 10px;"
                          "margin: 0px;"
                          "}"
                          "QPushButton:hover {"
                          "background-color: #a52a2a;" // Change hover color to #a52a2a (a darker shade of red)
                          "border: 2px solid #a52a2a;" // Change border color on hover
                          "}"
                          "QPushButton:pressed {"
                          "background-color: #800000;" // Change pressed color to #800000
                          "border: 2px solid #800000;" // Change border color on press
                          "}");
    QIcon icon(iconPath);
    button->setIcon(icon);
    button->setIconSize(QSize(24, 24));
    button->setCursor(Qt::PointingHandCursor);

    // Connect the button's clicked signal to the appropriate handler function
    if (text == "Registered Orphans") {
        connect(button, &QPushButton::clicked, this, &UserHomePage::openOrphansInfo);
    } else if (text == "Donate") {
        connect(button, &QPushButton::clicked, this, &UserHomePage::openDonationForm);
    } else if (text == "Adoption Request") {
        connect(button, &QPushButton::clicked, this, &UserHomePage::openAdoptionForm);
    } else if (text == "Weekly Sports Activities") {
        connect(button, &QPushButton::clicked, this, &UserHomePage::openWeeklySportsActivities);
    } else if (text == "Contact") {
        connect(button, &QPushButton::clicked, this, &UserHomePage::openContact);
    }

    // Apply animation to the button
    applyAnimation(button, 1000, 0.0, 1.0);

    return button;
}

void UserHomePage::applyAnimation(QPushButton *button, int duration, qreal startOpacity, qreal endOpacity){
    // Create opacity effect for the button
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(button);
    button->setGraphicsEffect(opacityEffect);

    // Create animation for the opacity effect
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(duration);
    animation->setStartValue(startOpacity);
    animation->setEndValue(endOpacity);

    // Set easing curve (optional)
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    // Start the animation
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void UserHomePage::openOrphansInfo() {

     this->close();
    // Create an instance of the OrphansInfoWindow
    User_OrphansInfoWindow *user_OrphansInfoWindow = new User_OrphansInfoWindow(this);
    user_OrphansInfoWindow->show();
}

void UserHomePage::openDonationForm()
{
    this->close();
    // Create an instance of the DonationForm
    UserDonationForm *userDonationForm = new UserDonationForm(this);
    userDonationForm->show();
}

void UserHomePage::openAdoptionForm()
{
     this->close();
    // Create an instance of the UserAdoptionForm
    UserAdoptionForm *userAdoptionForm = new UserAdoptionForm(this);
    userAdoptionForm->show();

}

void UserHomePage::openWeeklySportsActivities()
{
     this->close();
    // Create an instance of the SportsActivitiesWindow
    WeeklySportsActivities *weeklySportsActivities = new WeeklySportsActivities(this);
    weeklySportsActivities->show();
}


void UserHomePage::openContact()
{
     this->close();
    // Create an instance of the ContactWindow
    ContactWindow *contactWindow = new ContactWindow(this);
    contactWindow->show();
}
