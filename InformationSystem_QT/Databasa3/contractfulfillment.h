#ifndef CONTRACTFULFILLMENT_H
#define CONTRACTFULFILLMENT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <DanialDatabasaLib.h>

namespace Ui {
class ContractFulfillment;
}

class ContractFulfillment : public QWidget
{
    Q_OBJECT

public:
    explicit ContractFulfillment(QWidget *parent = nullptr);
    ~ContractFulfillment();
    bool TakeData(QString& Name, QString& Contract, QString& Reward, QString& DateEnd);
    void AddDateEnd(const QString& Name, const QString& Contract, const QString& Reward, const QString& DateEnd);

private slots:
    void on_pushButton_clicked();
    void UpdateContracts();

private:
    Ui::ContractFulfillment *ui;
    QSqlDatabase db;
};

#endif // CONTRACTFULFILLMENT_H
