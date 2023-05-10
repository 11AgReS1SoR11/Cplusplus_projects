/********************************************************************************
** Form generated from reading UI file 'changerate.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGERATE_H
#define UI_CHANGERATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeRate
{
public:
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *Position;
    QLabel *label;
    QLineEdit *Date;
    QLabel *label_3;
    QLineEdit *NewRate;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *LastRate;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *ChangeRate)
    {
        if (ChangeRate->objectName().isEmpty())
            ChangeRate->setObjectName("ChangeRate");
        ChangeRate->resize(596, 507);
        pushButton = new QPushButton(ChangeRate);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(410, 390, 121, 71));
        formLayoutWidget = new QWidget(ChangeRate);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(40, 30, 491, 331));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        Position = new QComboBox(formLayoutWidget);
        Position->setObjectName("Position");

        formLayout->setWidget(0, QFormLayout::FieldRole, Position);

        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        Date = new QLineEdit(formLayoutWidget);
        Date->setObjectName("Date");

        formLayout->setWidget(1, QFormLayout::FieldRole, Date);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        NewRate = new QLineEdit(formLayoutWidget);
        NewRate->setObjectName("NewRate");

        formLayout->setWidget(2, QFormLayout::FieldRole, NewRate);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(7, QFormLayout::FieldRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::FieldRole, verticalSpacer_2);

        LastRate = new QLabel(formLayoutWidget);
        LastRate->setObjectName("LastRate");
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(11);
        font.setBold(true);
        LastRate->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, LastRate);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::FieldRole, verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::FieldRole, verticalSpacer_4);


        retranslateUi(ChangeRate);

        QMetaObject::connectSlotsByName(ChangeRate);
    } // setupUi

    void retranslateUi(QWidget *ChangeRate)
    {
        ChangeRate->setWindowTitle(QCoreApplication::translate("ChangeRate", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ChangeRate", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("ChangeRate", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("ChangeRate", "\320\224\320\260\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("ChangeRate", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        LastRate->setText(QCoreApplication::translate("ChangeRate", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeRate: public Ui_ChangeRate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGERATE_H
