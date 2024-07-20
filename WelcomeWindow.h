#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *pictureLabel;
    QLabel *textLabel;
    QFrame *line;
    QPushButton *button;
    QPushButton *backButton;

private slots:
    void openLoginWindow();
    void goBack();
};

#endif // MAINWINDOW_H
