#include "dismissal_of_employee.h"
#include "ui_dismissal_of_employee.h"


Dismissal_of_employee::Dismissal_of_employee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dismissal_of_employee)
{
    ui->setupUi(this);

    setWindowTitle("Dismissal");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_2->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_3->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_4->setStyleSheet("color: rgb(230, 230, 230)");

    // Открываю базу данных
    if (!Connection_to_database(db)) return;

    QSqlQuery query = MyWorkers(db);
    while (query.next())
        ui->FIO->addItem(query.value(0).toString());

    connect(ui->FIO, &QComboBox::currentTextChanged, this, &Dismissal_of_employee::updateComboBox);
}

Dismissal_of_employee::~Dismissal_of_employee()
{
    delete ui;
}

bool Dismissal_of_employee::TakeData(QString& Name, QString& Position, QString& Department, QString& DateEnd){
    Name = ui->FIO->currentText();
    Position = ui->Position->currentText();
    DateEnd = ui->DateEnd->text();

    SepWords(Position, Department, " - ");

    if (!CheckForDate(DateEnd)){
        QMessageBox::warning(this, "Внимание", "Дата введена неверно");
        return false;
    }
    return true;
}

void Dismissal_of_employee::AddDateEnd(QString& Name, QString& DateEnd, QString& Position, QString& Department){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("update worker_occupation inner join occupations using(idoccupation) inner join staffing_table using(idstaffing_table) inner join workers using(idworker) set worker_occupation.DateEnd = '%1', workers.DateDismissal = '%1' where workers.name = '%2' and staffing_table.Title = '%3' and occupations.name = '%4' and worker_occupation.DateEnd is null;").arg(DateEnd).arg(Name).arg(Department).arg(Position);
    query.exec(queryStr);
}

void Dismissal_of_employee::updateComboBox()
{
    QString Name = ui->FIO->currentText();
    ui->Position->clear();
    QSqlQuery query = MyOccupations(db, Name);
    while (query.next())
        ui->Position->addItem(query.value(0).toString() + " - " + query.value(1).toString());
}

void Dismissal_of_employee::on_pushButton_clicked()
{
    QString Name, Position, Department, DateEnd;
    if (!TakeData(Name, Position, Department, DateEnd)) return;

    // Устанавливаю дату увольнения в таблице Worker_occupation и Worker
    AddDateEnd(Name, DateEnd, Position, Department);

    //всплывающее окно, что всё круто
    CallCompliteWindow("Сотрудник уволен");
}

