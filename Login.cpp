#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QMouseEvent> // Include QMouseEvent to handle mouse events
#include "Login.h"
#include "ClickableLabel.h"
#include "AccountCreationWindow.h"
#include "AdminHomePage.h"
#include "UserHomePage.h"

Login::Login(QWidget *parent) : QMainWindow(parent)
{
    // Set the background image of the main window
    QString backgroundImage = "C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/OrphanPic.png";
    this->setStyleSheet("QMainWindow { background-image: url(" + backgroundImage + "); background-size: cover; }");

    setWindowIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"));

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Add a QLabel to display the logo image
    QLabel *logoLabel = new QLabel(this);
    QPixmap logoPixmap("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png");
    logoLabel->setPixmap(logoPixmap);
    logoLabel->setScaledContents(true); // Scale the image to fit the QLabel
    logoLabel->setFixedSize(50, 50); // Set the size of the QLabel
    logoLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft); // Align the label to the top-right corner
    layout->addWidget(logoLabel);

    // Add a QLabel to display the name of the management system
    QLabel *titleLabel = new QLabel("Orphanage Connect", this);
    titleLabel->setStyleSheet("font-weight: bold; font-size: 40px; color: #333;"); // Add styling to the title label
    titleLabel->setAlignment(Qt::AlignLeft);

    // Add the boundary box to the main layout
    layout->addWidget(titleLabel);
    layout->addSpacing(100); // Add vertical spacing between title label and buttons

    // Create a QHBoxLayout for the buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(25); // Set horizontal spacing between buttons
    buttonLayout->setAlignment(Qt::AlignHCenter); // Align buttons horizontally at the center

    // Create buttons for user and admin sign-ins
    userSignInButton = new QPushButton("User", this);
    connect(userSignInButton, &QPushButton::clicked, this, &Login::userSignInClicked);
    userSignInButton->setFixedSize(230, 40);
    userSignInButton->setStyleSheet("QPushButton {"
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
    userSignInButton->setFont(QFont("Arial", 14, QFont::Bold)); // Increased font size and set bold
    buttonLayout->addWidget(userSignInButton);

    adminSignInButton = new QPushButton("Admin", this); // Initialize adminSignInButton
    connect(adminSignInButton, &QPushButton::clicked, this, &Login::adminSignInClicked);
    adminSignInButton->setFixedSize(230, 40);
    adminSignInButton->setFont(QFont("Arial", 14, QFont::Bold));
    adminSignInButton->setStyleSheet("QPushButton {"
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

    buttonLayout->addWidget(adminSignInButton);
    layout->addLayout(buttonLayout); // Add the button layout to the main layout

    // Create the sign-in box
    QWidget *signInBox = new QWidget(this);
    signInBox->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999);"
                             "border: 2px solid #aaa;"
                             "border-radius: 10px;"
                             "padding: 20px;"); // Set gradient background color with border and padding
    signInBox->setFixedSize(500, 280); // Set the fixed size of the sign-in box
    QVBoxLayout *signInBoxLayout = new QVBoxLayout(signInBox);

    usernameEdit = new QLineEdit(signInBox);
    usernameEdit->setPlaceholderText("Username");
    usernameEdit->setFixedSize(300, 30);
    usernameEdit->setContentsMargins(0, 0, 0, 0); // Set margins to zero
    signInBoxLayout->addWidget(usernameEdit, 0, Qt::AlignCenter); // Center align the username edit field

    passwordEdit = new QLineEdit(signInBox);
    passwordEdit->setPlaceholderText("Password");
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setFixedSize(300, 30);
    signInBoxLayout->addWidget(passwordEdit, 0, Qt::AlignCenter); // Center align the password edit field

    QPushButton *signInButton = new QPushButton("Sign In", signInBox);

    connect(signInButton, &QPushButton::clicked, this, &Login::signInClicked);
    signInButton->setFixedSize(300, 30);
    signInButton->setStyleSheet("QPushButton {"
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
    signInBoxLayout->addWidget(signInButton, 0, Qt::AlignCenter); // Center align the sign-in button

    // Create a clickable label for "Don't have an account? Sign up"
    ClickableLabel *signUpLabel = new ClickableLabel("Don't have an account? Sign up", signInBox);
    signUpLabel->setStyleSheet("color: #333; font-size: 14px; text-decoration: underline;");
    signUpLabel->setCursor(Qt::PointingHandCursor); // Change cursor to a pointing hand when hovering over the label
    signInBoxLayout->addWidget(signUpLabel, 0, Qt::AlignCenter); // Center align the sign-up label

    // Connect the clicked signal of the label to a slot
    // Connect the clicked signal of the label to the slot
    connect(signUpLabel, &ClickableLabel::clicked, this, &Login::openAccountCreationWindow);


    // Apply the same gradient background color to the sign-in box
    QPalette signInPalette = signInBox->palette();
    signInPalette.setColor(QPalette::Window, QColor(85, 85, 85)); // Change background color to match the sidebar gradient
    signInBox->setAutoFillBackground(true);
    signInBox->setPalette(signInPalette);

    layout->addWidget(signInBox, 0, Qt::AlignHCenter); // Center align the sign-in box within the main layout

    setWindowTitle("Authentication");
    centralWidget->setMinimumSize(810, 650);
}

// Slot to handle mouse press event on the clickable label
void Login::openAccountCreationWindow()
{
    // Open the window for account creation
    AccountCreationWindow *accountCreationWindow = new AccountCreationWindow(this);
    accountCreationWindow->show();
}

void Login::signInClicked()
{
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Open the credentials file
    QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Users_credentials.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open credentials file.");
        return;
    }

    QTextStream in(&file);
    bool signInSuccessful = false;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        qDebug() << "Line read from file:" << line;
        qDebug() << "Parts:" << parts;
        if (parts.size() == 2 && parts[0] == username && parts[1] == password) {
            signInSuccessful = true;
            break;
        }
    }

    file.close();

    if (signInSuccessful) {
        QMessageBox::information(this, "Success", "Sign-in successful."); // Display success message
        // Check if it's admin or user
        if (username == "admin") {
            adminSignInClicked(); // Directly invoke admin sign-in logic
              this->close();
        } else {
            userSignInClicked(); // Directly invoke user sign-in logic
              this->close();
        }
    } else {
        QMessageBox::critical(this, "Error", "Invalid username or password.");
    }
}



Login::~Login()
{
}

void Login::adminSignInClicked()
{
    QString adminUsername = "admin"; // Default admin username
    QString adminPassword = "admin123"; // Default admin password

    QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Admin_credentials.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open admin credentials file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 2) {
            adminUsername = parts[0];
            adminPassword = parts[1];
            break;
        }
    }

    file.close();

    if (usernameEdit->text() == adminUsername && passwordEdit->text() == adminPassword) {
        QMessageBox::information(this, "Success", "Admin sign-in successful."); // Display success message
        // Open the main menu window
         this->close();
        AdminHomepage *adminHomepage = new AdminHomepage(this);
        adminHomepage->show();
    } else {
        QMessageBox::critical(this, "Error", "Invalid admin username or password.");
    }
}

void Login::userSignInClicked()
{
    QString userUsername; // User's username read from file
    QString userPassword; // User's password read from file

    QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Users_credentials.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open user credentials file.");
        return;
    }

    QTextStream in(&file);
    bool signInSuccessful = false; // Flag to track if sign-in was successful
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 2) {
            userUsername = parts[0];
            userPassword = parts[1];
            if (usernameEdit->text() == userUsername && passwordEdit->text() == userPassword) {
                signInSuccessful = true; // Set sign-in success flag
                break; // Exit the loop if sign-in is successful
            }
        }
    }

    file.close();

    if (signInSuccessful) {
        QMessageBox::information(this, "Success", "User sign-in successful."); // Display success message
        // Open the user home page window
         this->close();
        UserHomePage *userHomePage = new UserHomePage(this);
        userHomePage->show();
    } else {
        QMessageBox::critical(this, "Error", "Invalid user username or password.");
    }
}

