#ifndef EXECUTIONCONTRACT_H
#define EXECUTIONCONTRACT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <DanialDatabasaLib.h>

namespace Ui {
class ExecutionContract;
}

class ExecutionContract : public QWidget
{
    Q_OBJECT

public:
    explicit ExecutionContract(QWidget *parent = nullptr);
    ~ExecutionContract();
    bool TakeData(QString& Name, QString& Contract, QString& Reward, QString& DateStart);
    void AddWorkerContract(const QString& Name, const QString& Contract, const QString& Reward, const QString& DateStart);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ExecutionContract *ui;
    QSqlDatabase db;
};

#endif // EXECUTIONCONTRACT_H
