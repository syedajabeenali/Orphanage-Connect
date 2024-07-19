#include "UserAdoptionForm.h"
#include "User_OrphansInfoWindow.h"
#include "WeeklySportsActivities.h"
#include "ContactWindow.h"
#include "Login.h"
#include "UserDonationForm.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

UserAdoptionForm::UserAdoptionForm(QWidget *parent)
    : QWidget(parent)
{
    // Main window
    setWindowTitle("Adoption Request Form");
    setWindowFlags(Qt::Window);

    // Main layout for the entire window
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // Sidebar layout
    QVBoxLayout *sidebarLayout = new QVBoxLayout();
    sidebarLayout->setSpacing(60);
    sidebarLayout->setAlignment(Qt::AlignTop);

    // Create sidebar widget
    QWidget *sidebar = new QWidget(this);
    sidebar->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;");
    sidebar->setLayout(sidebarLayout);
    sidebar->setFixedWidth(180);

    // Add icon to sidebar
    QLabel *iconLabel = new QLabel;
    QPixmap orphanageIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"); // Provide the path to your orphanage icon
    iconLabel->setPixmap(orphanageIcon);
    iconLabel->setScaledContents(true); // Scale the image to fit the QLabel
    iconLabel->setFixedSize(50, 50); // Set the size of the QLabel
    iconLabel->move(0,0);
    sidebarLayout->addWidget(iconLabel);

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
    backButton->setIconSize(QSize(24, 24));
    backButton->setFixedSize(40, 40);
    backButton->setCursor(Qt::PointingHandCursor);
    connect(backButton, &QPushButton::clicked, this, &UserAdoptionForm::goBackToLogin);
    sidebarLayout->addWidget(backButton);

    // Add sidebar to the main layout
    mainLayout->addWidget(sidebar);

    // Main content area layout
    QVBoxLayout *contentLayout = new QVBoxLayout();
    contentLayout->setContentsMargins(20, 20, 20, 20);
    contentLayout->setSpacing(20);

    // Picture at the top
    QLabel *pictureLabel = new QLabel;
    QPixmap picture(R"(C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/UserAdoptionRequestPic.jpg)");
    int width = 600;
    int height = 200;
    pictureLabel->setPixmap(picture.scaled(width, height, Qt::IgnoreAspectRatio));
    contentLayout->addWidget(pictureLabel, 0, Qt::AlignCenter);

    // Big bold title label
    QLabel *bigTitleLabel = new QLabel("Request Form");
    bigTitleLabel->setAlignment(Qt::AlignCenter);
    QFont bigTitleFont = bigTitleLabel->font();
    bigTitleFont.setPointSize(16);
    bigTitleFont.setBold(true);
    bigTitleLabel->setFont(bigTitleFont);
    bigTitleLabel->setStyleSheet("color: black;");
    contentLayout->addWidget(bigTitleLabel, 0, Qt::AlignLeft);

    // Adoptor's Details section
    QFrame *adoptorFrame = new QFrame;
    adoptorFrame->setLineWidth(1);
    adoptorFrame->setStyleSheet("QFrame { background-color: darkgrey; }");
    QVBoxLayout *adoptorLayout = new QVBoxLayout(adoptorFrame);
    QLabel *adoptorLabel = new QLabel("Adoptor's Details");
    adoptorLabel->setStyleSheet("color: black; font-weight: bold;");
    adoptorLabel->setAlignment(Qt::AlignCenter);
    adoptorLayout->addWidget(adoptorLabel);
    contentLayout->addWidget(adoptorFrame);

    // Input labels and line edits for adoptor information
    QStringList adoptorLabels = {"Adopter's Name:", "Number of Family Members:", "Marital Status:", "Income:"};
    addLabelsAndLineEdits(adoptorLabels, adoptorLayout);

    // Child's Details section
    QFrame *childFrame = new QFrame;
    childFrame->setLineWidth(1);
    childFrame->setStyleSheet("QFrame { background-color: darkgrey; }");
    QVBoxLayout *childLayout = new QVBoxLayout(childFrame);
    QLabel *childLabel = new QLabel("Child's Details");
    childLabel->setStyleSheet("color: black; font-weight: bold;");
    childLabel->setAlignment(Qt::AlignCenter);
    childLayout->addWidget(childLabel);
    contentLayout->addWidget(childFrame);
    QStringList childLabels = {"Child's Name:"};
    addLabelsAndLineEdits(childLabels, childLayout);

    // Housing Details section
    QFrame *housingFrame = new QFrame;
    housingFrame->setLineWidth(1);
    housingFrame->setStyleSheet("QFrame { background-color: darkgrey; }");
    QVBoxLayout *housingLayout = new QVBoxLayout(housingFrame);
    QLabel *housingLabel = new QLabel("Housing Details");
    housingLabel->setStyleSheet("color: black; font-weight: bold;");
    housingLabel->setAlignment(Qt::AlignCenter);
    housingLayout->addWidget(housingLabel);
    contentLayout->addWidget(housingFrame);
    QStringList houseLabels = {"Address:", "House Area:"};
    addLabelsAndLineEdits(houseLabels, housingLayout);

    // Submit button
    submitButton = new QPushButton("Submit");
    submitButton->setStyleSheet("background-color: #800000; color: white; border-radius: 20px;");
    submitButton->setStyleSheet("QPushButton {"
                                "background-color: #800000;" // Dark red background color
                                "color: white;" // White text color
                                "border: 2px solid #800000;" // Dark red border
                                "border-radius: 5px;" // Rounded corners
                                "}"
                                "QPushButton:hover {"
                                "background-color: #a52a2a;" // Lighter red when hovered
                                "}"
                                "QPushButton:pressed {"
                                "background-color: #5f0000;" // Darker red when pressed
                                "}");
     submitButton->setFixedSize(200, 40);
    contentLayout->addWidget(submitButton, 0, Qt::AlignCenter);

    // Connect the submit button click signal to a slot
    connect(submitButton, &QPushButton::clicked, this, &UserAdoptionForm::handleSubmit);

    // Add content layout to the main layout
    mainLayout->addLayout(contentLayout);

    // Adjust spacing and margins of the main layout
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // Set the main layout to the window
    setLayout(mainLayout);

    resize(810, 650);
}

void UserAdoptionForm::addLabelsAndLineEdits(const QStringList &labels, QVBoxLayout *layout)
{
    for (int i = 0; i < labels.size(); ++i)
    {
        QHBoxLayout *lineLayout = new QHBoxLayout;
        QLabel *label = new QLabel(labels[i]);
        label->setStyleSheet("color: black;");
        QLineEdit *lineEdit = new QLineEdit;
        lineLayout->addWidget(label);
        lineLayout->addWidget(lineEdit);
        layout->addLayout(lineLayout);
        lineEdits.append(lineEdit);
    }
}

QPushButton* UserAdoptionForm::createSidebarButton(const QString &text, const QString &iconPath)
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
        connect(button, &QPushButton::clicked, this, &UserAdoptionForm::openOrphansInfo);
    } else if (text == "Donate") {
        connect(button, &QPushButton::clicked, this, &UserAdoptionForm::openDonationForm);
    } else if (text == "Adoption Request") {
        connect(button, &QPushButton::clicked, this, &UserAdoptionForm::openAdoptionForm);
    } else if (text == "Weekly Sports Activities") {
        connect(button, &QPushButton::clicked, this, &UserAdoptionForm::openWeeklySportsActivities);
    } else if (text == "Contact") {
        connect(button, &QPushButton::clicked, this, &UserAdoptionForm::openContact);
    }

    return button;
}

void UserAdoptionForm::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}

void UserAdoptionForm::handleSubmit()
{
    // Validation check for name
    QString adopterName = lineEdits[0]->text();
    QRegularExpression nameRegex("^[a-zA-Z\\s]*$");
    if (!nameRegex.match(adopterName).hasMatch())
    {
        QMessageBox::critical(this, "Error", "Adopter's name cannot contain numbers or special characters.");
        return;
    }

    // Validation check for number of family members
    QString numFamilyMembers = lineEdits[1]->text();
    bool familyMembersValid = false;
    int familyMembers = numFamilyMembers.toInt(&familyMembersValid);
    if (!familyMembersValid || familyMembers <= 0)
    {
        QMessageBox::critical(this, "Error", "Number of family members must be a positive integer.");
        return;
    }

    // Validation check for marital status
    QString maritalStatus = lineEdits[2]->text().toLower();
    if (maritalStatus != "single" && maritalStatus != "married")
    {
        QMessageBox::critical(this, "Error", "Marital status should be either 'Single' or 'Married'.");
        return;
    }

    // Validation check for income
    QString income = lineEdits[3]->text();
    bool incomeValid = false;
    double incomeAmount = income.toDouble(&incomeValid);
    if (!incomeValid || incomeAmount <= 0)
    {
        QMessageBox::critical(this, "Error", "Income must be a positive number.");
        return;
    }

    // Validation check for house area
    QString houseArea = lineEdits[6]->text();
    bool areaValid = false;
    double area = houseArea.toDouble(&areaValid);
    if (!areaValid || area <= 0)
    {
        QMessageBox::critical(this, "Error", "House area must be a positive number.");
        return;
    }

    // Get the list of enrolled orphan names
    QStringList enrolledOrphansNames = getEnrolledOrphansNames();
    qDebug() << "Enrolled Orphans Names:" << enrolledOrphansNames;

    // Get the entered child's name
    QString childName = lineEdits[4]->text(); // Assuming the first line edit contains the child's name
    qDebug() << "Entered Child's Name:" << childName;

    // Check if the entered child's name is enrolled
    if (enrolledOrphansNames.contains(childName))
    {
        // Child is enrolled, proceed with submitting the adoption request
        QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/UserAdoptionFile.txt");
        if (!file.open(QIODevice::Append | QIODevice::Text))
        {
            qDebug() << "Failed to open file for writing.";
            return;
        }

        QTextStream out(&file);

        for (int i = 0; i < lineEdits.size(); ++i)
        {
            out << lineEdits[i]->text();
            if (i != lineEdits.size() - 1)
                out << ",";
        }
        out << "\n";

        file.close();

        qDebug() << "Data saved to file: UserAdoptionFile.txt";

        QMessageBox::information(this, "Success", "Request Submitted successfully!");
    }
    else
    {
        // Child is not enrolled, display error message
        QMessageBox::critical(this, "Error", "The entered child's name is not enrolled in the system.");
    }
}



void UserAdoptionForm::openOrphansInfo()
{
    this->close();
    User_OrphansInfoWindow *user_orphansInfoWindow = new User_OrphansInfoWindow(this);
    user_orphansInfoWindow->show();
}

void UserAdoptionForm::openDonationForm()
{
    this->close();
    UserDonationForm *userDonationForm = new UserDonationForm(this);
    userDonationForm->show();
}

void UserAdoptionForm::openAdoptionForm()
{
    this->close();
    UserAdoptionForm *userAdoptionForm = new UserAdoptionForm(this);
    userAdoptionForm->show();
}

void UserAdoptionForm::openWeeklySportsActivities()
{
     this->close();
    WeeklySportsActivities *weeklySportsActivities = new WeeklySportsActivities(this);
    weeklySportsActivities->show();
}

void UserAdoptionForm::openContact()
{
    this->close();
    ContactWindow *contactWindow = new ContactWindow(this);
    contactWindow->show();
}

QStringList UserAdoptionForm::getEnrolledOrphansNames()
{
    QStringList enrolledOrphansNames;

    QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Registered_Orphans.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open Registered Orphans file for reading.";
        return enrolledOrphansNames;
    }

    QTextStream in(&file);
    QString jsonData = in.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
    if (!doc.isArray())
    {
        qDebug() << "Registered Orphans data is not in array format.";
        return enrolledOrphansNames;
    }

    QJsonArray jsonArray = doc.array();
    for (const QJsonValue &value : jsonArray)
    {
        if (value.isObject())
        {
            QJsonObject orphanObject = value.toObject();
            enrolledOrphansNames.append(orphanObject["Name"].toString());
        }
    }

    return enrolledOrphansNames;
}

UserAdoptionForm::~UserAdoptionForm()
{
}



