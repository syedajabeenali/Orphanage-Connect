#ifndef USERHOMEPAGE_H
#define USERHOMEPAGE_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>

class QPushButton;

class UserHomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserHomePage(QWidget *parent = nullptr);

private:
     QPushButton* createSidebarButton(const QString &text, const QString &iconPath);
     void applyAnimation(QPushButton *button, int duration, qreal startOpacity, qreal endOpacity);
      QVBoxLayout *sidebarLayout;
       QPushButton *backButton;
     QStackedWidget *stackedWidget;

 private slots:
    void openOrphansInfo();
     void goBackToLogin();
    void openDonationForm();
    void openAdoptionForm();
    void openWeeklySportsActivities();
    void openContact();
};

#endif // USERHOMEPAGE_H
