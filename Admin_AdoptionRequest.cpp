#include "Admin_AdoptionRequest.h"
#include "Login.h"
#include "EmployeesInfoWindow.h"
#include "OrphansInfoWindow.h"
#include "AdminHomePage.h"
#include "OrphanRegistrationForm.h"
#include "AdminManageDonations.h"
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

AdoptionRequest::AdoptionRequest(QWidget *parent)
    : QMainWindow(parent) {

    QWidget *centralWidget = new QWidget(this); // Create a central widget
    setCentralWidget(centralWidget); // Set the central widget for the main window
    // Set background color to white
    centralWidget->setStyleSheet("background-color: white;");

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget); // Create layout for central widget

    // Create sidebar with buttons
    AdoptionRequest::createSidebar(mainLayout);

    // Add space between sidebar and request information
    mainLayout->addSpacing(20); // 3 to 4 lines space

    // Create layout for request information
    QVBoxLayout *requestLayout = new QVBoxLayout();
    mainLayout->addLayout(requestLayout);

    // Add title label
    QLabel *titleLabel = new QLabel("Adoption Requests", centralWidget);
    titleLabel->setStyleSheet("font-weight: bold; font-size: 40px; color: #333;"); // Add styling to the title label
    titleLabel->setAlignment(Qt::AlignCenter);
    requestLayout->addWidget(titleLabel);

    // Load requests from file
    loadRequestsFromFile("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/UserAdoptionFile.txt");

    // Create request widgets
    AdoptionRequest::createRequestWidgets(requestLayout);

    setWindowTitle("Adoption Requests");
    resize(810,650);
}

void AdoptionRequest::createSidebar(QHBoxLayout *mainLayout) {
    QVBoxLayout *sidebarLayout = new QVBoxLayout();

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
    connect(backButton, &QPushButton::clicked, this, &AdoptionRequest::goBackToLogin);
    sidebarLayout->addWidget(backButton);
}

void AdoptionRequest::createRequestWidgets(QVBoxLayout *requestLayout) {
    // Create a layout for each pair of group boxes
    for (int i = 0; i < requestsData.size(); i += 2) {
        QHBoxLayout *pairLayout = new QHBoxLayout();

        // Create group box for the first request in the pair
        QGroupBox *groupBox1 = new QGroupBox("Request Information", this);
        groupBox1->setStyleSheet("QGroupBox { border: 2px solid #800000; border-radius: 10px; background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #E0E0E0, stop:1 #CCCCCC); }");

        QVBoxLayout *groupBoxLayout1 = new QVBoxLayout(groupBox1);

        // Add sublabels and data in vertical layout
        QStringList sublabels1 = {"Adopter Name:", "Child Name:", "Adopter Family Members:",
                                  "Marital Status:", "Income:", "Address:", "House Area:"};
        for (int j = 0; j < requestsData[i].size(); ++j) {
            QLabel *sublabel = new QLabel(sublabels1[j] + " " + requestsData[i][j], groupBox1);
            QFont font = sublabel->font();
            font.setBold(true); // Set the font weight to bold
            sublabel->setFont(font);
            groupBoxLayout1->addWidget(sublabel);
        }

        // Add accept and reject buttons
        QPushButton *acceptButton = new QPushButton("Accept", groupBox1);
        QPushButton *rejectButton = new QPushButton("Reject", groupBox1);
        acceptButton->setStyleSheet("QPushButton { background-color: #8B0000; color: white; border: 1px solid #8B0000; border-radius: 5px; padding: 5px 10px; } QPushButton:hover { background-color: #800000; } QPushButton:pressed { background-color: #6B8E23; }");
        rejectButton->setStyleSheet("QPushButton { background-color: #00008B; color: white; border: 1px solid #00008B; border-radius: 5px; padding: 5px 10px; } QPushButton:hover { background-color: #000080; } QPushButton:pressed { background-color: #6B8E23; }");
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(acceptButton);
        buttonLayout->addWidget(rejectButton);
        groupBoxLayout1->addLayout(buttonLayout);

        pairLayout->addWidget(groupBox1);

        if (i + 1 < requestsData.size()) {
            // Create group box for the second request in the pair
            QGroupBox *groupBox2 = new QGroupBox("Request Information", this);
            groupBox2->setStyleSheet("QGroupBox { border: 2px solid #800000; border-radius: 10px; background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #E0E0E0, stop:1 #CCCCCC); }");

            QVBoxLayout *groupBoxLayout2 = new QVBoxLayout(groupBox2);

            // Add sublabels and data in vertical layout
            QStringList sublabels2 = {"Adopter Name:", "Child Name:", "Adopter Family Members:",
                                      "Marital Status:", "Income:", "Address:", "House Area:"};
            for (int j = 0; j < requestsData[i + 1].size(); ++j) {
                QLabel *sublabel = new QLabel(sublabels2[j] + " " + requestsData[i + 1][j], groupBox2);
                QFont font = sublabel->font();
                font.setBold(true); // Set the font weight to bold
                sublabel->setFont(font);
                groupBoxLayout2->addWidget(sublabel);
            }

            // Add accept and reject buttons
            QPushButton *acceptButton2 = new QPushButton("Accept", groupBox2);
            QPushButton *rejectButton2 = new QPushButton("Reject", groupBox2);
            acceptButton->setStyleSheet("QPushButton { background-color: #8B0000; color: white; border: 1px solid #8B0000; border-radius: 5px; padding: 5px 10px; } QPushButton:hover { background-color: #800000; } QPushButton:pressed { background-color: #6B8E23; }");
            rejectButton->setStyleSheet("QPushButton { background-color: #00008B; color: white; border: 1px solid #00008B; border-radius: 5px; padding: 5px 10px; } QPushButton:hover { background-color: #000080; } QPushButton:pressed { background-color: #6B8E23; }");
            QHBoxLayout *buttonLayout2 = new QHBoxLayout();
            buttonLayout2->addWidget(acceptButton2);
            buttonLayout2->addWidget(rejectButton2);
            groupBoxLayout2->addLayout(buttonLayout2);

            pairLayout->addWidget(groupBox2);

            // Connect accept and reject buttons to slots
            connect(acceptButton2, &QPushButton::clicked, this, &AdoptionRequest::acceptRequest);
            connect(rejectButton2, &QPushButton::clicked, this, &AdoptionRequest::rejectRequest);
        }

        requestLayout->addLayout(pairLayout);

        // Connect accept and reject buttons to slots
        connect(acceptButton, &QPushButton::clicked, this, &AdoptionRequest::acceptRequest);
        connect(rejectButton, &QPushButton::clicked, this, &AdoptionRequest::rejectRequest);
    }
}

void AdoptionRequest::acceptRequest() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QGroupBox *groupBox = qobject_cast<QGroupBox *>(button->parent());
    if (!groupBox) return;

    int index = groupBox->layout()->indexOf(groupBox);

    groupBox->layout()->removeWidget(groupBox);
    groupBox->deleteLater();

    qDebug()<<"Requestdata"<<requestsData;

   //if (index >= 0 && index / 2 < requestsData.size()) { // Check if the index is valid
        QStringList adoptedChildData = requestsData.takeAt(index / 2); // Extract adopted child's data
        QString adoptedChildName = adoptedChildData.value(4); // Assuming the child's name is in the fifth position

        qDebug() << "Adopted child data: " << adoptedChildData;
        qDebug() << "Adopted child name : " << adoptedChildName;

        removeAdoptedChildData(adoptedChildName); // Pass the adoptedChildName as a QString

        updateFile();

        QMessageBox::information(this, "Success", "Request accepted successfully");
    //}
}


void AdoptionRequest::removeAdoptedChildData(const QString &adoptedChildName) {
    QString fileName = "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Registered_Orphans.txt";
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << file.errorString();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (!jsonDoc.isArray()) {
        qDebug() << "Invalid JSON data format.";
        return;
    }

    QJsonArray jsonArray = jsonDoc.array();
    QJsonArray updatedOrphanArray;

    for (int i = 0; i < jsonArray.size(); ++i) {
        QJsonObject orphanObject = jsonArray[i].toObject();
        QString orphanName = orphanObject["Name"].toString();
        if (orphanName == adoptedChildName) {
            continue; // Skip this orphan
        }
        updatedOrphanArray.append(orphanObject);
    }

    QJsonDocument updatedJsonDoc(updatedOrphanArray);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing: " << file.errorString();
        return;
    }

    file.write(updatedJsonDoc.toJson());
    file.close();
}

void AdoptionRequest::rejectRequest() {

    QMessageBox::information(this, "Success", "Rejected Adoption Request");

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QGroupBox *groupBox = qobject_cast<QGroupBox *>(button->parent());
    if (!groupBox) return;

    // Get the index of the group box in the layout
    int index = groupBox->layout()->indexOf(groupBox);

    // Remove the group box from the layout
    groupBox->layout()->removeWidget(groupBox);
    groupBox->deleteLater();

    // Remove the corresponding request from the requestsData list
    if (index >= 0 && index < requestsData.size()) {
        requestsData.removeAt(index / 2);

        // Update the file to remove the rejected request
        updateFile();
    }
}


void AdoptionRequest::loadRequestsFromFile(const QString &fileName) {
    file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << file->errorString();
        return;
    }

    QTextStream in(file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(",");

        if (data.size() != 7) {
            qDebug() << "Invalid data format in file: " << fileName;
            continue;
        }

        requestsData.append(data);

        qDebug() << "Loaded request data:" << data;
    }

    file->close();
}

QPushButton* AdoptionRequest::createSidebarButton(const QString &text, const QString &iconPath)
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
        connect(button, &QPushButton::clicked, this, &AdoptionRequest::openOrphanRegistrationForm);
    } else if (text == "Registered Orphans") {
        connect(button, &QPushButton::clicked, this, &AdoptionRequest::openOrphansInfo);
    } else if (text == "Donations") {
        connect(button, &QPushButton::clicked, this, &AdoptionRequest::openManageDonations);
    } else if (text == "Adoption Requests") {
        connect(button, &QPushButton::clicked, this, &AdoptionRequest::openAdoptionRequests);
    } else if (text == "Employees Data") {
        connect(button, &QPushButton::clicked, this, &AdoptionRequest::openEmployeesInfo);
    }

    return button;
}


void AdoptionRequest::updateFile() {
    // Reopen the file in WriteOnly mode to clear its contents
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing: " << file->errorString();
        return;
    }
    QTextStream out(file);

    // Write the updated requests data to the file
    for (const QStringList &request : requestsData) {
        out << request.join(",") << "\n";
    }

    file->close();
}

void AdoptionRequest::openOrphanRegistrationForm()
{
     this->close();
    // Create an instance of OrphanRegistrationForm with no parent
    OrphanRegistrationForm *orphanForm = new OrphanRegistrationForm(nullptr);
    // Show the OrphanRegistrationForm
    orphanForm->show();
}

void AdoptionRequest::openOrphansInfo() {
     this->close();
    // Create an instance of the OrphansInfoWindow
    OrphansInfoWindow *orphansInfoWindow = new OrphansInfoWindow(this);

    // Show the OrphansInfoWindow
    orphansInfoWindow->show();
}

void AdoptionRequest::openEmployeesInfo() {
     this->close();
    // Create an instance of the EmployeesInfoWindow
    EmployeesInfoWindow *employeesInfoWindow = new EmployeesInfoWindow(this);

    // Show the EmployeesInfoWindow
    employeesInfoWindow->show();
}


void AdoptionRequest::openManageDonations()
{
     this->close();
    // Create an instance of the AdminManageDonations Window
    AdminManageDonations *adminManageDonations = new AdminManageDonations(this);
    adminManageDonations->show();
}

void AdoptionRequest::openAdoptionRequests()
{
    this->close();
    // Create an instance of the AdoptionRequestsWindow
    AdoptionRequest *adoptionRequest = new AdoptionRequest(this);

    // Show the AdoptionRequestsWindow
    adoptionRequest->show();

}

void AdoptionRequest::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}
AdoptionRequest::~AdoptionRequest()
{
}
