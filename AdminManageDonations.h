#ifndef ADMIN_MANAGE_DONATIONS_H
#define ADMIN_MANAGE_DONATIONS_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QHBoxLayout>
#include <QPushButton>

class AdminManageDonations : public QMainWindow {
    Q_OBJECT

public:
    explicit AdminManageDonations(QWidget *parent = nullptr);
    ~AdminManageDonations();

private:

    void displayDonor(const QString &donorInfo, QVBoxLayout *contentLayout);
    void displayDonorDetails(QVBoxLayout *contentLayout);
    void displayExpenditureDetails(QVBoxLayout *contentLayout);
    QPushButton* createSidebarButton(const QString &text, const QString &iconPath);
    QVBoxLayout *sidebarLayout;
    QPushButton *backButton;
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    void displayDonor(const QString &donorInfo);

private slots:
    void openOrphanRegistrationForm();
    void goBackToLogin();
    void openOrphansInfo();
    void openEmployeesInfo();
    void openAdoptionRequests();
    void openManageDonations();
};

#endif // ADMIN_MANAGE_DONATIONS_H
