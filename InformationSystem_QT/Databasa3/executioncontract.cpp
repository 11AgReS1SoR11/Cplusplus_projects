#include "executioncontract.h"
#include "ui_executioncontract.h"

ExecutionContract::ExecutionContract(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExecutionContract)
{
    ui->setupUi(this);

    setWindowTitle("Execute contract");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_2->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_3->setStyleSheet("color: rgb(230, 230, 230)");

    // Открываю базу данных
    if (!Connection_to_database(db)) return;
    // беру из бд
    QSqlQuery query = MyContractss(db);
    while (query.next())
        ui->Contract->addItem(query.value(0).toString() + ": " + query.value(1).toString());

    query = MyWorkers(db);
    while (query.next())
        ui->FIO->addItem(query.value(0).toString());
}

ExecutionContract::~ExecutionContract()
{
    delete ui;
}

bool ExecutionContract::TakeData(QString &Name, QString &Contract, QString& Reward, QString &DateStart){
    Name = ui->FIO->currentText();
    Contract = ui->Contract->currentText();
    DateStart = ui->DateStart->text();
    SepWords(Contract, Reward, ": ");

    if (!CheckForDate(DateStart)){
        QMessageBox::warning(this, "Внимание", "Дата введена неверно");
        return false;
    }
    return true;
}

void ExecutionContract::AddWorkerContract(const QString &Name, const QString &Contract, const QString& Reward, const QString &DateStart){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("insert into worker_contract(DateStart, DateEnd, IdWorker, IdContract) value('%1', null, %2, %3);").arg(DateStart).arg(GetIdWorker(Name, db)).arg(GetIdContract(Contract, Reward, db));
    query.exec(queryStr);
}

void ExecutionContract::on_pushButton_clicked()
{
    QString Name, Contract, Reward, DateStart;
    if (!TakeData(Name, Contract, Reward, DateStart)) return;

    // Добавляю в таблицу Worker_Contract
    AddWorkerContract(Name, Contract, Reward, DateStart);

    // Всплывающее окно, что всё круто
    CallCompliteWindow("Контракт назначен");
}

