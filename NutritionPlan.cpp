// #include "NutritionPlan.h"
// #include <QFile>
// #include <QTextStream>
// #include <QDebug>
// #include <QLabel>
// #include <QHBoxLayout>
// #include <QVBoxLayout>
// #include <QTextEdit>
// #include <QPixmap> // Add this line to include QPixmap class

// NutritionPlan::NutritionPlan(QWidget *parent)
//     : QMainWindow(parent)
// {
//     // Set up the main layout
//     QVBoxLayout *mainLayout = new QVBoxLayout();
//     QWidget *centralWidget = new QWidget(this);
//     centralWidget->setLayout(mainLayout);
//     setCentralWidget(centralWidget);

//     // Add the search bar at the top
//     QHBoxLayout *searchLayout = new QHBoxLayout();
//     mainLayout->addLayout(searchLayout);

//     searchLineEdit = new QLineEdit(this);
//     searchLineEdit->setPlaceholderText("Search...");
//     searchLineEdit->setMaximumWidth(200);
//     connect(searchLineEdit, &QLineEdit::textChanged, this, &NutritionPlan::highlightSearchText);
//     searchLayout->addWidget(searchLineEdit);
//     searchLayout->addStretch(); // Add stretchable space to the right
//     // Add the text "Weekly Nutrition Plan" below the picture
//     QLabel *titleLabel = new QLabel("Weekly Nutrition Plan", this);
//     QFont titleFont;
//     titleFont.setPointSize(30); // Adjust the font size as needed
//     titleFont.setBold(true);
//     titleLabel->setFont(titleFont);
//     titleLabel->setAlignment(Qt::AlignLeft);
//     mainLayout->addWidget(titleLabel);

//     // Create a QHBoxLayout for the pictures
//     QHBoxLayout *picturesLayout = new QHBoxLayout();
//     mainLayout->addLayout(picturesLayout);
//     // Add the first picture
//     QPixmap pixmap1(R"(C:\Users\user\Documents\Nutrition\nutrition_picture.jpg)"); // Replace with the path to your image
//     int width1 = 300; // Adjust the width as needed
//     int height1 = 200; // Adjust the height as needed
//     pixmap1 = pixmap1.scaled(width1, height1); // Scale while preserving aspect ratio
//     QLabel *pictureLabel1 = new QLabel(this);
//     pictureLabel1->setPixmap(pixmap1);
//     pictureLabel1->setAlignment(Qt::AlignCenter);
//     picturesLayout->addWidget(pictureLabel1);

//     // Add the second picture
//     QPixmap pixmap2(R"(C:\Users\user\Documents\Nutrition\center.jpg)"); // Replace with the path to your image
//     int width2 = 400; // Adjust the width as needed
//     int height2 = 200; // Adjust the height as needed
//     pixmap2 = pixmap2.scaled(width2, height2); // Scale while preserving aspect ratio
//     QLabel *pictureLabel2 = new QLabel(this);
//     pictureLabel2->setPixmap(pixmap2);
//     pictureLabel2->setAlignment(Qt::AlignCenter);
//     picturesLayout->addWidget(pictureLabel2);

//     // Add the third picture (larger one in the center)
//     QPixmap pixmap3(R"(C:\Users\user\Documents\Nutrition\nutrition_picture.jpg)"); // Replace with the path to your image
//     int width3 = 300; // Adjust the width as needed
//     int height3 = 200; // Adjust the height as needed
//     pixmap3 = pixmap3.scaled(width3, height3); // Scale while preserving aspect ratio
//     QLabel *pictureLabel3 = new QLabel(this);
//     pictureLabel3->setPixmap(pixmap3);
//     pictureLabel3->setAlignment(Qt::AlignCenter);
//     picturesLayout->addWidget(pictureLabel3);

//     // Second line: Days in blue boxes
//     QHBoxLayout *daysLayout = new QHBoxLayout();
//     mainLayout->addLayout(daysLayout);

//     QStringList dayNames = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//     QString backgroundColor = "#4682B4"; // Steel Blue color

//     for (int i = 0; i < dayNames.size(); ++i) {
//         QLabel *dayLabel = new QLabel(dayNames[i], this);
//         QString textColor = "white"; // You can adjust the text color as needed
//         dayLabel->setStyleSheet(QString("background-color: %1; color: %2; font-weight: bold; font-size: 18px; padding: 5px;").arg(backgroundColor).arg(textColor));
//         daysLayout->addWidget(dayLabel);
//     }

//     // Third line onwards: Load activities from file and display in light grey boxes
//     loadActivitiesFromFile();

// }

// void NutritionPlan::loadActivitiesFromFile() {
//     QFile file("C:/Users/user/Documents/Nutrition/nutritionfile.txt");
//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         qDebug() << "Could not open file for reading:" << file.errorString();
//         return;
//     }

//     QTextStream in(&file);
//     int dayIndex = 0;
//     QString backgroundColor = "#DCDCDC"; // Basic shade of grey

//     while (!in.atEnd() && dayIndex < 6) {
//         QString line = in.readLine();
//         QStringList parts = line.split(": ");
//         if (parts.size() == 2) {
//             QString activities = parts[1].trimmed();

//             // Split activities into breakfast, lunch, and dinner
//             QStringList mealActivities = activities.split("; ");

//             // Create layout for the row
//             QVBoxLayout *dayLayout = new QVBoxLayout();
//             QHBoxLayout *mealActivitiesLayout = new QHBoxLayout();
//             dayLayout->addLayout(mealActivitiesLayout);

//             // Create boxes for meal activities
//             foreach (const QString &mealActivity, mealActivities) {
//                 QTextEdit *mealTextEdit = new QTextEdit(this);
//                 mealTextEdit->setStyleSheet("background-color: " + backgroundColor + "; border: 1px solid; border-radius: 10px; padding: 10px; font-size: 14px; font-family: Arial;");
//                 mealTextEdit->setReadOnly(true);
//                 mealTextEdit->setText(mealActivity);
//                 mealActivitiesLayout->addWidget(mealTextEdit);
//             }

//             QWidget *centralWidgetPtr = dynamic_cast<QWidget*>(centralWidget());
//             if (centralWidgetPtr) {
//                 QVBoxLayout *mainLayout = dynamic_cast<QVBoxLayout*>(centralWidgetPtr->layout());
//                 if (mainLayout) {
//                     mainLayout->addLayout(dayLayout);
//                 } else {
//                     qDebug() << "Main layout is not QVBoxLayout, cannot add dayLayout.";
//                 }
//             } else {
//                 qDebug() << "Central widget is not a QWidget.";
//             }



//             dayIndex++;
//         }
//     }

//     file.close();
// }

// void NutritionPlan::highlightSearchText(const QString& searchText) {
//     // Highlight the search text in the displayed information
//     QList<QLabel *> labels = findChildren<QLabel *>();
//     for (QLabel *label : labels) {
//         QString text = label->text();
//         int index = text.indexOf(searchText, 0, Qt::CaseInsensitive);
//         if (index >= 0) {
//             QString styledText = "<span style='background-color: yellow;'>" + searchText + "</span>";
//             text.replace(searchText, styledText);
//             label->setText(text);
//         }
//     }
// }
