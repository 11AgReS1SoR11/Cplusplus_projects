#include "addingallowance.h"
#include "ui_addingallowance.h"

AddingAllowance::AddingAllowance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddingAllowance)
{
    ui->setupUi(this);
    setWindowTitle("Add allowance");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                    "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_2->setStyleSheet("color: rgb(230, 230, 230)");

    // Открываю базу данных
    if (!Connection_to_database(db)) return;
}

AddingAllowance::~AddingAllowance()
{
    delete ui;
}


bool AddingAllowance::TakeData(QString& Name, QString& Reward){
    Name = ui->Name->text();
    Reward = ui->Reward->text();

    for (auto c : Reward) if (!c.isDigit() && c != '.' && c != '-') {
        QMessageBox::warning(this, "Внимание", "Награда введена неверно");
        return false;
    }
    return true;
}

void AddingAllowance::AddAllowance(const QString& Name, const QString& Reward){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("insert into allowance(Name, Reward) value('%1', %2);").arg(Name).arg(Reward);
    query.exec(queryStr);
}


void AddingAllowance::on_pushButton_clicked()
{
    QString Name, Reward;
    if (!TakeData(Name, Reward)) return;

    // Добавляю контракт в таблицу Contracts
    AddAllowance(Name, Reward);

    //всплывающее окно, что всё круто
    CallCompliteWindow("Надбавка добавлена");
}

