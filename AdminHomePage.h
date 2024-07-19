#ifndef ADMINHOMEPAGE_H
#define ADMINHOMEPAGE_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>

class QPushButton;

class AdminHomepage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminHomepage(QWidget *parent = nullptr);

private:
    QPushButton* createSidebarButton(const QString &text, const QString &iconPath);
     QVBoxLayout *sidebarLayout;
    QPushButton *backButton;
    void applyAnimation(QPushButton *button, int duration, qreal startOpacity, qreal endOpacity); // New private function declaration
    QStackedWidget *stackedWidget;

private slots:
    void openOrphanRegistrationForm();
    void goBackToLogin();
    void openOrphansInfo();
    void openEmployeesInfo();
    void openAdoptionRequests();
    void openManageDonations();
};

#endif // ADMINHOMEPAGE_H
