#include <DanialDatabasaLib.h>

bool Connection_to_database(QSqlDatabase& db){
    // Открываю базу данных
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Databasa");
    db.setUserName("root");
    db.setPassword("Daniil1102*");

    // Если не открылась база данных, то вывожу сообщение об ошибки и завершаю
    if (!db.open()){
        QMessageBox msg;
        msg.setText("Не удалось открыть базу данных");
        msg.setWindowTitle("Ошибка");
        msg.exec();
        return false;
    }
    return true;
}

void CallCompliteWindow(const QString& Text){
    //всплывающее окно, что всё круто
    QMessageBox compite_message;
    compite_message.setText(Text);
    compite_message.exec();
}

bool CheckForDate(const QString& Date){
    if (Date.size() != 10) return false;
    if (Date[0].isDigit() && Date[1].isDigit() && Date[2].isDigit() && Date[3].isDigit() &&
            Date[4] == '-' && Date[5].isDigit() && Date[6].isDigit() &&
            Date[7] == '-' && Date[8].isDigit() && Date[9].isDigit()) return true;
    return false;
}

void SepWords(QString& First, QString& Second, const QString& Sep){
    int sepidx = First.indexOf(Sep);
    Second = First.right(First.size() - sepidx - Sep.size());
    First = First.left(sepidx);
}

bool CheckForNum(const QString& S){
    for (auto c : S)
        if (!c.isDigit()) return false;
    return true;
}

int GetIdWorker(const QString& Name, const QSqlDatabase& db){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("select idworker from workers where name = '%1';").arg(Name);
    query.exec(queryStr);
    query.next();
    return query.value(0).toInt();
}

int GetIdContract(const QString& Contract, const QString& Reward, const QSqlDatabase& db){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("select idcontract from contracts where name = '%1' and reward = %2;").arg(Contract).arg(Reward);
    query.exec(queryStr);
    query.next();
    return query.value(0).toInt();
}

int GetIdOccupation(const QString& Position, const QString& Department, const QSqlDatabase& db){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("select idOccupation from occupations inner join staffing_table using(Idstaffing_table) where occupations.name = '%1' and staffing_table.title = '%2';").arg(Position).arg(Department);
    query.exec(queryStr);
    query.next();
    return query.value(0).toInt();
}

QSqlQuery MyWorkers(const QSqlDatabase& db, bool IsNotDismissal){
    QSqlQuery query = QSqlQuery(db);
    if (IsNotDismissal) query.exec("select name from workers where DateDismissal is null order by name;");
    else query.exec("select name from workers order by name;");
    return query;
}

QSqlQuery MyOccupations(const QSqlDatabase &db, QString Name){
    QSqlQuery query = QSqlQuery(db);
    if (Name == "") query.exec("select occupations.name, staffing_table.title from occupations inner join staffing_table using(Idstaffing_table) order by staffing_table.title, occupations.name;");
    else query.exec(QString("select occupations.name, staffing_table.title from workers inner join worker_occupation using(idworker) inner join occupations using(idoccupation) inner join staffing_table using(idstaffing_table) where workers.name = '%1' and worker_occupation.DateEnd is null order by staffing_table.title, occupations.name;").arg(Name));
    return query;
}

QSqlQuery MyContractss(const QSqlDatabase &db, QString Name, bool IsNotComplited){
    QSqlQuery query = QSqlQuery(db);
    if (Name == "") query.exec("select name, Reward from contracts where idcontract not in (select contracts.idcontract from contracts inner join worker_contract using(idcontract)) order by reward, name;");
    else if (IsNotComplited) query.exec(QString("select contracts.name, contracts.reward from contracts inner join worker_contract using(idcontract) inner join workers using(idworker) where workers.name = '%1' and worker_contract.dateend is null order by reward, name;").arg(Name));
    else query.exec(QString("select contracts.name, contracts.reward from contracts inner join worker_contract using(idcontract) inner join workers using(idworker) where workers.name = '%1' order by reward, name;").arg(Name));
    return query;
}

QSqlQuery MyAllowance(const QSqlDatabase &db, QString Name){
    QSqlQuery query = QSqlQuery(db);
    if (Name == "") query.exec("select name, reward from allowance order by name;");
    else query.exec(QString("select allowance.name, allowance.reward from allowance inner join worker_allowance using(idallowance) inner join workers using(idworker) where workers.name = '%1' order by reward, name;").arg(Name));
    return query;
}

QSqlQuery MySelary(const QSqlDatabase &db, const QString &Position, const QString &Department){
    QSqlQuery query = QSqlQuery(db);
    QString queryStr = QString("select rate.rate from rate inner join occupations using(idoccupation) inner join staffing_table using(idstaffing_table) where occupations.name = '%1' and staffing_table.title = '%2' and rate.DateEnd is null;").arg(Position).arg(Department);
    query.exec(queryStr);
    return query;
}

QString ConvertToEng(const QString &S){
    //QLocale russianLocale(QLocale::Russian);
    QMap<QString, QString> Translater = {{"А", "A"}, {"Б", "B"}, {"В", "V"}, {"Г", "G"}, {"Д", "D"}, {"Е", "E"}, {"Ё", "YO"},
                                      {"Ж", "ZH"}, {"З", "Z"}, {"И", "I"}, {"Й", "Y"}, {"К", "K"}, {"Л", "L"}, {"М", "M"}, {"Н", "N"},
                                      {"О", "O"}, {"П", "P"}, {"Р", "R"}, {"С", "S"}, {"Т", "T"}, {"У", "U"}, {"Ф", "F"}, {"Х", "H"},
                                      {"Ц", "C"}, {"Ч", "CH"}, {"Ш", "SH"}, {"Щ", "SHH"}, {"Ъ", ""}, {"Ы", "I"}, {"Ь", ""}, {"Э", "E"},
                                      {"Ю", "YU"}, {"Я", "YA"}, {"а", "a"}, {"б", "b"}, {"в", "v"}, {"г", "g"}, {"д", "d"}, {"е", "e"}, {"ё", "yo"},
                                                                               {"ж", "zh"}, {"з", "z"}, {"и", "i"}, {"й", "y"}, {"к", "k"}, {"л", "l"}, {"м", "m"}, {"н", "n"},
                                                                               {"о", "o"}, {"п", "p"}, {"р", "r"}, {"с", "s"}, {"т", "t"}, {"у", "u"}, {"ф", "f"}, {"х", "h"},
                                                                               {"ц", "c"}, {"ч", "ch"}, {"ш", "sh"}, {"щ", "shh"}, {"ъ", ""}, {"ы", "i"}, {"ь", ""}, {"э", "e"},
                                         {"ю", "yu"}, {"я", "ya"}, {" ", "_"}};
    QString NewS = "";
    for (auto c : S){
        if (Translater.find(QString(c)) != Translater.end()) NewS += Translater.find(QString(c)).value();
        else NewS += QString(c);
    }
    return NewS;
}


int DateDiff(const QString& DateStart, const QString& DateEnd){
    if (DateStart == "" || DateEnd == "") return 0;;
    int datediff = (DateEnd.left(4).toInt() - DateStart.left(4).toInt()) * 365 + (DateEnd.mid(5,DateEnd.indexOf("-", 5)-5).toInt() - DateStart.mid(5,DateStart.indexOf("-", 5)-5).toInt()) * 30 + (DateEnd.right(DateEnd.size() - DateEnd.indexOf("-", 5)-1).toInt() - DateStart.right(DateStart.size() - DateStart.indexOf("-", 5)-1).toInt());
    return datediff;
}

QString MinDate(QString DateFirst, QString DateSecond){
    if (DateFirst == "") return DateSecond;
    if (DateSecond == "") return DateFirst;
    if (DateDiff(DateFirst, DateSecond) > 0) return DateFirst;
    else return DateSecond;
}

QString MaxDate(const QString DateFirst, QString DateSecond){
    if (DateFirst == "") return DateSecond;
    if (DateSecond == "") return DateFirst;
    if (DateDiff(DateFirst, DateSecond) > 0) return DateSecond;
    else return DateFirst;
}


bool SetBackground(QWidget* window, const QString& ImagePath)
{
    QPixmap bkgnd(ImagePath);
    bkgnd = bkgnd.scaled(window->size(), Qt::IgnoreAspectRatio);
    QPalette p = window->palette();
    p.setBrush(QPalette::Window, bkgnd);
    window->setPalette(p);
    return bkgnd.isNull();
}

bool SetBackground(QMainWindow* window, const QString& ImagePath)
{
    QPixmap bkgnd(ImagePath);
    bkgnd = bkgnd.scaled(window->size(), Qt::IgnoreAspectRatio);
    QPalette p = window->palette();
    p.setBrush(QPalette::Window, bkgnd);
    window->setPalette(p);
    return bkgnd.isNull();
}
