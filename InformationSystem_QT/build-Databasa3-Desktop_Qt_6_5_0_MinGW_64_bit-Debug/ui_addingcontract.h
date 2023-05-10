/********************************************************************************
** Form generated from reading UI file 'addingcontract.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINGCONTRACT_H
#define UI_ADDINGCONTRACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddingContract
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *FIO;
    QLineEdit *Reward;
    QPushButton *pushButton;

    void setupUi(QWidget *AddingContract)
    {
        if (AddingContract->objectName().isEmpty())
            AddingContract->setObjectName("AddingContract");
        AddingContract->resize(528, 397);
        formLayoutWidget = new QWidget(AddingContract);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 30, 421, 251));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        FIO = new QLineEdit(formLayoutWidget);
        FIO->setObjectName("FIO");

        formLayout->setWidget(0, QFormLayout::FieldRole, FIO);

        Reward = new QLineEdit(formLayoutWidget);
        Reward->setObjectName("Reward");

        formLayout->setWidget(1, QFormLayout::FieldRole, Reward);

        pushButton = new QPushButton(AddingContract);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 320, 141, 51));

        retranslateUi(AddingContract);

        QMetaObject::connectSlotsByName(AddingContract);
    } // setupUi

    void retranslateUi(QWidget *AddingContract)
    {
        AddingContract->setWindowTitle(QCoreApplication::translate("AddingContract", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddingContract", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("AddingContract", "\320\235\320\260\320\263\321\200\320\260\320\266\320\264\320\265\320\275\320\270\320\265", nullptr));
        pushButton->setText(QCoreApplication::translate("AddingContract", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\275\321\202\321\200\320\260\320\272\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddingContract: public Ui_AddingContract {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINGCONTRACT_H
