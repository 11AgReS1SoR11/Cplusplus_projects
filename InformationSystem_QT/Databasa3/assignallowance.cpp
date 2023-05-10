#include "assignallowance.h"
#include "ui_assignallowance.h"

AssignAllowance::AssignAllowance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AssignAllowance)
{
    ui->setupUi(this);

    setWindowTitle("Assign allowance");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_2->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_3->setStyleSheet("color: rgb(230, 230, 230)");

    // Открываю базу данных
    if (!Connection_to_database(db)) return;

    QSqlQuery query = MyWorkers(db);
    while(query.next())
        ui->FIO->addItem(query.value(0).toString());

    query = MyAllowance(db);
    while(query.next())
        ui->Allowance->addItem(query.value(0).toString() + ": " + query.value(1).toString());
}

AssignAllowance::~AssignAllowance()
{
    delete ui;
}

bool AssignAllowance::TakeData(QString &Name, QString &Allowance, QString &Reward, QString& Date){
    Name = ui->FIO->currentText();
    Allowance = ui->Allowance->currentText();
    Date = ui->Date->text();

    SepWords(Allowance, Reward, ": ");

    if (!CheckForDate(Date)){
        QMessageBox::warning(this, "Внимание", "Дата введена неверно");
        return false;
    }
    return true;

}

void AssignAllowance::AddWorkerAllowance(const QString &Name, const QString &Allowance, const QString &Reward, const QString &Date){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("insert into worker_allowance(Date, Idworker, IdAllowance) value('%1', (select idworker from workers where name = '%2'), (select idallowance from allowance where name = '%3' and reward = %4));").arg(Date).arg(Name).arg(Allowance).arg(Reward);
    query.exec(queryStr);
}

void AssignAllowance::on_pushButton_clicked()
{

    QString Name, Allowance, Reward, Date;
    if (!TakeData(Name, Allowance, Reward, Date)) return;

    // Заношу дату окончания в Worker_Allowance
    AddWorkerAllowance(Name, Allowance, Reward, Date);

    // Всплывающее окно, что всё круто
    CallCompliteWindow("Надбавка назначена");
}

