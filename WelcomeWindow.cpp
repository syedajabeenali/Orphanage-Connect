#include "WelcomeWindow.h"
#include "Login.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Set window title, size, and icon
    setWindowTitle("Orphanage Welcome");
    resize(800, 650);
    setWindowIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"));

    // Create the main widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    centralWidget->setStyleSheet("background-color: white;");
    // Load the picture
    QPixmap picture(R"(C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Welcomepg.jpg)");

    // Scale the picture to the desired size
    QSize newSize(810, 1400); // Set size of picture and window
    QPixmap scaledPicture = picture.scaled(newSize, Qt::KeepAspectRatio);

    // Create the picture label
    pictureLabel = new QLabel;
    pictureLabel->setPixmap(scaledPicture);
    pictureLabel->setAlignment(Qt::AlignCenter);
    pictureLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Set size policy to expand

    // Create other UI elements (text label, line, button, spacers)
    textLabel = new QLabel("Welcome to Orphanage");
    textLabel->setAlignment(Qt::AlignLeft);
    QFont font = textLabel->font();
    font.setPointSize(16); // Increase font size
    font.setBold(true);    // Make it bold
    textLabel->setFont(font);

    line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setFixedHeight(3); // Set smaller horizontal size
    line->setStyleSheet("background-color: #800000;"); // Set darker shade of red

    // Create the "Get Started" button
    button = new QPushButton("Get Started", this);
    button->setStyleSheet("QPushButton {"
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

    // Add arrow icon to the button
    QIcon icon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/forward_arrow.png");
    button->setIcon(icon);
    button->setIconSize(QSize(20, 20));
    button->setFixedSize(300, 40); // Set button size


    // Create spacer items
    QSpacerItem *spacerMiddle = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem *spacerBottom = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    // Create layout
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create and add the icon QLabel to the layout
    QLabel *iconLabel = new QLabel;
    QPixmap iconPixmap("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png"); // Set the path to your icon
    iconPixmap = iconPixmap.scaled(50, 50); // Scale the icon to 50x50
    iconLabel->setPixmap(iconPixmap);
    layout->addWidget(iconLabel, 0, Qt::AlignTop | Qt::AlignLeft); // Align the icon to the top-left corner

    // Create back button
    backButton = new QPushButton(this);
    backButton->setIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/IconBackArrow.png")); // Set the icon
    backButton->setIconSize(QSize(24, 24)); // Set the size of the icon
    backButton->setFixedSize(40, 40); // Set the size of the button

    layout->addWidget(pictureLabel);
    layout->addWidget(textLabel);

    layout->addWidget(line);
    layout->addWidget(button, 0, Qt::AlignHCenter | Qt::AlignTop); // Align button to the center and a little above
    layout->addWidget(backButton, 0, Qt::AlignBottom | Qt::AlignLeft); // Align back button to the top-right corner
    layout->addItem(spacerMiddle);
    layout->addItem(spacerBottom);

    centralWidget->setLayout(layout);

    // Connect the button's clicked signal to a slot that opens the Login window
    connect(button, &QPushButton::clicked, this, &MainWindow::openLoginWindow);
    // Connect the back button's clicked signal to a slot that handles going back
    connect(backButton, &QPushButton::clicked, this, &MainWindow::goBack);
}

void MainWindow::openLoginWindow()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}

void MainWindow::goBack()
{
    // Close the current window
    this->close();

    // // Open the previous window (e.g., Welcome window)
    // WelcomeWindow *welcomeWindow = new WelcomeWindow;
    // welcomeWindow->show();
}

MainWindow::~MainWindow()
{
    delete pictureLabel;
    delete textLabel;
    delete line;
    delete button;
    delete backButton;
}
