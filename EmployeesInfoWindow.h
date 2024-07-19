#ifndef EMPLOYEESINFOWINDOW_H
#define EMPLOYEESINFOWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "OrphanRegistrationForm.h" // Include the header for OrphanRegistrationForm

class EmployeesInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeesInfoWindow(QWidget *parent = nullptr);
    ~EmployeesInfoWindow();

private:
    QVBoxLayout *mainLayout;
    QPushButton *backButton;
    void displayEmployeeInfo(const QString& data, QVBoxLayout* mainLayout);
    QPushButton* createSidebarButton(const QString &text, const QString &iconPath);
    void setupTopLayout();
    void setupSidebar();
    void setupEmployeeInfo();

private slots:
    void goBackToLogin();
    void openOrphanRegistrationForm();
    void openOrphansInfo();
    void openEmployeesInfo();
    void openAdoptionRequests();
    void openManageDonations();
};

#endif // EMPLOYEESINFOWINDOW_H
