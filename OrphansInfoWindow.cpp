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
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

OrphansInfoWindow::OrphansInfoWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Orphans Information title
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
    connect(backButton, &QPushButton::clicked, this, &OrphansInfoWindow::goBackToLogin);
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
    readJsonDataFromFile("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Registered_Orphans.txt", orphanLayout);

    setWindowTitle("Registered Orphans");
    resize(810, 650);
}

void OrphansInfoWindow::readJsonDataFromFile(const QString& filePath, QVBoxLayout* mainLayout)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file" << filePath;
        return;
    }

    QTextStream in(&file);
    QString jsonData = in.readAll(); // Read the entire file content as a single string
    file.close();

    displayOrphanInfo(jsonData, mainLayout);
}

QPushButton* OrphansInfoWindow::createSidebarButton(const QString &text, const QString &iconPath)
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
    if (text == "Orphan Registration") {
        connect(button, &QPushButton::clicked, this, &OrphansInfoWindow::openOrphanRegistrationForm);
    } else if (text == "Registered Orphans") {
        connect(button, &QPushButton::clicked, this, &OrphansInfoWindow::openOrphansInfo);
    } else if (text == "Donations") {
        connect(button, &QPushButton::clicked, this, &OrphansInfoWindow::openManageDonations);
    } else if (text == "Adoption Requests") {
        connect(button, &QPushButton::clicked, this, &OrphansInfoWindow::openAdoptionRequests);
    } else if (text == "Employees Data") {
        connect(button, &QPushButton::clicked, this, &OrphansInfoWindow::openEmployeesInfo);
    }

    return button;
}
void OrphansInfoWindow::displayOrphanInfo(const QString& jsonData, QVBoxLayout* mainLayout)
{
    QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
    if(doc.isNull()) {
        qDebug() << "Failed to parse JSON data:" << jsonData;
        return;
    }

    if (!doc.isArray()) {
        qDebug() << "JSON data is not an array.";
        return;
    }

    QJsonArray jsonArray = doc.array();
    for (int i = 0; i < jsonArray.size(); ++i) {
        QJsonValue value = jsonArray.at(i);
        if (!value.isObject()) {
            qDebug() << "Invalid JSON data format.";
            continue;
        }

        QJsonObject orphanObject = value.toObject();

        QString name = orphanObject["Name"].toString();
        int age = orphanObject["Age"].toInt();
        QString gender = orphanObject["Gender"].toString();
        QString dateOfBirth = orphanObject["DateOfBirth"].toString();
        QString knownAllergies = orphanObject["KnownAllergies"].toString();
        QString medicalConditions = orphanObject["MedicalConditions"].toString();
        QString relationshipStatus = orphanObject["RelationshipStatus"].toString();
        QString contactNumber = orphanObject["ContactNumber"].toString();
        QString additionalComments = orphanObject["AdditionalComments"].toString();
        QString imagePath = orphanObject["ImagePath"].toString();

        // Create widgets and add them to layout for each orphan
        QWidget *infoWidget = new QWidget();
        QHBoxLayout *infoLayout = new QHBoxLayout(infoWidget);
        infoWidget->setLayout(infoLayout);
        infoWidget->setFixedSize(650,380); // Set maximum width as required
        infoWidget->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #c0c0c0, stop:1 #a0a0a0);"
                                  "padding: 7px;"
                                  "margin-bottom: 7px;"
                                  "border: 1px solid #ccc;"
                                  "border-radius: 5px;");

        QLabel *imageLabel = new QLabel(this);
        QPixmap pixmap(imagePath);
        imageLabel->setPixmap(pixmap.scaled(300, 300));
        imageLabel->setAlignment(Qt::AlignCenter);
        infoLayout->addWidget(imageLabel);

        QVBoxLayout *textLayout = new QVBoxLayout();
        QLabel *nameLabel = new QLabel("Name: " + name);
        QLabel *ageLabel = new QLabel("Age: " + QString::number(age));
        QLabel *genderLabel = new QLabel("Gender: " + gender);
        QLabel *dobLabel = new QLabel("Date of Birth: " + dateOfBirth);
        QLabel *allergiesLabel = new QLabel("Known Allergies: " + knownAllergies);
        QLabel *conditionsLabel = new QLabel("Medical Conditions: " + medicalConditions);
        QLabel *relationshipLabel = new QLabel("Relationship Status: " + relationshipStatus);
        QLabel *contactLabel = new QLabel("Contact Number: " + contactNumber);
        QLabel *commentsLabel = new QLabel("Additional Comments: " + additionalComments);

        QFont font;
        font.setPointSize(10);
        nameLabel->setFont(font);
        ageLabel->setFont(font);
        genderLabel->setFont(font);
        dobLabel->setFont(font);
        allergiesLabel->setFont(font);
        conditionsLabel->setFont(font);
        relationshipLabel->setFont(font);
        contactLabel->setFont(font);
        commentsLabel->setFont(font);

        textLayout->addWidget(nameLabel);
        textLayout->addWidget(ageLabel);
        textLayout->addWidget(genderLabel);
        textLayout->addWidget(dobLabel);
        textLayout->addWidget(allergiesLabel);
        textLayout->addWidget(conditionsLabel);
        textLayout->addWidget(relationshipLabel);
        textLayout->addWidget(contactLabel);
        textLayout->addWidget(commentsLabel);

        infoLayout->addLayout(textLayout);

        mainLayout->addWidget(infoWidget); // Add the infoWidget to the main layout
    }
}


void OrphansInfoWindow::openOrphanRegistrationForm()
{
    this->close();
    // Create an instance of OrphanRegistrationForm with no parent
    OrphanRegistrationForm *orphanForm = new OrphanRegistrationForm(nullptr);
    orphanForm->show();
}

void OrphansInfoWindow::openOrphansInfo() {

    this->close();
    // Create an instance of the OrphansInfoWindow
    OrphansInfoWindow *orphansInfoWindow = new OrphansInfoWindow(this);
    orphansInfoWindow->show();
}

void OrphansInfoWindow::openEmployeesInfo() {

    this->close();
    // Create an instance of the EmployeesInfoWindow
    EmployeesInfoWindow *employeesInfoWindow = new EmployeesInfoWindow(this);
    employeesInfoWindow->show();
}

void OrphansInfoWindow::openManageDonations()
{

    this->close();
    // Create an instance of the AdminManageDonations Window
    AdminManageDonations *adminManageDonations = new AdminManageDonations(this);
    adminManageDonations->show();
}

void OrphansInfoWindow::openAdoptionRequests()
{

    this->close();
    // Create an instance of the AdoptionRequestsWindow
    AdoptionRequest *adoptionRequest = new AdoptionRequest(this);
    adoptionRequest->show();
}

void OrphansInfoWindow::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}


OrphansInfoWindow::~OrphansInfoWindow()
{
}
