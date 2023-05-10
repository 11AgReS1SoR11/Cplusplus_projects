/********************************************************************************
** Form generated from reading UI file 'contractfulfillment.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRACTFULFILLMENT_H
#define UI_CONTRACTFULFILLMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContractFulfillment
{
public:
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *DateEnd;
    QComboBox *Contract;
    QComboBox *FIO;

    void setupUi(QWidget *ContractFulfillment)
    {
        if (ContractFulfillment->objectName().isEmpty())
            ContractFulfillment->setObjectName("ContractFulfillment");
        ContractFulfillment->resize(623, 435);
        pushButton = new QPushButton(ContractFulfillment);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(390, 320, 141, 71));
        formLayoutWidget = new QWidget(ContractFulfillment);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(40, 40, 491, 251));
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

        Contract = new QComboBox(formLayoutWidget);
        Contract->setObjectName("Contract");

        formLayout->setWidget(1, QFormLayout::FieldRole, Contract);

        FIO = new QComboBox(formLayoutWidget);
        FIO->setObjectName("FIO");

        formLayout->setWidget(0, QFormLayout::FieldRole, FIO);


        retranslateUi(ContractFulfillment);

        QMetaObject::connectSlotsByName(ContractFulfillment);
    } // setupUi

    void retranslateUi(QWidget *ContractFulfillment)
    {
        ContractFulfillment->setWindowTitle(QCoreApplication::translate("ContractFulfillment", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ContractFulfillment", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\320\273", nullptr));
        label->setText(QCoreApplication::translate("ContractFulfillment", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("ContractFulfillment", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("ContractFulfillment", "\320\224\320\260\321\202\320\260 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContractFulfillment: public Ui_ContractFulfillment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRACTFULFILLMENT_H
