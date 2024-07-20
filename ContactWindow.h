#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPixmap>
#include <QMap>
#include <QString>
#include <QVector>
#include <QVBoxLayout>
#include <QPushButton>

class ContactWindow : public QMainWindow
{
    Q_OBJECT

public:
    ContactWindow(QWidget *parent = nullptr);
    ~ContactWindow();

private:
    void loadContactsFromFile();
    void displayContacts();

    QLabel *titleLabel;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QTextEdit *contactDetailsTextEdit;
    QVBoxLayout *mainLayout;
    QHBoxLayout *searchLayout;
    QVBoxLayout *contactLayout; // Changed from QGridLayout to QVBoxLayout
    QPixmap orphanageImage;

    QMap<QString, QVector<QString>> contacts;

    QPushButton* createSidebarButton(const QString &text, const QString &iconPath);
    QVBoxLayout *sidebarLayout;
    QPushButton *backButton;

private slots:
    void searchContacts();
    void openOrphansInfo();
    void goBackToLogin();
    void openDonationForm();
    void openAdoptionForm();
    void openWeeklySportsActivities();
    void openContact();
};

#endif // CONTACTWINDOW_H
