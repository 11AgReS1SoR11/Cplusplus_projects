#ifndef DISMISSAL_OF_EMPLOYEE_H
#define DISMISSAL_OF_EMPLOYEE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <DanialDatabasaLib.h>

namespace Ui {
class Dismissal_of_employee;
}

class Dismissal_of_employee : public QWidget
{
    Q_OBJECT

public:
    explicit Dismissal_of_employee(QWidget *parent = nullptr);
    ~Dismissal_of_employee();
    bool TakeData(QString& Name, QString& Position, QString& Department, QString& DateEnd);
    void AddDateEnd(QString& Name, QString& DateEnd, QString& Position, QString& Department);

private slots:
    void updateComboBox();
    void on_pushButton_clicked();

private:
    Ui::Dismissal_of_employee *ui;
    QSqlDatabase db;
};

#endif // DISMISSAL_OF_EMPLOYEE_H
