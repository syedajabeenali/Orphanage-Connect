#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void userSignInClicked();
    void adminSignInClicked();
    void signInClicked();
    void openAccountCreationWindow();

private:
    QPushButton *userSignInButton;
    QPushButton *adminSignInButton;


    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;

};

#endif // LOGIN_H
