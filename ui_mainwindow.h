#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(C:/Users/syeda jabeen ali/Documents/OurProject/OrphanPic.png);\n"
                                                       ""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(50, 50));
        label->setAutoFillBackground(true);
        label->setPixmap(QPixmap(QString::fromUtf8("Icon.png")));
        label->setScaledContents(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 140, 150, 30));
        pushButton->setMinimumSize(QSize(150, 30));
        pushButton->setStyleSheet(QString::fromUtf8("<styleSheet>\n"
                                                    "    QPushButton {\n"
                                                    "        background-color: blue;\n"
                                                    "        color: white;\n"
                                                    "    }\n"
                                                    "</styleSheet>\n"
                                                    ""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 200, 150, 30));
        pushButton_2->setMinimumSize(QSize(150, 30));
        pushButton_2->setStyleSheet(QString::fromUtf8("<styleSheet>\n"
                                                      "    QPushButton {\n"
                                                      "        background-color: blue;\n"
                                                      "        color: white;\n"
                                                      "    }\n"
                                                      "</styleSheet>\n"
                                                      ""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 260, 150, 30));
        pushButton_3->setMinimumSize(QSize(150, 30));
        pushButton_3->setStyleSheet(QString::fromUtf8("<styleSheet>\n"
                                                      "    QPushButton {\n"
                                                      "        background-color: blue;\n"
                                                      "        color: white;\n"
                                                      "    }\n"
                                                      "</styleSheet>\n"
                                                      ""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 320, 150, 30));
        pushButton_4->setMinimumSize(QSize(150, 30));
        pushButton_4->setStyleSheet(QString::fromUtf8("<styleSheet>\n"
                                                      "    QPushButton {\n"
                                                      "        background-color: blue;\n"
                                                      "        color: white;\n"
                                                      "    }\n"
                                                      "</styleSheet>\n"
                                                      ""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 380, 150, 30));
        pushButton_5->setMinimumSize(QSize(150, 30));
        pushButton_5->setStyleSheet(QString::fromUtf8("<styleSheet>\n"
                                                      "    QPushButton {\n"
                                                      "        background-color: blue;\n"
                                                      "        color: white;\n"
                                                      "    }\n"
                                                      "</styleSheet>\n"
                                                      ""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 50, 191, 50));
        label_2->setMinimumSize(QSize(50, 50));
        label_2->setTextFormat(Qt::RichText);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Orphan Registration", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Orphans Info", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Manage Donations", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Adoption Requests", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Employees Info", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:700;\">Orphanage Center</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
