#ifndef USER_ORPHANSINFOWINDOW_H
#define USER_ORPHANSINFOWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class User_OrphansInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit User_OrphansInfoWindow(QWidget *parent = nullptr);
    ~User_OrphansInfoWindow();

private:
    QVBoxLayout *mainLayout;
     QPushButton *backButton;
    void displayOrphanInfo(const QString& data, QVBoxLayout* mainLayout);
    void highlightSearchText(const QString& searchText);
    void readJsonDataFromFile(const QString& filePath, QVBoxLayout* mainLayout);
    QPushButton* createSidebarButton(const QString &text , const QString &iconPath);
    // void setupTopLayout();
    // void setupSidebar();

private slots:
    void goBackToLogin();
    void openOrphansInfo();
    void openDonationForm();
    void openAdoptionForm();
    void openWeeklySportsActivities();
    void openContact();
};

#endif // USER_ORPHANSINFOWINDOW_H
