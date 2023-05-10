#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>
#include <DanialDatabasaLib.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class Reports;
}

class Reports : public QWidget
{
    Q_OBJECT

public:
    explicit Reports(QWidget *parent = nullptr);
    ~Reports();
    bool TakeData(QString& Name, QString& DateStart, QString& DateEnd);
    bool TakeData(QString& Name, QString& Date);

private slots:
    void on_Return_clicked();
    void onPaySheetClicked();
    void onYearUpClicked();
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::Reports *ui;
    QSqlDatabase db;
};

#endif // REPORTS_H
