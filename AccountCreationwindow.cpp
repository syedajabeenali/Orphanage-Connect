#include "AccountCreationWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpressionValidator>
#include <QIcon>

AccountCreationWindow::AccountCreationWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Create Account");
    setWindowIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"));
    QWidget *centralWidget = new QWidget(this); // Create a central widget
    setCentralWidget(centralWidget); // Set it as the central widget of the main window

    // centralWidget->setStyleSheet("background-color: sky blue;");

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget); // Main layout

    // Top layout for icon and title
    QVBoxLayout *topLayout = new QVBoxLayout();

    // Add a QLabel to display the logo image
    QLabel *logoLabel = new QLabel(this);
    QPixmap logoPixmap("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png");
    logoLabel->setPixmap(logoPixmap);
    logoLabel->setScaledContents(true); // Scale the image to fit the QLabel
    logoLabel->setFixedSize(50, 50); // Set the size of the QLabel
    logoLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft); // Align the label to the top-left corner
    topLayout->addWidget(logoLabel);

    // Add a QLabel to display the name of the management system
    QLabel *titleLabel = new QLabel("Orphanage Connect", this);
    titleLabel->setStyleSheet("font-weight: bold; font-size: 40px; color: #333;"); // Add styling to the title label
    titleLabel->setAlignment(Qt::AlignLeft);
    topLayout->addWidget(titleLabel);

    // Add the top layout to the main layout
    mainLayout->addLayout(topLayout);

    // Heading
    QLabel *headingLabel = new QLabel("Create New Account");
    headingLabel->setStyleSheet("font-weight: bold; font-size: 20px; color: #333;");
    mainLayout->addWidget(headingLabel, 0, Qt::AlignCenter);

    // Create the sign-up box
    QWidget *signUpBox = new QWidget(this);
    signUpBox->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999);"
                             "border: 2px solid #aaa;"
                             "border-radius: 10px;"
                             "padding: 20px;"); // Set gradient background color with border and padding
    signUpBox->setFixedSize(650, 450); // Set the fixed size of the sign-up box
    QVBoxLayout *signUpBoxLayout = new QVBoxLayout(signUpBox);

    // Username field
    QHBoxLayout *usernameLayout = new QHBoxLayout();
    QLabel *usernameLabel = new QLabel("Username:", signUpBox);
    usernameEdit = new QLineEdit(signUpBox);
    usernameEdit->setPlaceholderText("Enter your username");
    usernameEdit->setFixedSize(350, 30); // Adjust size
    usernameEdit->setStyleSheet("background-color: white;"); // Set background color to white
    usernameEdit->setContentsMargins(0, 0, 0, 0); // Set margins to zero
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameEdit);
    signUpBoxLayout->addLayout(usernameLayout);

    // Email field
    QHBoxLayout *emailLayout = new QHBoxLayout();
    QLabel *emailLabel = new QLabel("Email:", signUpBox);
    emailEdit = new QLineEdit(signUpBox);
    emailEdit->setPlaceholderText("Enter your email");
    emailEdit->setFixedSize(350, 30); // Adjust size
    emailEdit->setStyleSheet("background-color: white;"); // Set background color to white
    emailLayout->addWidget(emailLabel);
    emailLayout->addWidget(emailEdit);
    signUpBoxLayout->addLayout(emailLayout);

    // Phone number field
    QHBoxLayout *phoneLayout = new QHBoxLayout();
    QLabel *phoneLabel = new QLabel("Phone Number:", signUpBox);
    phoneEdit = new QLineEdit(signUpBox);
    phoneEdit->setPlaceholderText("Enter your phone number");
    phoneEdit->setFixedSize(350, 30); // Adjust size
    phoneEdit->setStyleSheet("background-color: white;"); // Set background color to white
    QRegularExpression phoneRegex("\\d{11}"); // Regex for 11 digits
    phoneEdit->setValidator(new QRegularExpressionValidator(phoneRegex, this));
    phoneLayout->addWidget(phoneLabel);
    phoneLayout->addWidget(phoneEdit);
    signUpBoxLayout->addLayout(phoneLayout);

    // Password field
    QHBoxLayout *passwordLayout = new QHBoxLayout();
    QLabel *passwordLabel = new QLabel("Password:", signUpBox);
    passwordEdit = new QLineEdit(signUpBox);
    passwordEdit->setPlaceholderText("Enter your password");
    passwordEdit->setFixedSize(350, 30); // Adjust size
    passwordEdit ->setStyleSheet("background-color: white;"); // Set background color to white
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordEdit);
    signUpBoxLayout->addLayout(passwordLayout);

    // Confirm Password field
    QHBoxLayout *confirmPasswordLayout = new QHBoxLayout();
    QLabel *confirmPasswordLabel = new QLabel("Confirm Password:", signUpBox);
    confirmPasswordEdit = new QLineEdit(signUpBox);
    confirmPasswordEdit->setPlaceholderText("Confirm your password");
    confirmPasswordEdit->setFixedSize(350, 30); // Adjust size
    confirmPasswordEdit->setStyleSheet("background-color: white;"); // Set background color to white
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordLayout->addWidget(confirmPasswordLabel);
    confirmPasswordLayout->addWidget(confirmPasswordEdit);
    signUpBoxLayout->addLayout(confirmPasswordLayout);

    // Terms and Conditions checkbox
    termsCheckBox = new QCheckBox("I agree to the Terms and Conditions", signUpBox);
    signUpBoxLayout->addWidget(termsCheckBox, 0, Qt::AlignCenter);

    // Create Account button
    createAccountButton = new QPushButton("Sign Up", signUpBox);
    createAccountButton->setFixedSize(370, 30); // Adjust size
    createAccountButton->setStyleSheet("QPushButton {"
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
    connect(createAccountButton, &QPushButton::clicked, this, &AccountCreationWindow::createAccountClicked);
    signUpBoxLayout->addWidget(createAccountButton, 0, Qt::AlignCenter);

    // Apply the same gradient background color to the sign-up box
    QPalette signUpPalette = signUpBox->palette();
    signUpPalette.setColor(QPalette::Window, QColor(85, 85, 85)); // Change background color to match the sidebar gradient
    signUpBox->setAutoFillBackground(true);
    signUpBox->setPalette(signUpPalette);

    mainLayout->addWidget(signUpBox, 0, Qt::AlignHCenter); // Center align the sign-up box within the main layout


    centralWidget->setLayout(mainLayout); // Set the main layout on the central widget
    resize(810, 650);
}

AccountCreationWindow::~AccountCreationWindow()
{
}

    void AccountCreationWindow::createAccountClicked()
    {
        QString username = usernameEdit->text();
        QString email = emailEdit->text();
        QString phone = phoneEdit->text();
        QString password = passwordEdit->text();
        QString confirmPassword = confirmPasswordEdit->text();

        // Validate fields
        if (username.isEmpty() || email.isEmpty() || phone.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please fill in all fields.");
            return;
        }

        if (phone.length() < 11) {
            QMessageBox::warning(this, "Error", "Phone number must contain at least 11 digits.");
            return;
        }

        if (password != confirmPassword) {
            QMessageBox::warning(this, "Error", "Passwords do not match.");
            return;
        }

        if (!termsCheckBox->isChecked()) {
            QMessageBox::warning(this, "Error", "Please agree to the Terms and Conditions.");
            return;
        }

        // Open the credentials file
        QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Users_credentials.txt");
        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Failed to open credentials file.");
            return;
        }

        // Write new account to file
        QTextStream out(&file);
        out << username << " " << password << "\n";
        file.close();

        QMessageBox::information(this, "Success", "Account created successfully.");
        emit accountCreated(); // Signal that account is created
        close(); // Close the window
    }
