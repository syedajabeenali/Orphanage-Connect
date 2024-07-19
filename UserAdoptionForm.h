#ifndef USERADOPTIONFORM_H
#define USERADOPTIONFORM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class UserAdoptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserAdoptionForm(QWidget *parent = nullptr);
    ~UserAdoptionForm();

private slots:
    void handleSubmit();
    void openOrphansInfo();
    void goBackToLogin();
    void openDonationForm();
    void openAdoptionForm();
    void openWeeklySportsActivities();
    void openContact();

private:
     QPushButton* createSidebarButton(const QString &text, const QString &iconPath);
    void addLabelsAndLineEdits(const QStringList &labels, QVBoxLayout *layout);
    QVBoxLayout *sidebarLayout;
    QPushButton *backButton;

    QStringList getEnrolledOrphansNames();
    QVBoxLayout *layout;
    QList<QLineEdit *> lineEdits;
    QPushButton *submitButton;
};

#endif // USERADOPTIONFORM_H
