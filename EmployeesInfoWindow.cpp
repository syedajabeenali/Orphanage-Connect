#include "OrphansInfoWindow.h"
#include "Login.h"
#include "OrphanRegistrationForm.h"
#include "EmployeesInfoWindow.h"
#include "AdminHomePage.h"
#include "Admin_AdoptionRequest.h"
#include "AdminManageDonations.h"
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

EmployeesInfoWindow::EmployeesInfoWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Employees Information title
    QLabel *titleLabel = new QLabel("Orphans Information", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20); // Increase font size to 20 points
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->move(10, 10); // Adjust the position of the title label

    // Central widget layout
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget); // Use QHBoxLayout for main layout
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Sidebar layout
    QVBoxLayout *sidebarLayout = new QVBoxLayout(); // Sidebar layout

    // Sidebar layout
    QWidget *sidebar = new QWidget(this);
    sidebar->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;");
    sidebar->setLayout(sidebarLayout);
    sidebarLayout->setSpacing(60); // Set spacing between buttons
    sidebarLayout->setAlignment(Qt::AlignTop); // Align buttons to the top
    sidebar->setFixedWidth(180); // Fixed width for the sidebar
    mainLayout->addWidget(sidebar); // Add sidebar to the main layout

    // Add icon to sidebar
    QLabel *iconLabel = new QLabel;
    QPixmap orphanageIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"); // Provide the path to your orphanage icon
    iconLabel->setPixmap(orphanageIcon);
    iconLabel->setScaledContents(true); // Scale the image to fit the QLabel
    iconLabel->setFixedSize(50, 50); // Set the size of the QLabel
    iconLabel->move(0,0);
    sidebarLayout->addWidget(iconLabel);

    // Create sidebar buttons
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
    connect(backButton, &QPushButton::clicked, this, &EmployeesInfoWindow::goBackToLogin);
    sidebarLayout->addWidget(backButton);


    // Orphan information scroll area
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *orphanWidget = new QWidget(this);
    QVBoxLayout *orphanLayout = new QVBoxLayout(orphanWidget); // Use QVBoxLayout for orphan layout
    orphanWidget->setLayout(orphanLayout);
    scrollArea->setWidget(orphanWidget);
    scrollArea->setWidgetResizable(true);
    mainLayout->addWidget(scrollArea);

    // Read orphan data from file
    QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/employee_data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        displayEmployeeInfo(line, orphanLayout);
    }

    file.close();

    setWindowTitle("Employees Data");
    resize(810, 650);
}

QPushButton* EmployeesInfoWindow::createSidebarButton(const QString &text, const QString &iconPath)
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

    if (text == "Orphan Registration") {
        connect(button, &QPushButton::clicked, this, &EmployeesInfoWindow::openOrphanRegistrationForm);
    } else if (text == "Registered Orphans") {
        connect(button, &QPushButton::clicked, this, &EmployeesInfoWindow::openOrphansInfo);
    } else if (text == "Donations") {
        connect(button, &QPushButton::clicked, this, &EmployeesInfoWindow::openManageDonations);
    } else if (text == "Adoption Requests") {
        connect(button, &QPushButton::clicked, this, &EmployeesInfoWindow::openAdoptionRequests);
    } else if (text == "Employees Data") {
        connect(button, &QPushButton::clicked, this, &EmployeesInfoWindow::openEmployeesInfo);
    }


    return button;
}

void EmployeesInfoWindow::displayEmployeeInfo(const QString& data, QVBoxLayout* mainLayout)
{
    QStringList orphanData = data.split(",");
    if (orphanData.size() != 7) {
        qDebug() << "Invalid data format:" << data;
        return;
    }

    QWidget *infoWidget = new QWidget();
    QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);
    infoWidget->setLayout(infoLayout);
    infoWidget->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #c0c0c0, stop:1 #a0a0a0);"
                              "padding: 7px;"
                              "margin-bottom: 7px;"
                              "border: 1px solid #ccc;"
                              "border-radius: 5px;");



    QLabel *imageLabel = new QLabel(this);
    QPixmap pixmap(orphanData.at(6));
    imageLabel->setPixmap(pixmap.scaled(250, 250));
    imageLabel->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(imageLabel);

    QVBoxLayout *textLayout = new QVBoxLayout();
    QLabel *nameLabel = new QLabel("Name: " + orphanData.at(0));
    QLabel *ageLabel = new QLabel("Age: " + orphanData.at(1));
    QLabel *genderLabel = new QLabel("Gender: " + orphanData.at(2));
    QLabel *addressLabel = new QLabel("Address: " + orphanData.at(3));
    QLabel *guardianLabel = new QLabel("Guardian: " + orphanData.at(4));
    QLabel *statusLabel = new QLabel("Status: " + orphanData.at(5));

    QFont font;
    font.setPointSize(8);
    nameLabel->setFont(font);
    ageLabel->setFont(font);
    genderLabel->setFont(font);
    addressLabel->setFont(font);
    guardianLabel->setFont(font);
    statusLabel->setFont(font);

    textLayout->addWidget(nameLabel);
    textLayout->addWidget(ageLabel);
    textLayout->addWidget(genderLabel);
    textLayout->addWidget(addressLabel);
    textLayout->addWidget(guardianLabel);
    textLayout->addWidget(statusLabel);

    infoLayout->addLayout(textLayout);

    mainLayout->addWidget(infoWidget); // Add the infoWidget to the main layout
}

void EmployeesInfoWindow::openOrphanRegistrationForm()
{
     this->close();
    // Create an instance of OrphanRegistrationForm with no parent
    OrphanRegistrationForm *orphanForm = new OrphanRegistrationForm(nullptr);
    orphanForm->show();
}

void EmployeesInfoWindow::openOrphansInfo() {
     this->close();
    // Create an instance of the OrphansInfoWindow
    OrphansInfoWindow *orphansInfoWindow = new OrphansInfoWindow(this);
    orphansInfoWindow->show();
}

void EmployeesInfoWindow::openEmployeesInfo() {
     this->close();
    // Create an instance of the EmployeesInfoWindow
    EmployeesInfoWindow *employeesInfoWindow = new EmployeesInfoWindow(this);
    employeesInfoWindow->show();
}

void EmployeesInfoWindow::openManageDonations()
{
     this->close();
    // Create an instance of the AdminManageDonations Window
    AdminManageDonations *adminManageDonations = new AdminManageDonations(this);
    adminManageDonations->show();
}

void EmployeesInfoWindow::openAdoptionRequests()
{
    this->close();
    // Create an instance of the AdoptionRequestsWindow
    AdoptionRequest *adoptionRequest = new AdoptionRequest(this);
    adoptionRequest->show();
}

void EmployeesInfoWindow::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}

EmployeesInfoWindow::~EmployeesInfoWindow()
{
}
