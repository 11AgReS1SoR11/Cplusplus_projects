#ifndef DANIALDATABASALIB_H
#define DANIALDATABASALIB_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QMap>
#include <QPalette>
#include <QMainWindow>

bool Connection_to_database(QSqlDatabase& db);

void CallCompliteWindow(const QString& Text);

bool CheckForDate(const QString& Date);

bool CheckForNum(const QString& S);

void SepWords(QString& First, QString& Second, const QString& Sep);

int GetIdWorker(const QString& Name, const QSqlDatabase& db);

int GetIdContract(const QString& Contract, const QString& Reward, const QSqlDatabase& db);

int GetIdOccupation(const QString& Position, const QString& Department, const QSqlDatabase& db);

QSqlQuery MyWorkers(const QSqlDatabase& db, bool IsNotDismissal = true);

QSqlQuery MyOccupations(const QSqlDatabase& db, QString Name = "");

QSqlQuery MyContractss(const QSqlDatabase& db, QString Name = "", bool IsNotComplited = false);

QSqlQuery MyAllowance(const QSqlDatabase& db, QString Name = "");

QSqlQuery MySelary(const QSqlDatabase& db, const QString& Position, const QString& Department);

QString ConvertToEng(const QString& S);

int DateDiff(const QString& DateStart, const QString& DateEnd);

QString MinDate(QString DateFirst, QString DateSecond);

QString MaxDate(QString DateFirst, QString DateSecond);

bool SetBackground(QWidget* window, const QString& ImagePath);

bool SetBackground(QMainWindow* window, const QString& ImagePath);


#endif // DANIALDATABASALIB_H
