#ifndef WEEKLYSPORTSACTIVITIES_H
#define WEEKLYSPORTSACTIVITIES_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class WeeklySportsActivities : public QMainWindow
{
    Q_OBJECT

public:
    explicit WeeklySportsActivities(QWidget *parent = nullptr);
    ~WeeklySportsActivities();

private slots:
    void highlightSearchText(const QString& searchText);
    void openOrphansInfo();
    void goBackToLogin();
    void openDonationForm();
    void openAdoptionForm();
    void openWeeklySportsActivities();
    void openContact();

private:
    QPushButton* createSidebarButton(const QString &text, const QString &iconPath);
    QVBoxLayout *sidebarLayout;
    QPushButton *backButton;
     QWidget *sidebar;
     QLabel *iconLabel;
    QHBoxLayout *mainLayout;
    QLineEdit *searchLineEdit;
    QTextEdit *mondayTextEdit;
    QTextEdit *tuesdayTextEdit;
    QTextEdit *wednesdayTextEdit;
    QTextEdit *thursdayTextEdit;
    QTextEdit *fridayTextEdit;
    QTextEdit *saturdayTextEdit;
    void setupDay(const QString &dayName, QTextEdit *&textEdit);

    void loadActivitiesFromFile();
    QString formatActivity(const QString& activity);


};

#endif // WEEKLYSPORTSACTIVITIES_H
