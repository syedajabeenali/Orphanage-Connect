#ifndef ORPHANREGISTRATIONFORM_H
#define ORPHANREGISTRATIONFORM_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QPushButton>

class OrphanRegistrationForm : public QMainWindow
{
    Q_OBJECT

public:
    OrphanRegistrationForm(QWidget *parent = nullptr);
    ~OrphanRegistrationForm();

private slots:
    void selectImage();
    void goBackToLogin();
    void submitButtonClicked();
    void openOrphanRegistrationForm();
    void openOrphansInfo();
    void openEmployeesInfo();
    void openAdoptionRequests();
    void openManageDonations();

private:

      QPushButton *backButton;
     QPushButton *selectImageButton ;
    QPushButton* createSidebarButton(const QString &text , const QString &iconPath);
    QLineEdit *nameLineEdit;
    QSpinBox *ageSpinBox;
    QString selectedImagePath;
    QComboBox *genderComboBox;
    QDateEdit *dobDateEdit;
    QLineEdit *allergiesLineEdit;
    QLineEdit *conditionsLineEdit;
    QLineEdit *relationshipLineEdit;
    QLineEdit *contactLineEdit;
    QPlainTextEdit *commentsPlainTextEdit;
    QPushButton *submitButton;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
};

#endif // ORPHANREGISTRATIONFORM_H
