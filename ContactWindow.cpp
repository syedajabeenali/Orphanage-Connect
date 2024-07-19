#include "ContactWindow.h"
#include "UserHomePage.h"
#include "Login.h"
#include "User_OrphansInfoWindow.h"
#include "WeeklySportsActivities.h"
#include "UserdonationForm.h"
#include "UserAdoptionForm.h"
#include "NutritionPlan.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

ContactWindow::ContactWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set window title
    setWindowTitle("Contact Us");

    // Create central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Sidebar layout
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Sidebar
    QVBoxLayout *sidebarLayout = new QVBoxLayout(); // Sidebar layout
    sidebarLayout->setSpacing(60);
    sidebarLayout->setAlignment(Qt::AlignTop);

    QWidget *sidebar = new QWidget(this);
    sidebar->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;");
    sidebar->setLayout(sidebarLayout);
    sidebar->setFixedWidth(180);
    mainLayout->addWidget(sidebar);

    // Add icon to sidebar
    QLabel *iconLabel = new QLabel;
    QPixmap orphanageIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png");
    iconLabel->setPixmap(orphanageIcon);
    iconLabel->setScaledContents(true);
    iconLabel->setFixedSize(50, 50);
    sidebarLayout->addWidget(iconLabel);

    // Add buttons and other elements to the sidebar layout
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
    sidebarLayout->addWidget(backButton);

    connect(backButton, &QPushButton::clicked, this, &ContactWindow::goBackToLogin);
    sidebarLayout->addWidget(backButton);
    // Create layouts for other widgets
    QVBoxLayout *formLayout = new QVBoxLayout();
    searchLayout = new QHBoxLayout;
    contactLayout = new QVBoxLayout;

    // Create widgets
    titleLabel = new QLabel("Contact Us");
    titleLabel->setFont(QFont("Arial", 18, QFont::Bold));
    searchLabel = new QLabel("Search:");
    searchLineEdit = new QLineEdit;
    searchButton = new QPushButton("Search");
    contactDetailsTextEdit = new QTextEdit;
    contactDetailsTextEdit->setReadOnly(true);

    // Load contacts from file
    loadContactsFromFile();

    // Set up search functionality
    connect(searchButton, &QPushButton::clicked, this, &ContactWindow::searchContacts);

    // Set up layouts
    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(searchButton);

    formLayout->addWidget(titleLabel);
    formLayout->addLayout(searchLayout);
    formLayout->addLayout(contactLayout);
    formLayout->addWidget(contactDetailsTextEdit);
    formLayout->addStretch();

    // Set main layout
    mainLayout->addLayout(formLayout);

    // Load orphanage image
    orphanageImage.load("C:/Users/user/Downloads/Orphangezipfile/OurProject/ContactPic.png");
    QLabel *imageLabel = new QLabel;
    imageLabel->setPixmap(orphanageImage.scaled(810, 300));
    imageLabel->setAlignment(Qt::AlignCenter);
    contactLayout->addWidget(imageLabel);

    // Apply background gradient to the central widget
    centralWidget->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #f0f0f0, stop:1 #CCCCCC);");

    resize(810,650);

}

ContactWindow::~ContactWindow()
{
}

void ContactWindow::loadContactsFromFile()
{
    QFile file(R"(C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Contact_info.txt)");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open contacts file";
        return;
    }

    QTextStream in(&file);
    QString rank;
    while (!in.atEnd())
    {
        QString line = in.readLine();
if (line.startsWith("Rank:"))
{
    rank = line.mid(6); // Get the rank text without "Rank: "
    QLabel *rankLabel = new QLabel(rank);
    rankLabel->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #800000, stop:1 #400000 ); \
                           color: white; \
                           font-weight: bold; \
                           border-radius: 5px; \
                           padding: 5px; \
                           min-width: 80px; \
                           max-width: 80px;"); // Adjust the max-width property

    contactLayout->addWidget(rankLabel);
}

        else if (!line.isEmpty())
        {
            QLabel *label = new QLabel(line);
            label->setStyleSheet("background-color: lightgrey;");
            contactLayout->addWidget(label);
        }
    }

    file.close();
}

void ContactWindow::displayContacts()
{
    // Adding vertical spacers between each contact
    contactLayout->addStretch(2);
}

void ContactWindow::searchContacts()
{
    QString searchText = searchLineEdit->text().trimmed().toLower();
    contactDetailsTextEdit->clear();

    QTextCharFormat format;
    format.setBackground(Qt::yellow); // Set the background color for highlighting

    QTextCursor cursor(contactDetailsTextEdit->document());

    for (auto it = contacts.begin(); it != contacts.end(); ++it)
    {
        QVector<QString> personInfo = it.value();
        for (const QString &contact : personInfo)
        {
            QString lowerContact = contact.toLower();
            int index = lowerContact.indexOf(searchText);
            if (index != -1)
            {
                cursor.movePosition(QTextCursor::End);
                cursor.insertText(it.key() + ": " + contact);
                cursor.setPosition(cursor.position() - contact.length() + index, QTextCursor::MoveAnchor);
                cursor.setPosition(cursor.position() + searchText.length(), QTextCursor::KeepAnchor);
                cursor.setCharFormat(format);
                cursor.setPosition(cursor.position() + 1);
                cursor.setCharFormat(QTextCharFormat());
                cursor.insertText("\n");
            }
        }
    }
}

void ContactWindow::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}


QPushButton* ContactWindow::createSidebarButton(const QString &text, const QString &iconPath)
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
        connect(button, &QPushButton::clicked, this, &ContactWindow::openOrphansInfo);
    } else if (text == "Donate") {
        connect(button, &QPushButton::clicked, this, &ContactWindow::openDonationForm);
    } else if (text == "Adoption Request") {
        connect(button, &QPushButton::clicked, this, &ContactWindow::openAdoptionForm);
    } else if (text == "Weekly Sports Activities") {
        connect(button, &QPushButton::clicked, this, &ContactWindow::openWeeklySportsActivities);
    } else if (text == "Contact") {
        connect(button, &QPushButton::clicked, this, &ContactWindow::openContact);
    }

    return button;
}

void ContactWindow::openOrphansInfo() {
    this->close();

    // Create an instance of the OrphansInfoWindow
    User_OrphansInfoWindow *user_orphansInfoWindow = new User_OrphansInfoWindow(this);
    user_orphansInfoWindow->show();
}

void ContactWindow::openDonationForm()
{
    this->close();
    // Create an instance of the DonationForm
    UserDonationForm *userDonationForm = new UserDonationForm(this);
    userDonationForm->show();
}

void ContactWindow::openAdoptionForm()
{
    this->close();

    // Create an instance of the UserAdoptionForm
    UserAdoptionForm *userAdoptionForm = new UserAdoptionForm(this);
    userAdoptionForm->show();

}

void ContactWindow::openWeeklySportsActivities()
{
    this->close();

    // Create an instance of the SportsActivitiesWindow
    WeeklySportsActivities *weeklySportsActivities = new WeeklySportsActivities(this);
    weeklySportsActivities->show();
}


void ContactWindow::openContact()
{
    this->close();

    // Create an instance of the ContactWindow
    ContactWindow *contactWindow = new ContactWindow(this);
    contactWindow->show();
}







