#include "changerate.h"
#include "ui_changerate.h"

ChangeRate::ChangeRate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeRate)
{
    ui->setupUi(this);

    setWindowTitle("Change rate");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_2->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_3->setStyleSheet("color: rgb(230, 230, 230)");
    ui->LastRate->setStyleSheet("color: rgb(230, 230, 230)");


    // Открываю базу данных
    if (!Connection_to_database(db)) return;

    // беру из бд
    QSqlQuery query = MyOccupations(db);
    query.next();
    QString Department = query.value(1).toString(), Position = query.value(0).toString(); // запоминаю первый occupation
    do {
        ui->Position->addItem(query.value(0).toString() + " - " + query.value(1).toString());
    } while (query.next());

    query = MySelary(db, Position, Department); // ставка первого occupation
    query.next();
    ui->LastRate->setText("Текущая ставка на эту должность: " + query.value(0).toString());

    connect(ui->Position, &QComboBox::currentTextChanged, this, &ChangeRate::UpdateLastRate);
}

ChangeRate::~ChangeRate()
{
    delete ui;
}


bool ChangeRate::TakeData(QString& NewRate, QString& Position, QString& Department, QString& DateEnd){
    NewRate = ui->NewRate->text();
    Position = ui->Position->currentText();
    DateEnd = ui->Date->text();

    SepWords(Position, Department, " - ");

    if (!CheckForDate(DateEnd)){
        QMessageBox::warning(this, "Внимание", "Дата введена неверно");
        return false;
    }
    return true;
}

void ChangeRate::AddDateEnd(const QString& NewRate, const QString& Position, const QString& Department, const QString& DateEnd){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("update rate set dateend = '%1' where idoccupation = (select idoccupation from occupations inner join staffing_table using(idstaffing_table) where occupations.name = '%2' and staffing_table.title = '%3'); insert into rate(DateEnd, Rate, idOccupation) value (null, '%4', (select idoccupation from occupations inner join staffing_table using(idstaffing_table) where occupations.name = '%2' and staffing_table.title = '%3'));").arg(DateEnd).arg(Position).arg(Department).arg(NewRate);
    query.prepare(queryStr);
    query.exec();
}

void ChangeRate::UpdateLastRate()
{
    QString Department, Position = ui->Position->currentText();
    SepWords(Position, Department, " - ");
    ui->LastRate->clear();
    QSqlQuery query = MySelary(db, Position, Department);
    query.next();
    ui->LastRate->setText("Текущая ставка на эту должность: " + query.value(0).toString());
}

void ChangeRate::on_pushButton_clicked()
{
    QString NewRate, Position, Department, DateEnd;
    if (!TakeData(NewRate, Position, Department, DateEnd)) return;

    // Заношу дату окончания в Worker_Contract
    AddDateEnd(NewRate, Position, Department, DateEnd);

    // Всплывающее окно, что всё круто
    CallCompliteWindow("Ставка изменена");
}
