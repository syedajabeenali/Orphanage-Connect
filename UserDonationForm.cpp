#include "UserDonationForm.h"
#include "Login.h"
#include "User_OrphansInfoWindow.h"
#include "WeeklySportsActivities.h"
#include "UserAdoptionForm.h"
#include "ContactWindow.h"
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>

UserDonationForm::UserDonationForm(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    centralWidget->setStyleSheet("background-color: white;");

    // Sidebar layout
    QVBoxLayout *sidebarLayout = new QVBoxLayout();
    sidebarLayout->setSpacing(60);
    sidebarLayout->setAlignment(Qt::AlignTop);

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
    connect(backButton, &QPushButton::clicked, this, &UserDonationForm::goBackToLogin);
    sidebarLayout->addWidget(backButton);

    QVBoxLayout *formLayout = new QVBoxLayout(); // Layout for the form elements

    // Picture at the top
    QLabel *pictureLabel = new QLabel;
    QPixmap picture(R"(C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/DonationFormPic.jpg)");
    int width = 600;
    int height = 200;
    pictureLabel->setPixmap(picture.scaled(width, height, Qt::IgnoreAspectRatio));
    formLayout->addWidget(pictureLabel, 0, Qt::AlignCenter);

    // Add "Donation System" label at the top
    QLabel *titleLabel = new QLabel("Donation System", this);
    QFont titleFont;
    titleFont.setBold(true);
    titleFont.setPointSize(16);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignHCenter);
    titleLabel->setStyleSheet("color: #333;"); // Set text color to dark grey
    formLayout->addWidget(titleLabel);

    // Add subheading "Just A Penny Can Help Little Souls"
    QLabel *subheadingLabel = new QLabel("Just A Penny Can Help Little Souls", this);
    QFont subheadingFont;
    subheadingFont.setItalic(true);
    subheadingLabel->setFont(subheadingFont);
    subheadingLabel->setAlignment(Qt::AlignHCenter);
    subheadingLabel->setStyleSheet("color: #333;"); // Set text color to dark grey
    formLayout->addWidget(subheadingLabel);

    // Add input fields to the donation form content
    nameEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    paymentMethodComboBox = new QComboBox(this);
    commentsTextEdit = new QTextEdit(this);
    donationAmountEdit = new QLineEdit(this);

    paymentMethodComboBox->addItem("Paypal");
    paymentMethodComboBox->addItem("Credit Card");
    paymentMethodComboBox->addItem("Visa Card");

    // Adjust form layout for smaller screens
    formLayout->addWidget(new QLabel("Donor Name:", this));
    formLayout->addWidget(nameEdit);
    formLayout->addWidget(new QLabel("Donor Email:", this));
    formLayout->addWidget(emailEdit);
    formLayout->addWidget(new QLabel("Donation Amount:", this));
    formLayout->addWidget(donationAmountEdit);
    formLayout->addWidget(new QLabel("Payment Method:", this));
    formLayout->addWidget(paymentMethodComboBox);
    formLayout->addWidget(new QLabel("Additional Comments:", this));
    formLayout->addWidget(commentsTextEdit);


    // Add submit button
    QPushButton *submitButton = new QPushButton("Submit", this);
    submitButton->setStyleSheet("background-color: #800000; color: white; border-radius: 20px;"); // Dark red theme for the button with rounded corners
    connect(submitButton, &QPushButton::clicked, this, &UserDonationForm::submitDonation);
    submitButton->setCursor(Qt::PointingHandCursor); // Change cursor to a pointing hand on hover
    submitButton->setFixedSize(200, 40);
    formLayout->addWidget(submitButton, 0, Qt::AlignHCenter); // Align submit button to the center horizontally


    // Set hover effect animation for the submit button
    submitButton->setStyleSheet("QPushButton { background-color: #800000; color: white; border-radius: 20px; } QPushButton:hover { background-color: #a52a2a; color: white; border-radius: 20px; } QPushButton:pressed { background-color: #800000; color: white; border-radius: 20px; }");

    mainLayout->addLayout(formLayout);

    // Set window size
    resize(810, 650);
}

UserDonationForm::~UserDonationForm()
{
}

QPushButton* UserDonationForm::createSidebarButton(const QString &text, const QString &iconPath)
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
        connect(button, &QPushButton::clicked, this, &UserDonationForm::openOrphansInfo);
    } else if (text == "Donate") {
        connect(button, &QPushButton::clicked, this, &UserDonationForm::openDonationForm);
    } else if (text == "Adoption Request") {
        connect(button, &QPushButton::clicked, this, &UserDonationForm::openAdoptionForm);
    } else if (text == "Weekly Sports Activities") {
        connect(button, &QPushButton::clicked, this, &UserDonationForm::openWeeklySportsActivities);
    } else if (text == "Contact") {
        connect(button, &QPushButton::clicked, this, &UserDonationForm::openContact);
    }

    return button;
}

void UserDonationForm::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}


void UserDonationForm::submitDonation()
{
    // Get donor information from input fields
    QString name = nameEdit->text();
    QString email = emailEdit->text();
    QString paymentMethod = paymentMethodComboBox->currentText();
    QString comments = commentsTextEdit->toPlainText();
    QString amount = donationAmountEdit->text(); // Get donation amount

    // Check if any field is empty
    if (name.isEmpty() || email.isEmpty() || amount.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all fields.");
        return;
    }

    // Check if name contains numbers or special characters
    QRegularExpression nameRegex("^[a-zA-Z\\s]*$");
    if (!nameRegex.match(name).hasMatch()) {
        QMessageBox::critical(this, "Error", "Name cannot contain numbers or special characters.");
        return;
    }

    // Check if email is in a valid format
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::critical(this, "Error", "Please enter a valid email address.");
        return;
    }

    // Check if amount contains characters
    bool ok;
    amount.toDouble(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Error", "Donation amount must be a number.");
        return;
    }

    // Open the file for appending data
    QFile file(R"(C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/UserDonations.txt)");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file for writing!");
        return;
    }

    // Write donor information to the file in the desired format
    QTextStream out(&file);
    out << name << "," << email << "," << amount << "," << paymentMethod << "," << comments << Qt::endl;

    // Close the file
    file.close();

    // Show success message
    QMessageBox::information(this, "Success", "Donation submitted successfully!");
}

void UserDonationForm::openOrphansInfo() {
     this->close();

    // Create an instance of the OrphansInfoWindow
    User_OrphansInfoWindow *user_OrphansInfoWindow = new User_OrphansInfoWindow(this);
    user_OrphansInfoWindow->show();
}

void UserDonationForm::openDonationForm()
{
     this->close();
    // Create an instance of the DonationForm
    UserDonationForm *userDonationForm = new UserDonationForm(this);
    userDonationForm->show();
}

void UserDonationForm::openAdoptionForm()
{
     this->close();
    // Create an instance of the UserAdoptionForm
    UserAdoptionForm *userAdoptionForm = new UserAdoptionForm(this);
    userAdoptionForm->show();
}

void UserDonationForm::openWeeklySportsActivities()
{
     this->close();
    // Create an instance of the SportsActivitiesWindow
    WeeklySportsActivities *weeklySportsActivities = new WeeklySportsActivities(this);
    weeklySportsActivities->show();
}

void UserDonationForm::openContact()
{
     this->close();
    // Create an instance of the ContactWindow
    ContactWindow *contactWindow = new ContactWindow(this);
    contactWindow->show();
}
