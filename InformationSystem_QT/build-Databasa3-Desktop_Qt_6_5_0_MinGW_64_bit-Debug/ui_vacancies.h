/********************************************************************************
** Form generated from reading UI file 'vacancies.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VACANCIES_H
#define UI_VACANCIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Vacancies
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Vacancies)
    {
        if (Vacancies->objectName().isEmpty())
            Vacancies->setObjectName("Vacancies");
        Vacancies->resize(661, 490);
        scrollArea = new QScrollArea(Vacancies);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 30, 601, 421));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 599, 419));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Vacancies);

        QMetaObject::connectSlotsByName(Vacancies);
    } // setupUi

    void retranslateUi(QWidget *Vacancies)
    {
        Vacancies->setWindowTitle(QCoreApplication::translate("Vacancies", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Vacancies: public Ui_Vacancies {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VACANCIES_H
