#ifndef ASSIGNALLOWANCE_H
#define ASSIGNALLOWANCE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <DanialDatabasaLib.h>

namespace Ui {
class AssignAllowance;
}

class AssignAllowance : public QWidget
{
    Q_OBJECT

public:
    explicit AssignAllowance(QWidget *parent = nullptr);
    ~AssignAllowance();
    bool TakeData(QString& Name, QString& Allowance, QString& Reward, QString &Date);
    void AddWorkerAllowance(const QString& Name, const QString& Allowance, const QString& Reward, const QString& Date);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AssignAllowance *ui;
    QSqlDatabase db;
};

#endif // ASSIGNALLOWANCE_H
