#include "addingcontract.h"
#include "ui_addingcontract.h"

AddingContract::AddingContract(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddingContract)
{
    ui->setupUi(this);
    setWindowTitle("Add contract");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_2->setStyleSheet("color: rgb(230, 230, 230)");

    // Открываю базу данных
    if (!Connection_to_database(db)) return;
}

AddingContract::~AddingContract()
{
    delete ui;
}

bool AddingContract::TakeData(QString& Name, QString& Reward){
    Name = ui->FIO->text();
    Reward = ui->Reward->text();

    for (auto c : Reward) if (!c.isDigit() && c != '.') {
        QMessageBox::warning(this, "Внимание", "Награда введена неверно");
        return false;
    }
    return true;
}

void AddingContract::AddContract(const QString& Name, const QString& Reward){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("insert into contracts(Name, Reward) value('%1', %2);").arg(Name).arg(Reward);
    query.exec(queryStr);
}


void AddingContract::on_pushButton_clicked()
{
    QString Name, Reward;
    if (!TakeData(Name, Reward)) return;

    // Добавляю контракт в таблицу Contracts
    AddContract(Name, Reward);

    //всплывающее окно, что всё круто
    CallCompliteWindow("Контракт Добавлен");
}

