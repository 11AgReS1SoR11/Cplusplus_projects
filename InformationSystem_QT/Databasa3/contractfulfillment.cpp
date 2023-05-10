#include "contractfulfillment.h"
#include "ui_contractfulfillment.h"

ContractFulfillment::ContractFulfillment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContractFulfillment)
{
    ui->setupUi(this);

    setWindowTitle("Contract fulfillment");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_2->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_3->setStyleSheet("color: rgb(230, 230, 230)");

    // Открываю базу данных
    if (!Connection_to_database(db)) return;
    QSqlQuery query = MyWorkers(db);
    query.next();
    QString NameFirst = query.value(0).toString(); // запоминаю первого человека
    do {
        ui->FIO->addItem(query.value(0).toString());
    }while(query.next());

    query = MyContractss(db, NameFirst, true); // контракты первого человека
    while(query.next())
        ui->Contract->addItem(query.value(0).toString() + ": " + query.value(1).toString());

    connect(ui->FIO, &QComboBox::currentTextChanged, this, &ContractFulfillment::UpdateContracts);
}

ContractFulfillment::~ContractFulfillment()
{
    delete ui;
}

void ContractFulfillment::UpdateContracts()
{
    QString Name = ui->FIO->currentText();
    ui->Contract->clear();
    QSqlQuery query = MyContractss(db, Name, true);
    while (query.next())
        ui->Contract->addItem(query.value(0).toString() + ": " + query.value(1).toString());
}

bool ContractFulfillment::TakeData(QString &Name, QString &Contract, QString& Reward, QString &DateEnd){
    Name = ui->FIO->currentText();
    Contract = ui->Contract->currentText();
    DateEnd = ui->DateEnd->text();
    SepWords(Contract, Reward, ": ");

    if (!CheckForDate(DateEnd)){
        QMessageBox::warning(this, "Внимание", "Дата введена неверно");
        return false;
    }
    return true;
}

void ContractFulfillment::AddDateEnd(const QString &Name, const QString &Contract, const QString& Reward, const QString &DateEnd){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("update worker_contract set DateEnd = '%1' where idWorker = (select idWorker from workers where name = '%2') and IdContract = (select idContract from contracts where name = '%3' and Reward = %4);").arg(DateEnd).arg(Name).arg(Contract).arg(Reward);
    query.exec(queryStr);
}

void ContractFulfillment::on_pushButton_clicked()
{
    QString Name, Contract, Reward, DateEnd;
    if (!TakeData(Name, Contract, Reward, DateEnd)) return;

    // Заношу дату окончания в Worker_Contract
    AddDateEnd(Name, Contract, Reward, DateEnd);

    // Всплывающее окно, что всё круто
    CallCompliteWindow("Контракт выполнен");
}

