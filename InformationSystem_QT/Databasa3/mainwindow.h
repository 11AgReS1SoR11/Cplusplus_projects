#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Actions.h>
#include <Reports.h>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Actions_clicked();
    void on_Reports_clicked();

private:
    Ui::MainWindow *ui;
    Actions win_with_actions;
    Reports win_with_reports;
};
#endif // MAINWINDOW_H
