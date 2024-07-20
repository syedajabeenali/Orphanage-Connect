#include "UserHomePage.h"
#include "Login.h"
#include "User_OrphansInfoWindow.h"
#include "WeeklySportsActivities.h"
#include "UserdonationForm.h"
#include "UserAdoptionForm.h"
#include "NutritionPlan.h"
#include "ContactWindow.h"
#include <QPushButton>
#include <QPalette>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QLabel>

WeeklySportsActivities::WeeklySportsActivities(QWidget *parent)
    : QMainWindow(parent)
{
    // Set up the main layout
    QHBoxLayout *mainLayout = new QHBoxLayout(); // Main horizontal layout
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
      centralWidget->setStyleSheet("background-color: white;");

    // Sidebar layout
    QVBoxLayout *sidebarLayout = new QVBoxLayout();
    sidebarLayout->setSpacing(60);
    sidebarLayout->setAlignment(Qt::AlignTop);

    QWidget *sidebar = new QWidget(this);
    sidebar->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #555555, stop:1 #999999); border-right: 1px solid #ddd;");
    sidebar->setLayout(sidebarLayout);
    sidebarLayout->setAlignment(Qt::AlignTop);
    mainLayout->addWidget(sidebar);

    // Add icon to sidebar
    QLabel *iconLabel = new QLabel;
    QPixmap orphanageIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/Icon3.png");
    iconLabel->setPixmap(orphanageIcon);
    iconLabel->setScaledContents(true);
    iconLabel->setFixedSize(50, 50);
    iconLabel->move(0, 0);
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

    // Back button
    QPushButton *backButton = new QPushButton(this);
    backButton->setIcon(QIcon("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/IconBackArrow.png"));
    backButton->setIconSize(QSize(24, 24));
    backButton->setFixedSize(40, 40);
    backButton->setCursor(Qt::PointingHandCursor);
    connect(backButton, &QPushButton::clicked, this, &WeeklySportsActivities::goBackToLogin);
    sidebarLayout->addWidget(backButton);

    // Add sidebar layout to the main layout
    mainLayout->addLayout(sidebarLayout);

    // Vertical layout for sports activities content
    QVBoxLayout *sportsLayout = new QVBoxLayout(); // Vertical layout for sports activities content
    mainLayout->addLayout(sportsLayout);

    // Horizontal layout for the title label and search bar
    QHBoxLayout *titleSearchLayout = new QHBoxLayout();
    sportsLayout->addLayout(titleSearchLayout);

    QLabel *titleLabel = new QLabel("Weekly Sports Activities Schedule", this);
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    titleLabel->setFont(font);
    titleSearchLayout->addWidget(titleLabel);

    // Add search bar
    searchLineEdit = new QLineEdit(this);
    searchLineEdit->setPlaceholderText("Search...");
    searchLineEdit->setMaximumWidth(200);
    connect(searchLineEdit, &QLineEdit::textChanged, this, &WeeklySportsActivities::highlightSearchText);
    titleSearchLayout->addWidget(searchLineEdit);

    // Initialize grid layout
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(70);
    sportsLayout->addLayout(gridLayout);

    // Initialize text edits for each day
    setupDay("Monday", mondayTextEdit);
    setupDay("Tuesday", tuesdayTextEdit);
    setupDay("Wednesday", wednesdayTextEdit);
    setupDay("Thursday", thursdayTextEdit);
    setupDay("Friday", fridayTextEdit);
    setupDay("Saturday", saturdayTextEdit);

    // Add text edits to the grid layout
    gridLayout->addWidget(mondayTextEdit, 1, 0);
    gridLayout->addWidget(tuesdayTextEdit, 1, 1);
    gridLayout->addWidget(wednesdayTextEdit, 1, 2);
    gridLayout->addWidget(thursdayTextEdit, 2, 0);
    gridLayout->addWidget(fridayTextEdit, 2, 1);
    gridLayout->addWidget(saturdayTextEdit, 2, 2);

    // Load activities from file
    loadActivitiesFromFile();
    setWindowTitle("Weekly Sports Activities");
    resize(810,650);
}


void WeeklySportsActivities::setupDay(const QString &dayName, QTextEdit *&textEdit)
{
    // Create QTextEdit for the day's activities
    textEdit = new QTextEdit(this);
    textEdit->setStyleSheet("QTextEdit { background-color: #DDDDDD; border: 1px solid grey; border-radius: 10px; padding: 10px; }"
                            "QTextEdit::title { font-size: 20pt; }"); // Increase font size for title to 20pt
    textEdit->setReadOnly(true);

    // Set the day name as the title of the QTextEdit
    textEdit->setWindowTitle(dayName);
}



void WeeklySportsActivities::loadActivitiesFromFile() {
    QFile file("C:/Users/syeda jabeen ali/OneDrive/Documents/OurProject/WeeklySportActivities_schedule.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(": ");
        if (parts.size() == 2) {
            QString day = parts[0].trimmed();
            QString activities = parts[1].trimmed();

            // Update the text edit content based on the day
            QTextEdit *textEdit = nullptr;
            if (day == "Monday")
                textEdit = mondayTextEdit;
            else if (day == "Tuesday")
                textEdit = tuesdayTextEdit;
            else if (day == "Wednesday")
                textEdit = wednesdayTextEdit;
            else if (day == "Thursday")
                textEdit = thursdayTextEdit;
            else if (day == "Friday")
                textEdit = fridayTextEdit;
            else if (day == "Saturday")
                textEdit = saturdayTextEdit;

            if (textEdit) {
                // Add the day name in bold and start a new line
                QString formattedText = "<b>" + day + "</b>:";
                QStringList activityList = activities.split(", ");
                for (const QString& activity : activityList) {
                    formattedText += "<br>" + formatActivity(activity);
                }
                textEdit->setHtml(formattedText);
            }
        }
    }

    file.close();
}

QString WeeklySportsActivities::formatActivity(const QString& activity) {
    QStringList parts = activity.split(", ");
    QString formattedActivity;
    for (const QString& part : parts) {
        QString label = part.section(" = ", 0, 0); // Extract label before "="
        QString value = part.section(" = ", 1);   // Extract value after "="
        formattedActivity += label + ": " + value + "<br>";
    }
    return formattedActivity;
}

WeeklySportsActivities::~WeeklySportsActivities()
{
}

void WeeklySportsActivities::highlightSearchText(const QString& searchText) {
    // Highlight the search text in the displayed information
    QList<QTextEdit *> textEdits = findChildren<QTextEdit *>();
    for (QTextEdit *textEdit : textEdits) {
        QString text = textEdit->toPlainText();
        int index = text.indexOf(searchText, 0, Qt::CaseInsensitive);
        QTextCursor cursor = textEdit->textCursor();
        cursor.clearSelection();
        while (index >= 0) {
            cursor.setPosition(index);
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, searchText.length());
            QTextCharFormat format;
            format.setBackground(Qt:: blue);
            cursor.mergeCharFormat(format);
            index = text.indexOf(searchText, index + 1, Qt::CaseInsensitive);
        }
    }
}


void WeeklySportsActivities::goBackToLogin()
{
    QPoint currentPos = this->pos();
    close();
    Login *login = new Login();
    login->move(currentPos);
    login->show();
}


QPushButton* WeeklySportsActivities::createSidebarButton(const QString &text, const QString &iconPath)
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
        connect(button, &QPushButton::clicked, this, &WeeklySportsActivities::openOrphansInfo);
    } else if (text == "Donate") {
        connect(button, &QPushButton::clicked, this, &WeeklySportsActivities::openDonationForm);
    } else if (text == "Adoption Request") {
        connect(button, &QPushButton::clicked, this, &WeeklySportsActivities::openAdoptionForm);
    } else if (text == "Weekly Sports Activities") {
        connect(button, &QPushButton::clicked, this, &WeeklySportsActivities::openWeeklySportsActivities);
    } else if (text == "Contact") {
        connect(button, &QPushButton::clicked, this, &WeeklySportsActivities::openContact);
    }

    return button;
}

void WeeklySportsActivities::openOrphansInfo() {
       this->close();
    // Create an instance of the OrphansInfoWindow
    User_OrphansInfoWindow *user_OrphansInfoWindow = new User_OrphansInfoWindow(this);
    user_OrphansInfoWindow->show();
}

void WeeklySportsActivities::openDonationForm()
{
    this->close();
    // Create an instance of the DonationForm
    UserDonationForm *userDonationForm = new UserDonationForm(this);
    userDonationForm->show();
}

void WeeklySportsActivities::openAdoptionForm()
{
    this->close();

    // Create an instance of the UserAdoptionForm
    UserAdoptionForm *userAdoptionForm = new UserAdoptionForm(this);
    userAdoptionForm->show();

}

void WeeklySportsActivities::openWeeklySportsActivities()
{
    this->close();

    // Create an instance of the SportsActivitiesWindow
    WeeklySportsActivities *weeklySportsActivities = new WeeklySportsActivities(this);
    weeklySportsActivities->show();
}


void WeeklySportsActivities::openContact()
{
    this->close();

    // Create an instance of the ContactWindow
    ContactWindow *contactWindow = new ContactWindow(this);
    contactWindow->show();
}
