#ifndef ADMIN_ADOPTIONREQUEST_H
#define ADMIN_ADOPTIONREQUEST_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QStringList>
#include <QPushButton>

class AdoptionRequest : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdoptionRequest(QWidget *parent = nullptr);
    ~AdoptionRequest();

private slots:
     void goBackToLogin();
    void acceptRequest();
    void rejectRequest();
    void openOrphanRegistrationForm();
    void openOrphansInfo();
    void openEmployeesInfo();
    void openManageDonations();
    void openAdoptionRequests();

private:
     QPushButton *backButton;
    void createSidebar(QHBoxLayout *mainLayout);
    void createRequestWidgets(QVBoxLayout *requestLayout);
    void loadRequestsFromFile(const QString &fileName);
    QPushButton* createSidebarButton(const QString &text,  const QString &iconPath);

    void removeAdoptedChildData(const QString &adoptedChildName);
    void updateFile();

    QFile *file;
    QList<QStringList> requestsData;
};

#endif // ADMIN_ADOPTIONREQUEST_H
