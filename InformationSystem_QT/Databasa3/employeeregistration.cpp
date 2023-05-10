#include "employeeregistration.h"
#include "ui_employeeregistration.h"


EmployeeRegistration::EmployeeRegistration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeRegistration)
{
    ui->setupUi(this);

    setWindowTitle("Registration");
    SetBackground(this, "C:/Users/79916/Documents/Databasa3/DatabaseBackground2.jpg");
    ui->pushButton->setStyleSheet("QPushButton { background-color: #8A2BE2; color: white; border: 2px solid black; }"
                                  "QPushButton:hover { border: 2px solid #FF00FF; }");
    ui->label->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_2->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_3->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_4->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_5->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_6->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_7->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_8->setStyleSheet("color: rgb(230, 230, 230)");
    ui->label_9->setStyleSheet("color: rgb(230, 230, 230)");

    // Открываю базу данных
    if (!Connection_to_database(db)) return;
    // беру из бд
    QSqlQuery query = MyOccupations(db);
    while (query.next())
        ui->Position->addItem(query.value(0).toString() + " - " + query.value(1).toString());
}

EmployeeRegistration::~EmployeeRegistration()
{
    delete ui;
}


bool CheckForRate(const QString& Rate, int IdOccupation, const QSqlDatabase& db){
    if (Rate == "0") return false;
    for (auto c : Rate) if (!c.isDigit() && c != '.') return false; // проверка на вилидность Rate
    QSqlQuery queryAmount = QSqlQuery(db), querySumPartRate = QSqlQuery(db);
    queryAmount.exec("select Amount from occupations where idOccupation = "+QVariant(IdOccupation).toString());
    queryAmount.next();
    querySumPartRate.exec("select sum(PartRate) from worker_occupation where DateEnd is null group by IdOccupation having IdOccupation = "+QVariant(IdOccupation).toString());
    querySumPartRate.next();
    if (queryAmount.value(0).toFloat() < querySumPartRate.value(0).toFloat() + Rate.toFloat()) return false;
    return true;
}

void FillNameChildren(QString& AmountChild, QString DateText, QString NameText, QVector<QPair<QString,QString>>& NameDateChildren){
    if (!CheckForNum(AmountChild)) return;
    NameDateChildren.resize(AmountChild.toInt());
    QStringList Date = DateText.split(u';');
    QStringList Name = NameText.split(u';');
    for (int i = 0; i < AmountChild.toInt(); i++){
        if (Date[i][0] == ' ') Date[i] = Date[i].right(Date[i].size()-1); // если начинается
        if (Name[i][0] == ' ') Name[i] = Name[i].right(Name[i].size()-1); // с пробела
        NameDateChildren[i].first = Name[i];
        NameDateChildren[i].second = Date[i];
    }
}

bool EmployeeRegistration::TakeData(QString& Name, QString& Rate, QString& DateRegistration, QString& AmountChild, QString& Position, QString& Department, QVector<QPair<QString,QString>>& NameDateChildren){
    Name = ui->FIO->text();
    Rate = ui->Rate->text();
    DateRegistration = ui->Date_registration->text();
    Position = ui->Position->currentText();
    AmountChild = ui->AmountChild->text();
    FillNameChildren(AmountChild, ui->ChildrenBirthday->text(), ui->ChildrenName->text(), NameDateChildren);

    SepWords(Position, Department, " - ");

    // Проверка на корректность кол-во детей и даты и ставки
    if (!CheckForNum(AmountChild)){
        QMessageBox::warning(this, "Внимание", "Количество детей введено неверно");
        return false;
    }
    if (!CheckForDate(DateRegistration)){
        QMessageBox::warning(this, "Внимание", "Дата введена неверно");
        return false;
    }
    for (auto child : NameDateChildren){
        if (!CheckForDate(child.second)){
            QMessageBox::warning(this, "Внимание", "Дата ребёнка введена неверно");
            return false;
        }
    }
    if (!CheckForRate(Rate, GetIdOccupation(Position, Department, db), db)){
        QMessageBox::warning(this, "Внимание", "Ставка введена неверно");
        return false;
    }
    return true;
}

int EmployeeRegistration::AddWorker(const QString& Name, const QString& DateRegistration){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO workers(Name, DateRegistration, DateDismissal) VALUES(?, ?, ?);");
    query.addBindValue(Name);
    query.addBindValue(DateRegistration);
    query.addBindValue(QVariant()); // null
    query.exec();
    return query.lastInsertId().toInt();
}

void EmployeeRegistration::AddChildren(const QString &AmountChild, const QVector<QPair<QString,QString>>& NameDateChildren, const int Id){
    if (AmountChild == "0") return;
    QSqlQuery query = QSqlQuery(db);
    for (auto NameDate : NameDateChildren){
        query.prepare("INSERT INTO children(Name, Birthday, IdWorker) VALUES(?, ?, ?);");
        query.addBindValue(NameDate.first);
        query.addBindValue(NameDate.second);
        query.addBindValue(Id); // null
        query.exec();
        query.clear();
    }
}

void EmployeeRegistration::AddWorker_Occupation(const QString& DateStart, const QString& Rate, const int IdWorker, const int IdOccupation){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO Worker_Occupation(DateStart, DateEnd, PartRate, IdWorker, IdOccupation) VALUES(?, ?, ?, ?, ?);");
    query.addBindValue(DateStart);
    query.addBindValue(QVariant()); // null
    query.addBindValue(Rate);
    query.addBindValue(IdWorker);
    query.addBindValue(IdOccupation);
    query.exec();
}

void EmployeeRegistration::on_pushButton_clicked()
{
    // Собираю данные
    QString Name, Rate, DateRegistration, AmountChild, Position, Department;
    QVector<QPair<QString,QString>> NameDateChildren;
    // Проверка на корректные данные
    if (!TakeData(Name, Rate, DateRegistration, AmountChild, Position, Department, NameDateChildren)) return;

    // Заношу данные в таблицу Workers
    int IdNewWorker = AddWorker(Name, DateRegistration);

    // Заношу данные в таблицу Children
    AddChildren(AmountChild, NameDateChildren, IdNewWorker);

    // Заношу данные в таблицу Worker_occupation
    AddWorker_Occupation(DateRegistration, Rate, IdNewWorker, GetIdOccupation(Position, Department, db));

    //всплывающее окно, что всё круто
    CallCompliteWindow("Сотрудник оформлен");
}

