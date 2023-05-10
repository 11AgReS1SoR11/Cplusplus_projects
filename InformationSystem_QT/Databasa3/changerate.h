#ifndef CHANGERATE_H
#define CHANGERATE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <DanialDatabasaLib.h>

namespace Ui {
class ChangeRate;
}

class ChangeRate : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeRate(QWidget *parent = nullptr);
    ~ChangeRate();
    bool TakeData(QString& NewRate, QString& Position, QString& Department, QString& DateEnd);
    void AddDateEnd(const QString& NewRate, const QString& Position, const QString& Department, const QString& DateEnd);


private slots:
    void on_pushButton_clicked();
    void UpdateLastRate();

private:
    Ui::ChangeRate *ui;
    QSqlDatabase db;
};

#endif // CHANGERATE_H
