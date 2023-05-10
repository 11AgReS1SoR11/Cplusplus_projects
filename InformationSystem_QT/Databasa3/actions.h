#ifndef ACTIONS_H
#define ACTIONS_H

#include <QWidget>
#include <EmployeeRegistration.h>
#include <dismissal_of_employee.h>
#include <addingcontract.h>
#include <executioncontract.h>
#include <contractfulfillment.h>
#include <addingallowance.h>
#include <assignallowance.h>
#include <changerate.h>

namespace Ui {
class Actions;
}

class Actions : public QWidget
{
    Q_OBJECT

public:
    explicit Actions(QWidget *parent = nullptr);
    ~Actions();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Actions *ui;
    EmployeeRegistration win_with_employeeregistration;
    Dismissal_of_employee win_with_dismissalofemployee;
    AddingContract win_with_addingcontract;
    ExecutionContract win_with_executioncontract;
    ContractFulfillment win_with_contractfullfillment;
    AddingAllowance win_with_addingallowance;
    AssignAllowance win_with_assignallowance;
    ChangeRate win_with_changerate;
};

#endif // ACTIONS_H
