/********************************************************************************
** Form generated from reading UI file 'employeeregistration.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEREGISTRATION_H
#define UI_EMPLOYEEREGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeRegistration
{
public:
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *FIO;
    QLabel *label_2;
    QComboBox *Position;
    QLabel *label_5;
    QLineEdit *Rate;
    QLabel *label_3;
    QLineEdit *Date_registration;
    QLabel *label_4;
    QLineEdit *AmountChild;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *ChildrenBirthday;
    QLineEdit *ChildrenName;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *EmployeeRegistration)
    {
        if (EmployeeRegistration->objectName().isEmpty())
            EmployeeRegistration->setObjectName("EmployeeRegistration");
        EmployeeRegistration->resize(589, 460);
        pushButton = new QPushButton(EmployeeRegistration);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 350, 131, 61));
        formLayoutWidget = new QWidget(EmployeeRegistration);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 30, 431, 291));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        FIO = new QLineEdit(formLayoutWidget);
        FIO->setObjectName("FIO");

        formLayout->setWidget(0, QFormLayout::FieldRole, FIO);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        Position = new QComboBox(formLayoutWidget);
        Position->setObjectName("Position");

        formLayout->setWidget(1, QFormLayout::FieldRole, Position);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        Rate = new QLineEdit(formLayoutWidget);
        Rate->setObjectName("Rate");

        formLayout->setWidget(2, QFormLayout::FieldRole, Rate);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        Date_registration = new QLineEdit(formLayoutWidget);
        Date_registration->setObjectName("Date_registration");

        formLayout->setWidget(3, QFormLayout::FieldRole, Date_registration);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        AmountChild = new QLineEdit(formLayoutWidget);
        AmountChild->setObjectName("AmountChild");

        formLayout->setWidget(4, QFormLayout::FieldRole, AmountChild);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");

        formLayout->setWidget(5, QFormLayout::FieldRole, label_9);

        ChildrenBirthday = new QLineEdit(formLayoutWidget);
        ChildrenBirthday->setObjectName("ChildrenBirthday");

        formLayout->setWidget(6, QFormLayout::LabelRole, ChildrenBirthday);

        ChildrenName = new QLineEdit(formLayoutWidget);
        ChildrenName->setObjectName("ChildrenName");

        formLayout->setWidget(6, QFormLayout::FieldRole, ChildrenName);

        label_6 = new QLabel(EmployeeRegistration);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(490, 120, 91, 21));
        label_7 = new QLabel(EmployeeRegistration);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(490, 150, 71, 21));

        retranslateUi(EmployeeRegistration);

        QMetaObject::connectSlotsByName(EmployeeRegistration);
    } // setupUi

    void retranslateUi(QWidget *EmployeeRegistration)
    {
        EmployeeRegistration->setWindowTitle(QCoreApplication::translate("EmployeeRegistration", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("EmployeeRegistration", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("EmployeeRegistration", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("EmployeeRegistration", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("EmployeeRegistration", "\320\241\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("EmployeeRegistration", "\320\224\320\260\321\202\320\260 \320\276\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("EmployeeRegistration", "\320\224\320\265\321\202\320\270", nullptr));
        label_8->setText(QCoreApplication::translate("EmployeeRegistration", "\320\224\320\260\321\202\321\213 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217 ", nullptr));
        label_9->setText(QCoreApplication::translate("EmployeeRegistration", "\320\230\320\274\320\265\320\275\320\260 (\320\265\321\201\320\273\320\270 \320\264\320\265\321\202\320\265\320\271 \320\275\320\265\321\201\320\272\320\276\320\273\321\214\320\272\320\276, \321\202\320\276 \320\277\320\265\321\200\320\265\321\207\320\270\321\201\320\273\321\217\321\202\321\214 \321\207\320\265\321\200\320\265\320\267 \";\")", nullptr));
        label_6->setText(QCoreApplication::translate("EmployeeRegistration", "YYYY-MM-DD", nullptr));
        label_7->setText(QCoreApplication::translate("EmployeeRegistration", "\320\232\320\276\320\273-\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeRegistration: public Ui_EmployeeRegistration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEREGISTRATION_H
