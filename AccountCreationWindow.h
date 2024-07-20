#ifndef ACCOUNTCREATIONWINDOW_H
#define ACCOUNTCREATIONWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

class AccountCreationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountCreationWindow(QWidget *parent = nullptr);
    ~AccountCreationWindow();

signals:
    void accountCreated();

private slots:
    void createAccountClicked();

private:
    QLineEdit *usernameEdit;
    QLineEdit *emailEdit;
    QLineEdit *phoneEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmPasswordEdit;
    QCheckBox *termsCheckBox;
    QPushButton *createAccountButton;
};

#endif // ACCOUNTCREATIONWINDOW_H
