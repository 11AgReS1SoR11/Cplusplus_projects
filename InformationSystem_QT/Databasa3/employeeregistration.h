#ifndef EMPLOYEEREGISTRATION_H
#define EMPLOYEEREGISTRATION_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QPair>
#include <DanialDatabasaLib.h>

namespace Ui {
class EmployeeRegistration;
}

class EmployeeRegistration : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeRegistration(QWidget *parent = nullptr);
    ~EmployeeRegistration();
    bool TakeData(QString& Name, QString& Rate, QString& DateRegistration, QString& AmountChild, QString& Position, QString& Department, QVector<QPair<QString,QString>>& NameDateChildren);
    int AddWorker(const QString& Name, const QString& DateRegistration);
    void AddChildren(const QString& AmountChild, const QVector<QPair<QString,QString>>& NameDateChildren, const int Id);
    void AddWorker_Occupation(const QString& DateStart, const QString& Rate, const int IdWorker, const int IdOccupation);

private slots:
    void on_pushButton_clicked();

private:
    Ui::EmployeeRegistration *ui;
    QSqlDatabase db;
};

#endif // EMPLOYEEREGISTRATION_H
