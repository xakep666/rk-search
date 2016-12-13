#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_validateButton_clicked();


    void on_speedButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
