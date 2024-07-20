#ifndef ORPHANSINFOWINDOW_H
#define ORPHANSINFOWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "OrphanRegistrationForm.h" // Include the header for OrphanRegistrationForm

class OrphansInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrphansInfoWindow(QWidget *parent = nullptr);
    ~OrphansInfoWindow();

private:
    QVBoxLayout *mainLayout;
     QPushButton *backButton;
    void displayOrphanInfo(const QString& data, QVBoxLayout* mainLayout);
    void highlightSearchText(const QString& searchText);
    void readJsonDataFromFile(const QString& filePath, QVBoxLayout* mainLayout);
    QPushButton* createSidebarButton(const QString &text , const QString &iconPath);
    void setupTopLayout();
    void setupSidebar();

private slots:
    void goBackToLogin();
    void openOrphanRegistrationForm();
    void openOrphansInfo();
    void openAdoptionRequests();
    void openEmployeesInfo();
    void openManageDonations();
};

#endif // ORPHANSINFOWINDOW_H
