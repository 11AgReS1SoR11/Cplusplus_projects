/********************************************************************************
** Form generated from reading UI file 'assignallowance.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNALLOWANCE_H
#define UI_ASSIGNALLOWANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AssignAllowance
{
public:
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *FIO;
    QComboBox *Allowance;
    QLabel *label_3;
    QLineEdit *Date;

    void setupUi(QWidget *AssignAllowance)
    {
        if (AssignAllowance->objectName().isEmpty())
            AssignAllowance->setObjectName("AssignAllowance");
        AssignAllowance->resize(594, 470);
        pushButton = new QPushButton(AssignAllowance);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(400, 370, 131, 61));
        formLayoutWidget = new QWidget(AssignAllowance);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 30, 501, 321));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        FIO = new QComboBox(formLayoutWidget);
        FIO->setObjectName("FIO");

        formLayout->setWidget(0, QFormLayout::FieldRole, FIO);

        Allowance = new QComboBox(formLayoutWidget);
        Allowance->setObjectName("Allowance");

        formLayout->setWidget(1, QFormLayout::FieldRole, Allowance);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        Date = new QLineEdit(formLayoutWidget);
        Date->setObjectName("Date");

        formLayout->setWidget(2, QFormLayout::FieldRole, Date);


        retranslateUi(AssignAllowance);

        QMetaObject::connectSlotsByName(AssignAllowance);
    } // setupUi

    void retranslateUi(QWidget *AssignAllowance)
    {
        AssignAllowance->setWindowTitle(QCoreApplication::translate("AssignAllowance", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("AssignAllowance", "\320\235\320\260\320\267\320\275\320\260\321\207\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("AssignAllowance", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("AssignAllowance", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("AssignAllowance", "\320\224\320\260\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssignAllowance: public Ui_AssignAllowance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNALLOWANCE_H
