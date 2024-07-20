#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>


class UserDonationForm : public QMainWindow
{
    Q_OBJECT

public:
    UserDonationForm(QWidget *parent = nullptr);
    ~UserDonationForm();

private:
    QPushButton* createSidebarButton(const QString &text, const QString &iconPath);
    QVBoxLayout *sidebarLayout;
    QPushButton *backButton;
    QLineEdit *nameEdit;
    QLineEdit *emailEdit;
    QLineEdit *donationEdit;
    QLineEdit *donationAmountEdit; // Added line for donation
    QComboBox *paymentMethodComboBox;
    QTextEdit *commentsTextEdit;

private slots:
    void submitDonation();
    void openOrphansInfo();
    void goBackToLogin();
    void openDonationForm();
    void openAdoptionForm();
    void openWeeklySportsActivities();
    void openContact();


};
