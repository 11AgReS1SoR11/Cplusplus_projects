/********************************************************************************
** Form generated from reading UI file 'addingallowance.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINGALLOWANCE_H
#define UI_ADDINGALLOWANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddingAllowance
{
public:
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Name;
    QLineEdit *Reward;

    void setupUi(QWidget *AddingAllowance)
    {
        if (AddingAllowance->objectName().isEmpty())
            AddingAllowance->setObjectName("AddingAllowance");
        AddingAllowance->resize(604, 451);
        pushButton = new QPushButton(AddingAllowance);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(410, 350, 121, 61));
        formLayoutWidget = new QWidget(AddingAllowance);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 30, 501, 291));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        Name = new QLineEdit(formLayoutWidget);
        Name->setObjectName("Name");

        formLayout->setWidget(0, QFormLayout::FieldRole, Name);

        Reward = new QLineEdit(formLayoutWidget);
        Reward->setObjectName("Reward");

        formLayout->setWidget(1, QFormLayout::FieldRole, Reward);


        retranslateUi(AddingAllowance);

        QMetaObject::connectSlotsByName(AddingAllowance);
    } // setupUi

    void retranslateUi(QWidget *AddingAllowance)
    {
        AddingAllowance->setWindowTitle(QCoreApplication::translate("AddingAllowance", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("AddingAllowance", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("AddingAllowance", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("AddingAllowance", "\320\235\320\260\320\263\321\200\320\260\320\266\320\264\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddingAllowance: public Ui_AddingAllowance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINGALLOWANCE_H
