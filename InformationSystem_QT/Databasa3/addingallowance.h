#ifndef ADDINGALLOWANCE_H
#define ADDINGALLOWANCE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <DanialDatabasaLib.h>

namespace Ui {
class AddingAllowance;
}

class AddingAllowance : public QWidget
{
    Q_OBJECT

public:
    explicit AddingAllowance(QWidget *parent = nullptr);
    ~AddingAllowance();
    bool TakeData(QString& Name, QString& Reward);
    void AddAllowance(const QString& Name, const QString& Reward);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddingAllowance *ui;
    QSqlDatabase db;
};

#endif // ADDINGALLOWANCE_H
