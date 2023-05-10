/********************************************************************************
** Form generated from reading UI file 'dismissal_of_employee.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISMISSAL_OF_EMPLOYEE_H
#define UI_DISMISSAL_OF_EMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dismissal_of_employee
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *DateEnd;
    QComboBox *Position;
    QComboBox *FIO;
    QPushButton *pushButton;
    QLabel *label_4;

    void setupUi(QWidget *Dismissal_of_employee)
    {
        if (Dismissal_of_employee->objectName().isEmpty())
            Dismissal_of_employee->setObjectName("Dismissal_of_employee");
        Dismissal_of_employee->resize(599, 453);
        formLayoutWidget = new QWidget(Dismissal_of_employee);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 40, 451, 281));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        DateEnd = new QLineEdit(formLayoutWidget);
        DateEnd->setObjectName("DateEnd");

        formLayout->setWidget(2, QFormLayout::FieldRole, DateEnd);

        Position = new QComboBox(formLayoutWidget);
        Position->setObjectName("Position");

        formLayout->setWidget(1, QFormLayout::FieldRole, Position);

        FIO = new QComboBox(formLayoutWidget);
        FIO->setObjectName("FIO");

        formLayout->setWidget(0, QFormLayout::FieldRole, FIO);

        pushButton = new QPushButton(Dismissal_of_employee);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(410, 350, 131, 61));
        label_4 = new QLabel(Dismissal_of_employee);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(510, 100, 81, 21));

        retranslateUi(Dismissal_of_employee);

        QMetaObject::connectSlotsByName(Dismissal_of_employee);
    } // setupUi

    void retranslateUi(QWidget *Dismissal_of_employee)
    {
        Dismissal_of_employee->setWindowTitle(QCoreApplication::translate("Dismissal_of_employee", "Form", nullptr));
        label->setText(QCoreApplication::translate("Dismissal_of_employee", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("Dismissal_of_employee", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("Dismissal_of_employee", "\320\224\320\260\321\202\320\260 \321\203\320\262\320\276\320\273\321\214\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("Dismissal_of_employee", "\320\243\320\262\320\276\320\273\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("Dismissal_of_employee", "YYYY-MM-DD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dismissal_of_employee: public Ui_Dismissal_of_employee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISMISSAL_OF_EMPLOYEE_H
