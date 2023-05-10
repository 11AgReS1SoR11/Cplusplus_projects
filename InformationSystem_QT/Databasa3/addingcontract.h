#ifndef ADDINGCONTRACT_H
#define ADDINGCONTRACT_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <DanialDatabasaLib.h>

namespace Ui {
class AddingContract;
}

class AddingContract : public QWidget
{
    Q_OBJECT

public:
    explicit AddingContract(QWidget *parent = nullptr);
    ~AddingContract();
    bool TakeData(QString& Name, QString& Reward);
    void AddContract(const QString& Name, const QString& Reward);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddingContract *ui;
    QSqlDatabase db;
};

#endif // ADDINGCONTRACT_H
