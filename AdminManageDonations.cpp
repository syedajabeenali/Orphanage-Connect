#include "AdminManageDonations.h"
#include "AdminHomepage.h"
#include "Login.h"
#include "OrphanRegistrationForm.h"
#include "OrphansInfoWindow.h"
#include "EmployeesInfoWindow.h"
#include "Admin_AdoptionRequest.h"
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHBoxLayout>

AdminManageDonations::AdminManageDonations(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create main layout for the central widget
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Create sidebar layout
    QVBoxLayout *sidebarLayout = new QVBoxLayout();
    sidebarLayout->setSpacing(50);
    sidebarLayout->setAlignment(Qt::AlignTop);

    centralWidget->setStyleSheet("background-color: #f0f0f0;");

    QWidget *sidebar = new QWidget(this);
    sidebar->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;");
    sidebar->setLayout(sidebarLayout);
    sidebar->setFixedWidth(180);
    mainLayout->addWidget(sidebar);

    // Add icon to sidebar
    QLabel *iconLabel = new QLabel;
    QPixmap orphanageIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"); // Provide the path to your orphanage icon
    iconLabel->setPixmap(orphanageIcon);
    iconLabel->setScaledContents(true); // Scale the image to fit the QLabel
    iconLabel->setFixedSize(50, 50); // Set the size of the QLabel
    iconLabel->move(0,0);
    sidebarLayout->addWidget(iconLabel);

    // Add buttons to the sidebar
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

    // Add the back button to the sidebar
    backButton = new QPushButton(this);
    backButton->setIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/IconBackArrow.png"));
    backButton->setIconSize(QSize(24, 24));
    backButton->setFixedSize(40, 40);
    backButton->setCursor(Qt::PointingHandCursor);
    connect(backButton, &QPushButton::clicked, this, &AdminManageDonations::goBackToLogin);
    sidebarLayout->addWidget(backButton);

    // Create content layout
    QVBoxLayout *contentLayout = new QVBoxLayout();
    contentLayout->setAlignment(Qt::AlignTop);

    // Add content widgets to the content layout
    QLabel *donationsHeading = new QLabel("Donations", this);
    donationsHeading->setStyleSheet("font-size: 30pt; font-weight: bold; color: black;");
    contentLayout->addWidget(donationsHeading, 0, Qt::AlignCenter);

    // Add sub-heading: "Your Donations Matter"
    QLabel *donationsSubheading = new QLabel("Your Donations Matter", this);
    donationsSubheading->setStyleSheet("font-size: 9pt; font-weight: bold; color: black;");
    contentLayout->addWidget(donationsSubheading, 0, Qt::AlignCenter);

    // Add labels for donor info and spending details
    QLabel *donorInfoLabel = new QLabel("Donor Detail", this);
    donorInfoLabel->setStyleSheet("font-size: 18pt; font-weight: bold; color: black;");
    contentLayout->addWidget(donorInfoLabel);

    // Read and display donor details
    displayDonorDetails(contentLayout);

    QLabel *spendingLabel = new QLabel("Spending Details", this);
    spendingLabel->setStyleSheet("font-size: 18pt; font-weight: bold; color: black;");
    contentLayout->addWidget(spendingLabel);

    // Read and display expenditure details
    displayExpenditureDetails(contentLayout);

    // Set the content layout as the second part of the main layout
    mainLayout->addLayout(contentLayout);

    setWindowTitle("Orphan Registration Form");
    resize(810, 650);
}

void AdminManageDonations::goBackToLogin() {
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}

AdminManageDonations::~AdminManageDonations() {}

void AdminManageDonations::displayExpenditureDetails(QVBoxLayout *contentLayout) {
    // Read the expenditure details and picture path from the file
    QString picturePath;
    QStringList expenditureDetails;
    QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/ExpenditureDetails.txt"); // Provide the path to your text file
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()) {
                if (line.startsWith("C:\\") || line.startsWith("D:\\") || line.startsWith("E:\\")) {
                    picturePath = line;
                } else {
                    expenditureDetails.append(line);
                }
            }
        }
        file.close();
    }

    // Create a layout for the expenditure details
    QVBoxLayout *detailsLayout = new QVBoxLayout();
    detailsLayout->setAlignment(Qt::AlignTop);

    // Display expenditure details
    for (const QString &detail : expenditureDetails) {
        QLabel *detailLabel = new QLabel(detail, this);
        detailLabel->setStyleSheet("font-weight: bold; color: black;");
        detailsLayout->addWidget(detailLabel);
    }

    // Create a group box for expenditures and picture
    QGroupBox *expenditureGroupBox = new QGroupBox("", this);
    QHBoxLayout *expenditureLayout = new QHBoxLayout(expenditureGroupBox);

    // Add the details layout to the expenditure layout
    expenditureLayout->addLayout(detailsLayout);

    // Create a label for the picture
    QLabel *pictureLabel = new QLabel(this);
    QPixmap picture(picturePath);
    pictureLabel->setPixmap(picture.scaledToWidth(200));
    pictureLabel->setScaledContents(true);

    // Add the picture label to the expenditure layout
    expenditureLayout->addWidget(pictureLabel);

    // Set the style sheet for the expenditure group box
    expenditureGroupBox->setStyleSheet("QGroupBox { border: 2px solid blue; background-color: #f0f0f0; }");

    // Add the group box to the content layout
    contentLayout->addWidget(expenditureGroupBox);
}


void AdminManageDonations::displayDonorDetails(QVBoxLayout *contentLayout) {
    // Read donor details and display
    QFile donorFile(R"(C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/UserDonations.txt)");
    if (donorFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&donorFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            displayDonor(line, contentLayout);
        }
        donorFile.close();
    }
}

void AdminManageDonations::displayDonor(const QString &donorInfo, QVBoxLayout *contentLayout) {
    // Create a new group box for each donor
    QGroupBox *donorGroupBox = new QGroupBox("Donor Information", this);
    QVBoxLayout *donorLayout = new QVBoxLayout(donorGroupBox);

    // Add a space before printing donor information
    donorLayout->addSpacing(14);

    // Split donor information
    QStringList details = donorInfo.split(",");
    for (int i = 0; i < details.size(); ++i) {
        details[i] = details[i].trimmed(); // Remove leading and trailing whitespace
    }

    // Create a horizontal layout for each donor's details
    QHBoxLayout *detailLayout = new QHBoxLayout();

    // Create labels for name, email, amount, and donation method
    QLabel *nameLabel = new QLabel("Name: " + details.value(0), this);
    nameLabel->setStyleSheet("font-weight: bold; color: black;"); // Text color is black and bold
    QLabel *emailLabel = new QLabel("Email: " + details.value(1), this);
    emailLabel->setStyleSheet("font-weight: bold; color: black;"); // Text color is black and bold
    QLabel *amountLabel = new QLabel("Amount: " + details.value(2), this);
    amountLabel->setStyleSheet("font-weight: bold; color: black;"); // Text color is black and bold
    QLabel *donationMethodLabel = new QLabel("Donation Method: " + details.value(3), this);
    donationMethodLabel->setStyleSheet("font-weight: bold; color: black;"); // Text color is black and bold

    // Add labels to the horizontal layout
    detailLayout->addWidget(nameLabel);
    detailLayout->addWidget(emailLabel);
    detailLayout->addWidget(amountLabel);
    detailLayout->addWidget(donationMethodLabel);

    // Add the horizontal layout to the vertical layout of the donor group box
    donorLayout->addLayout(detailLayout);

    // Set the style sheet for the donor group box
    donorGroupBox->setStyleSheet("QGroupBox { border: 2px solid red; margin: 10px; }"); // Red boundary color

    // Set maximum width for the donor group box
    // donorGroupBox->setFixedSize(650,100);

    // Add the donor group box to the content layout
    contentLayout->addWidget(donorGroupBox);
}


QPushButton* AdminManageDonations::createSidebarButton(const QString &text, const QString &iconPath) {
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
        connect(button, &QPushButton::clicked, this, &AdminManageDonations::openOrphanRegistrationForm);
    } else if (text == "Registered Orphans") {
        connect(button, &QPushButton::clicked, this, &AdminManageDonations::openOrphansInfo);
    } else if (text == "Donations") {
        connect(button, &QPushButton::clicked, this, &AdminManageDonations::openManageDonations);
    } else if (text == "Adoption Requests") {
        connect(button, &QPushButton::clicked, this, &AdminManageDonations::openAdoptionRequests);
    } else if (text == "Employees Data") {
        connect(button, &QPushButton::clicked, this, &AdminManageDonations::openEmployeesInfo);
    }

    return button;
}

void AdminManageDonations::openOrphanRegistrationForm() {
    this->close();
    OrphanRegistrationForm *orphanForm = new OrphanRegistrationForm(this);
    orphanForm->show();
}

void AdminManageDonations::openOrphansInfo() {
    this->close();
    OrphansInfoWindow *orphansInfoWindow = new OrphansInfoWindow(this);
    orphansInfoWindow->show();
}

void AdminManageDonations::openEmployeesInfo() {
    this->close();
    EmployeesInfoWindow *employeesInfoWindow = new EmployeesInfoWindow(this);
    employeesInfoWindow->show();
}

void AdminManageDonations::openAdoptionRequests() {
    this->close();
    AdoptionRequest *adoptionRequest = new AdoptionRequest(this);
    adoptionRequest->show();
}

void AdminManageDonations::openManageDonations() {
    this->close();
    AdminManageDonations *adminManageDonations = new AdminManageDonations(this);
    adminManageDonations->show();
}


