#include "actions.h"
#include "ui_actions.h"

Actions::Actions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Actions)
{
    ui->setupUi(this);
    setWindowTitle("Actions");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                               "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                    "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                    "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                    "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_5->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                    "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                    "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                    "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_8->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                    "QPushButton:hover { border: 2px solid #FF00FF; }");
}

Actions::~Actions()
{
    delete ui;
}

void Actions::on_pushButton_clicked()
{
    win_with_employeeregistration.show();
}


void Actions::on_pushButton_3_clicked()
{
    win_with_dismissalofemployee.show();
}


void Actions::on_pushButton_6_clicked()
{
    win_with_addingcontract.show();
}


void Actions::on_pushButton_7_clicked()
{
    win_with_executioncontract.show();
}


void Actions::on_pushButton_8_clicked()
{
    win_with_contractfullfillment.show();
}


void Actions::on_pushButton_5_clicked()
{
    win_with_addingallowance.show();
}


void Actions::on_pushButton_4_clicked()
{
    win_with_assignallowance.show();
}


void Actions::on_pushButton_2_clicked()
{
    win_with_changerate.show();
}

