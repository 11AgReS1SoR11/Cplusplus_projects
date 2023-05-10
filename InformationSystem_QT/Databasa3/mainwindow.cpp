#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Information sistem");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->Title->setStyleSheet("color: rgb(230, 230, 230)");
    ui->Reports->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->Actions->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Actions_clicked()
{
    hide();
    win_with_actions.show();
}


void MainWindow::on_Reports_clicked()
{
    hide();
    win_with_reports.show();
}

