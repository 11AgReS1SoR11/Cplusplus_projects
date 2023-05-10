#include "reports.h"
#include "ui_reports.h"
#include <mainwindow.h>
#include <QStackedWidget>
#include <QFile>
#include <QDir>

#include <QVector>
#include <cmath>
#include <QTextStream>

Reports::Reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reports)
{
    ui->setupUi(this);
    setWindowTitle("Reports");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->PaySheet->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_6->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->pushButton_7->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->Return->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                              "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->YearUp->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                              "QPushButton:hover { border: 2px solid #FF00FF; }");

    // Открываю базу данных
    if (!Connection_to_database(db)) return;
    QSqlQuery query = MyWorkers(db);
    while (query.next()){
        ui->FIO->addItem(query.value(0).toString());
        ui->FIO_2->addItem(query.value(0).toString());
    }

    connect(ui->PaySheet, &QPushButton::clicked, this, &Reports::onPaySheetClicked);
    connect(ui->YearUp, &QPushButton::clicked, this, &Reports::onYearUpClicked);
}

Reports::~Reports()
{
    delete ui;
}

void Reports::onPaySheetClicked(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Reports::onYearUpClicked(){
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(0);
}

void Reports::on_Return_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


bool Reports::TakeData(QString &Name, QString &DateStart, QString &DateEnd){
    Name = ui->FIO->currentText();
    DateStart = ui->DateStart->text();
    DateEnd = ui->DateEnd->text();

    if (!CheckForDate(DateStart) && !CheckForDate(DateEnd)){
        QMessageBox::warning(this, "Внимание", "Дата введена неверно");
        return false;
    }
    return true;
}

bool Reports::TakeData(QString &Name, QString &Date){
    Name = ui->FIO_2->currentText();
    Date = ui->Year->text();

    if (!CheckForNum(Date)){
        QMessageBox::warning(this, "Внимание", "Дата введена неверно");
        return false;
    }
    return true;
}


double TakeIncome(const QString& Name, const QString& DateStart, const QString& DateEnd, const QSqlDatabase& db){
    QSqlQuery query = QSqlQuery(db);
    query.exec(QString("select rate.dateend, rate.Rate, worker_occupation.partRate, worker_occupation.datestart, worker_occupation.dateend from rate inner join occupations using(idoccupation) inner join worker_occupation using(idoccupation) inner join workers using(idworker) where (workers.name = '%1') and ((rate.dateend is null) or (datediff(rate.dateend, '%2') > 0)) and ((worker_occupation.dateend is null) or (datediff(worker_occupation.dateend, '%2') > 0)) order by rate.dateend desc, worker_occupation.DateStart;").arg(Name).arg(DateStart));
    double Income = 0;
    QString RateEnd = "", Rate, PartRate, WorkStart, WorkEnd, PrevRateEnd;
    while(query.next()){
        PrevRateEnd = RateEnd;

        RateEnd = query.value(0).toString();
        Rate = query.value(1).toString();
        PartRate = query.value(2).toString();
        WorkStart = query.value(3).toString();
        WorkEnd = query.value(4).toString();

        if (PrevRateEnd != "" && DateDiff(PrevRateEnd, DateEnd) < 0){
            RateEnd = "";
            qDebug() << "Next";
            continue; //перейти к следующей работе
        }
        int days = DateDiff(MaxDate(WorkStart, MaxDate(DateStart, PrevRateEnd)), MinDate(RateEnd, MinDate(DateEnd, WorkEnd))) < 0 ? 0 : DateDiff(MaxDate(WorkStart, MaxDate(DateStart, PrevRateEnd)), MinDate(RateEnd, MinDate(DateEnd, WorkEnd)));
        Income += days * PartRate.toDouble() * Rate.toDouble() / 30;
    }
    return std::floor(Income * 100) / 100;
}

double TakeSumContracts(const QString& Name, const QString& DateStart, const QString& DateEnd, const QSqlDatabase& db){
    QSqlQuery query = QSqlQuery(db);
    query.exec(QString("select sum(contracts.Reward), workers.name from contracts inner join worker_contract using(idcontract) inner join workers using(idworker) where (worker_contract.dateend is not null) and (datediff(worker_contract.dateend, '%2') <= 0) and (datediff(worker_contract.dateend, '%3') >= 0) and (workers.name = '%1') group by workers.name;").arg(Name).arg(DateEnd).arg(DateStart));
    double Income = 0;
    while(query.next()){
        Income = query.value(0).toDouble();
    }
    return Income;
}

double TakeSumAllowance(const QString& Name, const QString& DateStart, const QString& DateEnd, const QSqlDatabase& db){
    QSqlQuery query = QSqlQuery(db);
    query.exec(QString("select sum(allowance.Reward), workers.name from allowance inner join worker_allowance using(idallowance) inner join workers using(idworker) where datediff(worker_allowance.date, '%1') <= 0  and datediff(worker_allowance.date, '%2') >= 0 and workers.name = '%3' group by workers.name;").arg(DateEnd).arg(DateStart).arg(Name));
    double Income = 0;
    while(query.next()){
        Income = query.value(0).toDouble();
    }
    return Income;
}

int TakeCountChildren(const QString& Name, const QString& DateStart, const QString& DateEnd, const QSqlDatabase& db){
    QSqlQuery query = QSqlQuery(db);
    query.exec(QString("select count(idchildren), workers.name from workers inner join children using(idworker) where (workers.name = '%1') and (datediff('%2', children.Birthday) <= 365*18) and (datediff('%3',  children.Birthday) > 0) group by workers.name;").arg(Name).arg(DateEnd).arg(DateStart));
    if (query.next()) return query.value(0).toInt();;
    return 0;
}

QString FormatStr(QString S){
    while (S.size() < 8) S += " ";
    return S;
}

void FillPaySheet(const QString& Name, const QString& DateStart, const QString& DateEnd, QString& text, const QSqlDatabase& db){
    double IncomeSalary = (TakeIncome(Name, DateStart, DateEnd, db));
    double IncomeAllowance = (TakeSumAllowance(Name, DateStart, DateEnd, db));
    double IncomeContracts = (TakeSumContracts(Name, DateStart, DateEnd, db));
    text.replace(QString("%PLACE1%"), DateStart + " - " + DateEnd);
    text.replace(QString("%PLACE2%"), Name);
    text.replace(QString("%PLACE13%"), QString::number(GetIdWorker(Name, db)));
    text.replace(QString("%PLACE3%"), FormatStr(QString::number(DateDiff(DateStart, DateEnd))));
    text.replace(QString("%PLACE4%"), FormatStr(QString::number(IncomeSalary)));
    text.replace(QString("%PLACE5%"), FormatStr(QString::number(IncomeAllowance)));
    text.replace(QString("%PLACE6%"), FormatStr(QString::number(IncomeContracts)));
    text.replace(QString("%PLACE7%"), FormatStr(QString::number(IncomeSalary + IncomeAllowance + IncomeContracts)));
    text.replace(QString("%PLACE8%"), FormatStr(QString::number(std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0))));
    text.replace(QString("%PLACE9%"), FormatStr(QString::number(IncomeSalary * std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0)/100)));
    text.replace(QString("%PLACE10%"), FormatStr(QString::number(IncomeAllowance * std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0)/100)));
    text.replace(QString("%PLACE11%"), FormatStr(QString::number(IncomeContracts * std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0)/100)));
    text.replace(QString("%PLACE12%"), FormatStr(QString::number((IncomeSalary + IncomeContracts + IncomeAllowance) * std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0)/100)));
    text.replace(QString("%PLACE14%"), FormatStr(QString::number((IncomeSalary + IncomeContracts + IncomeAllowance) *(100 - std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0))/100)));
}

void FillYearIncome(const QString& Name, const QString& Year, QString& text, const QSqlDatabase& db){
    text.replace(QString("%PLACE1%"), Year);
    text.replace(QString("%PLACE2%"), Name);
    text.replace(QString("%PLACE3%"), QString::number(GetIdWorker(Name, db)));

    double TotalIncome = 0, TotalTax = 0;
    for (int mounth = 0; mounth < 12; mounth++){
        QString DateStart = QString("%1-%2-01").arg(Year).arg(mounth+1);
        QString DateEnd = QString("%1-%2-01").arg(Year).arg(mounth+2);
        if (mounth == 11) DateEnd = QString("%1-01-01").arg(Year.toInt()+1);
        double IncomeSalary = (TakeIncome(Name, DateStart, DateEnd, db));
        double IncomeAllowance = (TakeSumAllowance(Name, DateStart, DateEnd, db));
        double IncomeContracts = (TakeSumContracts(Name, DateStart, DateEnd, db));
        TotalIncome += IncomeSalary + IncomeContracts + IncomeAllowance;
        TotalTax += (IncomeSalary + IncomeContracts + IncomeAllowance) * std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0)/100;
        text.replace(QString("%PLACE%1%").arg(4 + 7*mounth), FormatStr(QString::number(IncomeAllowance)));
        text.replace(QString("%PLACE%1%").arg(4 + 7*mounth + 1), FormatStr(QString::number(IncomeContracts)));
        text.replace(QString("%PLACE%1%").arg(4 + 7*mounth + 2), FormatStr(QString::number(IncomeSalary)));
        text.replace(QString("%PLACE%1%").arg(4 + 7*mounth + 3), FormatStr(QString::number(IncomeSalary + IncomeContracts + IncomeAllowance)));
        text.replace(QString("%PLACE%1%").arg(4 + 7*mounth + 4), FormatStr(QString::number(std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0))));
        text.replace(QString("%PLACE%1%").arg(4 + 7*mounth + 5), FormatStr(QString::number((IncomeSalary + IncomeContracts + IncomeAllowance) * std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0)/100)));
        text.replace(QString("%PLACE%1%").arg(4 + 7*mounth + 6), FormatStr(QString::number((IncomeSalary + IncomeContracts + IncomeAllowance) *(100 - std::max(13 - 3*TakeCountChildren(Name, DateStart, DateEnd, db), 0))/100)));
    }
    text.replace(QString("%PLACE88%"), QString::number(TotalIncome - TotalTax));
}


//// нажатие на кнопку расчётного листка
void Reports::on_pushButton_6_clicked()
{
    QString Name, DateStart, DateEnd;
    if (!TakeData(Name, DateStart, DateEnd)) return;

    QString ReportFileName = QDir::currentPath() + "/Reports/PaySheet_" + ConvertToEng(Name) + ".txt";
    QString TemplateFileName = QDir::currentPath() + "/Templates/PaySheetTemplate.txt";
    QFile::copy(TemplateFileName, ReportFileName);

    QFile ReportFile(ReportFileName);
    ReportFile.open(QIODevice::ReadWrite);
    QByteArray fileData = ReportFile.readAll();
    QString text(fileData);

    FillPaySheet(Name, DateStart, DateEnd, text, db);
    ReportFile.seek(0);
    ReportFile.write(text.toUtf8());
    ReportFile.close();

    CallCompliteWindow("Отчёт ждёт вас в папке");
}


void Reports::on_pushButton_7_clicked()
{
    QString Name, Year;
    if (!TakeData(Name, Year)) return;

    QString ReportFileName = QDir::currentPath() + "/Reports/YearIncome_" + ConvertToEng(Name) + "_" + Year + ".txt";
    QString TemplateFileName = QDir::currentPath() + "/Templates/YearIncomeTemplate.txt";
    QFile::copy(TemplateFileName, ReportFileName);

    QFile TemplateFile(TemplateFileName);
    TemplateFile.open(QIODevice::ReadOnly);
    QByteArray fileData = TemplateFile.readAll();
    QString text(fileData);

    FillYearIncome(Name, Year, text, db);

    QFile ReportFile(ReportFileName);
    if (ReportFile.open(QIODevice::WriteOnly)) ReportFile.write(text.toUtf8());
    ReportFile.close();


    CallCompliteWindow("Отчёт ждёт вас в папке");
}

void Reports::on_pushButton_4_clicked()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("select occupations.name, staffing_table.title, amount - sum(PartRate), amount, sum(partrate) from staffing_table inner join occupations using(idstaffing_table) inner join rate using(idoccupation) left join worker_occupation using(idoccupation) where rate.dateend is null and worker_occupation.dateend is null group by idOccupation having sum(partrate) is null or sum(PartRate) < amount;");
    QString text = "Доступные вакансии\n";
    while(query.next()){
        if (query.value(2).isNull()) text += query.value(0).toString() + " - " + query.value(1).toString() + ": " + query.value(3).toString() + "\n";
        else text += query.value(0).toString() + " - " + query.value(1).toString() + ": " + query.value(2).toString() + "\n";
    }
    if (text == "") text = "Вакансий нет";
    QString ReportFileName = QDir::currentPath() + "/Reports/Vacancies.txt";
    QFile ReportFile(ReportFileName);
    if (ReportFile.open(QIODevice::WriteOnly)) ReportFile.write(text.toUtf8());
    ReportFile.close();

    CallCompliteWindow("Вакансии успешно выписаны");
}


void Reports::on_pushButton_clicked()
{
    QSqlQuery query = QSqlQuery(db);
    query.exec("SELECT workers.name, COALESCE(SUM(t.reward), 0) AS total_sum FROM workers LEFT JOIN ( SELECT idworker, reward FROM worker_allowance JOIN allowance ON worker_allowance.idallowance = allowance.idallowance WHERE worker_allowance.date > '2023-04-01' AND worker_allowance.date < '2023-05-01' UNION ALL SELECT idworker, reward FROM worker_contract JOIN contracts ON worker_contract.idcontract = contracts.idcontract WHERE worker_contract.dateend > '2023-04-01' AND worker_contract.dateend < '2023-05-01' ) t ON workers.idworker = t.idworker GROUP BY workers.name having total_sum < 0;");
    QString text = "На грани увольнения\n";
    while (query.next()){
        text += query.value(0).toString() + ": " + query.value(1).toString() + "\n";
    }
    if (text == "") text = "У всех работников нет задолжности!";

    QString ReportFileName = QDir::currentPath() + "/Reports/DismissalList.txt";
    QFile ReportFile(ReportFileName);
    if (ReportFile.open(QIODevice::WriteOnly)) ReportFile.write(text.toUtf8());
    ReportFile.close();

    CallCompliteWindow("Список работников ждёт вас в папке");
}
