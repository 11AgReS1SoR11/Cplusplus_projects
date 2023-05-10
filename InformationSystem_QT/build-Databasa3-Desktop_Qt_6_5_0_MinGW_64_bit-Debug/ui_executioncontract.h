/********************************************************************************
** Form generated from reading UI file 'executioncontract.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXECUTIONCONTRACT_H
#define UI_EXECUTIONCONTRACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExecutionContract
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *DateStart;
    QComboBox *Contract;
    QComboBox *FIO;
    QPushButton *pushButton;

    void setupUi(QWidget *ExecutionContract)
    {
        if (ExecutionContract->objectName().isEmpty())
            ExecutionContract->setObjectName("ExecutionContract");
        ExecutionContract->resize(599, 463);
        formLayoutWidget = new QWidget(ExecutionContract);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(40, 50, 491, 281));
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

        DateStart = new QLineEdit(formLayoutWidget);
        DateStart->setObjectName("DateStart");

        formLayout->setWidget(2, QFormLayout::FieldRole, DateStart);

        Contract = new QComboBox(formLayoutWidget);
        Contract->setObjectName("Contract");

        formLayout->setWidget(1, QFormLayout::FieldRole, Contract);

        FIO = new QComboBox(formLayoutWidget);
        FIO->setObjectName("FIO");

        formLayout->setWidget(0, QFormLayout::FieldRole, FIO);

        pushButton = new QPushButton(ExecutionContract);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(390, 370, 141, 51));

        retranslateUi(ExecutionContract);

        QMetaObject::connectSlotsByName(ExecutionContract);
    } // setupUi

    void retranslateUi(QWidget *ExecutionContract)
    {
        ExecutionContract->setWindowTitle(QCoreApplication::translate("ExecutionContract", "Form", nullptr));
        label->setText(QCoreApplication::translate("ExecutionContract", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("ExecutionContract", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("ExecutionContract", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("ExecutionContract", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214 \320\272\320\276\320\275\321\202\321\200\320\260\320\272\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExecutionContract: public Ui_ExecutionContract {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXECUTIONCONTRACT_H
