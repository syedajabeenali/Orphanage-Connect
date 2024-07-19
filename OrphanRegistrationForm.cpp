#include "OrphanRegistrationForm.h"
#include "OrphansInfoWindow.h"
#include "EmployeesInfoWindow.h"
#include "AdminHomePage.h"
#include "Login.h"
#include "Admin_AdoptionRequest.h"
#include "AdminManageDonations.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QDateEdit>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

OrphanRegistrationForm::OrphanRegistrationForm(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(810, 650);
    setWindowTitle("Orphan Registration Form");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Set background color to white
   // centralWidget->setStyleSheet("background-color: white;");
    setWindowIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"));

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget); // Use QHBoxLayout for main layout

    // Sidebar
    QVBoxLayout *sidebarLayout = new QVBoxLayout(); // Sidebar layout

    // Sidebar layout
    QWidget *sidebar = new QWidget(this);
    sidebar->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;");
    sidebar->setLayout(sidebarLayout);
    sidebarLayout->setSpacing(70); // Set spacing between buttons
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
    connect(backButton, &QPushButton::clicked, this, &OrphanRegistrationForm::goBackToLogin);
    sidebarLayout->addWidget(backButton);

    mainLayout->addWidget(sidebar); // Add sidebar to mainLayout

    // Form layout
    QVBoxLayout *formLayout = new QVBoxLayout(); // Layout for the form elements

    // Add bold text label
    QLabel *titleLabel = new QLabel("Orphan Registration Form");
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20); // Increase font size to 20 points
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    formLayout->addWidget(titleLabel);

    // Name
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QLabel *nameLabel = new QLabel("Orphan's Name:");
    nameLineEdit = new QLineEdit;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameLineEdit);
    formLayout->addLayout(nameLayout);

    // Age, Gender, Date of Birth
    QHBoxLayout *infoLayout = new QHBoxLayout;
    QLabel *ageLabel = new QLabel("Age:");
    ageSpinBox = new QSpinBox;
    ageSpinBox->setRange(0, 150);
    infoLayout->addWidget(ageLabel);
    infoLayout->addWidget(ageSpinBox);

    QLabel *genderLabel = new QLabel("Gender:");
    genderComboBox = new QComboBox;
    genderComboBox->addItem("Male");
    genderComboBox->addItem("Female");
    genderComboBox->addItem("Other");
    infoLayout->addWidget(genderLabel);
    infoLayout->addWidget(genderComboBox);

    QLabel *dobLabel = new QLabel("Date of Birth:");
    dobDateEdit = new QDateEdit;
    dobDateEdit->setDisplayFormat("dd/MM/yyyy");
    infoLayout->addWidget(dobLabel);
    infoLayout->addWidget(dobDateEdit);

    formLayout->addLayout(infoLayout);

    // Known Allergies
    QHBoxLayout *allergiesLayout = new QHBoxLayout;
    QLabel *allergiesLabel = new QLabel("Known Allergies:");
    allergiesLineEdit = new QLineEdit;
    allergiesLayout->addWidget(allergiesLabel);
    allergiesLayout->addWidget(allergiesLineEdit);
    formLayout->addLayout(allergiesLayout);

    // Medical Conditions
    QHBoxLayout *conditionsLayout = new QHBoxLayout;
    QLabel *conditionsLabel = new QLabel("Medical Conditions:");
    conditionsLineEdit = new QLineEdit;
    conditionsLayout->addWidget(conditionsLabel);
    conditionsLayout->addWidget(conditionsLineEdit);
    formLayout->addLayout(conditionsLayout);

    // Relationship
    QHBoxLayout *relationshipLayout = new QHBoxLayout;
    QLabel *relationshipLabel = new QLabel("Relationship Status:");
    relationshipLineEdit = new QLineEdit;
    relationshipLayout->addWidget(relationshipLabel);
    relationshipLayout->addWidget(relationshipLineEdit);
    formLayout->addLayout(relationshipLayout);

    // Contact Number
    QHBoxLayout *contactLayout = new QHBoxLayout;
    QLabel *contactLabel = new QLabel("Contact Number:");
    contactLineEdit = new QLineEdit;
    contactLayout->addWidget(contactLabel);
    contactLayout->addWidget(contactLineEdit);
    formLayout->addLayout(contactLayout);

    // Additional Comments
    QLabel *commentsLabel = new QLabel("Additional Comments:");
    commentsPlainTextEdit = new QPlainTextEdit;
    formLayout->addWidget(commentsLabel);
    formLayout->addWidget(commentsPlainTextEdit);

    // Select Image Button
    selectImageButton = new QPushButton("Select Image", this);
    // //selectImageButton ->setStyleSheet("QPushButton {"
    //                             "background-color: #800000;"
    //                             "border-radius: 20px;" // Set border-radius for rounded edges
    //                             "border: 2px solid #800000;" // Set border color
    //                             "color: white;"
    //                             "text-align: left;"
    //                             "padding: 5px 10px;"
    //                             "margin: 0px;"
    //                             "}"
    //                             "QPushButton:hover {"
    //                             "background-color: #a52a2a;" // Change hover color to #a52a2a (a darker shade of red)
    //                             "border: 2px solid #a52a2a;" // Change border color on hover
    //                             "}"
    //                             "QPushButton:pressed {"
    //                             "background-color: #800000;" // Change pressed color to #800000
    //                             "border: 2px solid #800000;" // Change border color on press
    //                             "}");
    selectImageButton->setFixedSize(180, 40);
    connect(selectImageButton, &QPushButton::clicked, this, &OrphanRegistrationForm::selectImage);
    formLayout->addWidget(selectImageButton);

    // Submit Button
    submitButton = new QPushButton("Submit");
    submitButton->setStyleSheet("QPushButton {"
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
    formLayout->addWidget(submitButton);


    mainLayout->addLayout(formLayout); // Add formLayout to mainLayout

    // Connect Submit Button
    connect(submitButton, &QPushButton::clicked, this, &OrphanRegistrationForm::submitButtonClicked);
}


void OrphanRegistrationForm::submitButtonClicked()
{
        // Validate orphan's name
        QString orphanName = nameLineEdit->text();
        QRegularExpression nameRegex("^[a-zA-Z\\s]*$");
        if (!nameRegex.match(orphanName).hasMatch())
        {
            QMessageBox::critical(this, "Error", "Orphan's name cannot contain digits or special characters.");
            return;
        }

        // Validate known allergies
        QString allergies = allergiesLineEdit->text();
        if (!allergies.isEmpty() && !nameRegex.match(allergies).hasMatch())
        {
            QMessageBox::critical(this, "Error", "Known allergies cannot contain digits or special characters.");
            return;
        }

        // Validate medical conditions
        QString medicalConditions = conditionsLineEdit->text();
        if (!medicalConditions.isEmpty() && !nameRegex.match(medicalConditions).hasMatch())
        {
            QMessageBox::critical(this, "Error", "Medical conditions cannot contain digits or special characters.");
            return;
        }

        // Validate contact number
        QString contactNumber = contactLineEdit->text();
        QRegularExpression phoneRegex("^\\d{11}$"); // 11 digits only
        if (!phoneRegex.match(contactNumber).hasMatch())
        {
            QMessageBox::critical(this, "Error", "Invalid phone number. Please enter a valid 11-digit phone number.");
            return;
        }


    // Create a JSON object for the new orphan
    QJsonObject orphanObject;
    orphanObject["Name"] = nameLineEdit->text();
    orphanObject["Age"] = ageSpinBox->value();
    orphanObject["Gender"] = genderComboBox->currentText();
    orphanObject["DateOfBirth"] = dobDateEdit->date().toString("dd/MM/yyyy");
    orphanObject["KnownAllergies"] = allergiesLineEdit->text();
    orphanObject["MedicalConditions"] = conditionsLineEdit->text();
    orphanObject["RelationshipStatus"] = relationshipLineEdit->text();
    orphanObject["ContactNumber"] = contactLineEdit->text();
    orphanObject["ImagePath"] = selectedImagePath;
    orphanObject["AdditionalComments"] = commentsPlainTextEdit->toPlainText();
   // orphanObject["ImagePath"] = ""; // Set image path if needed

    // Read existing data from file
    QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Registered_Orphans.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Could not open file for reading.");
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    // Convert existing data to JSON array
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if(!doc.isArray()) {
        QMessageBox::critical(this, "Error", "Invalid JSON data in the file.");
        return;
    }

    QJsonArray jsonArray = doc.array();

    // Append new orphan object to the array
    jsonArray.append(orphanObject);

    // Write updated data back to the file
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Could not open file for writing.");
        return;
    }

    doc = QJsonDocument(jsonArray);
    file.write(doc.toJson());
    file.close();

    QMessageBox::information(this, "Success", "Data submitted successfully!");
}

QPushButton* OrphanRegistrationForm::createSidebarButton(const QString &text, const QString &iconPath)
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
        connect(button, &QPushButton::clicked, this, &OrphanRegistrationForm::openOrphanRegistrationForm);
    } else if (text == "Registered Orphans") {
        connect(button, &QPushButton::clicked, this, &OrphanRegistrationForm::openOrphansInfo);
    } else if (text == "Donations") {
        connect(button, &QPushButton::clicked, this, &OrphanRegistrationForm::openManageDonations);
    } else if (text == "Adoption Requests") {
        connect(button, &QPushButton::clicked, this, &OrphanRegistrationForm::openAdoptionRequests);
    } else if (text == "Employees Data") {
        connect(button, &QPushButton::clicked, this, &OrphanRegistrationForm::openEmployeesInfo);
    }

    return button;
}

void OrphanRegistrationForm::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}

void OrphanRegistrationForm::openOrphanRegistrationForm()
{     this->close();
    OrphanRegistrationForm *orphanForm = new OrphanRegistrationForm(this);
    // Show the OrphanRegistrationForm
    orphanForm->show();
}

void OrphanRegistrationForm::openOrphansInfo() {
         this->close();
    // Create an instance of the OrphansInfoWindow
    OrphansInfoWindow *orphansInfoWindow = new OrphansInfoWindow(this);
    orphansInfoWindow->show();
}

void OrphanRegistrationForm::openEmployeesInfo() {
         this->close();
    // Create an instance of the EmployeesInfoWindow
    EmployeesInfoWindow *employeesInfoWindow = new EmployeesInfoWindow(this);
    employeesInfoWindow->show();
}

void OrphanRegistrationForm::openAdoptionRequests()
{
         this->close();
    // Create an instance of the AdoptionRequestsWindow
    AdoptionRequest *adoptionRequest = new AdoptionRequest(this);
    adoptionRequest->show();

}

void OrphanRegistrationForm::openManageDonations()
{
         this->close();
    // Create an instance of the AdminManageDonations Window
    AdminManageDonations *adminManageDonations = new AdminManageDonations(this);
    adminManageDonations->show();
}

void OrphanRegistrationForm::selectImage()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Select Image"), "", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    // Check if imagePath is not empty (i.e., if a file was selected)
    if (!imagePath.isEmpty())
    {
        // Display the selected image path (optional)
        // imagePathLabel->setText(imagePath);
        selectedImagePath = imagePath;
    }
}

OrphanRegistrationForm::~OrphanRegistrationForm()
{
}
