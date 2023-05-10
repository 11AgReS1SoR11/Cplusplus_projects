/********************************************************************************
** Form generated from reading UI file 'reports.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTS_H
#define UI_REPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reports
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page_7;
    QPushButton *PaySheet;
    QWidget *page_8;
    QPushButton *pushButton_6;
    QComboBox *FIO;
    QLineEdit *DateStart;
    QLineEdit *DateEnd;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QPushButton *YearUp;
    QWidget *page_2;
    QPushButton *pushButton_7;
    QComboBox *FIO_2;
    QLineEdit *Year;
    QPushButton *Return;

    void setupUi(QWidget *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName("Reports");
        Reports->resize(935, 592);
        verticalLayoutWidget = new QWidget(Reports);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 50, 841, 521));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(verticalLayoutWidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(0, 50));
        stackedWidget->setMaximumSize(QSize(16777215, 50));
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        PaySheet = new QPushButton(page_7);
        PaySheet->setObjectName("PaySheet");
        PaySheet->setGeometry(QRect(0, 0, 841, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PaySheet->sizePolicy().hasHeightForWidth());
        PaySheet->setSizePolicy(sizePolicy1);
        PaySheet->setMinimumSize(QSize(0, 50));
        PaySheet->setMaximumSize(QSize(16777215, 50));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        pushButton_6 = new QPushButton(page_8);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(740, 0, 80, 45));
        pushButton_6->setMinimumSize(QSize(0, 45));
        pushButton_6->setMaximumSize(QSize(16777215, 45));
        FIO = new QComboBox(page_8);
        FIO->setObjectName("FIO");
        FIO->setGeometry(QRect(200, 0, 541, 45));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(FIO->sizePolicy().hasHeightForWidth());
        FIO->setSizePolicy(sizePolicy2);
        FIO->setMinimumSize(QSize(0, 45));
        FIO->setMaximumSize(QSize(16777215, 45));
        DateStart = new QLineEdit(page_8);
        DateStart->setObjectName("DateStart");
        DateStart->setGeometry(QRect(20, 10, 61, 30));
        DateStart->setMinimumSize(QSize(0, 30));
        DateStart->setMaximumSize(QSize(16777215, 30));
        DateEnd = new QLineEdit(page_8);
        DateEnd->setObjectName("DateEnd");
        DateEnd->setGeometry(QRect(120, 10, 61, 30));
        DateEnd->setMinimumSize(QSize(0, 30));
        DateEnd->setMaximumSize(QSize(16777215, 30));
        label = new QLabel(page_8);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 10, 31, 21));
        stackedWidget->addWidget(page_8);

        verticalLayout_2->addWidget(stackedWidget);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 50));
        pushButton->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(pushButton);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(pushButton_4);

        stackedWidget_2 = new QStackedWidget(verticalLayoutWidget);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setMinimumSize(QSize(0, 50));
        stackedWidget_2->setMaximumSize(QSize(16777215, 50));
        page = new QWidget();
        page->setObjectName("page");
        YearUp = new QPushButton(page);
        YearUp->setObjectName("YearUp");
        YearUp->setGeometry(QRect(0, 0, 841, 50));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(YearUp->sizePolicy().hasHeightForWidth());
        YearUp->setSizePolicy(sizePolicy3);
        YearUp->setMinimumSize(QSize(0, 50));
        YearUp->setMaximumSize(QSize(16777215, 50));
        stackedWidget_2->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(740, 0, 80, 45));
        pushButton_7->setMinimumSize(QSize(0, 45));
        pushButton_7->setMaximumSize(QSize(16777215, 45));
        FIO_2 = new QComboBox(page_2);
        FIO_2->setObjectName("FIO_2");
        FIO_2->setGeometry(QRect(200, 0, 541, 45));
        sizePolicy2.setHeightForWidth(FIO_2->sizePolicy().hasHeightForWidth());
        FIO_2->setSizePolicy(sizePolicy2);
        FIO_2->setMinimumSize(QSize(0, 45));
        FIO_2->setMaximumSize(QSize(16777215, 45));
        Year = new QLineEdit(page_2);
        Year->setObjectName("Year");
        Year->setGeometry(QRect(90, 0, 113, 45));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(45);
        sizePolicy4.setHeightForWidth(Year->sizePolicy().hasHeightForWidth());
        Year->setSizePolicy(sizePolicy4);
        Year->setMinimumSize(QSize(0, 45));
        stackedWidget_2->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget_2);

        Return = new QPushButton(Reports);
        Return->setObjectName("Return");
        Return->setGeometry(QRect(10, 10, 80, 24));
        Return->setStyleSheet(QString::fromUtf8("a.Return {\n"
"  display: inline-block;\n"
"  font-weight: bold;\n"
"  color: #fff;\n"
"  text-decoration: none;\n"
"  text-shadow: 0 -1px rgba(0,0,0,.5);\n"
"  user-select: none;\n"
"  padding: .7em 1.5em;\n"
"  border: 1px solid rgb(80,32,0);\n"
"  border-radius: 5px;\n"
"  outline: none;\n"
"  background: rgb(147,80,36) linear-gradient(rgb(106,58,26), rgb(147,80,36) 80%);\n"
"  box-shadow:\n"
"   0 6px rgb(86,38,6),\n"
"   0 3px 15px rgba(0,0,0,.4),\n"
"   inset 0 1px rgba(255,255,255,.3),\n"
"   inset 0 0 3px rgba(255,255,255,.5);\n"
"  transition: .2s;\n"
"} \n"
".Return:hover {\n"
"  background: rgb(167,91,41) linear-gradient(rgb(126,69,31), rgb(167,91,41) 80%);\n"
"}\n"
".Return:active {\n"
"  background: rgb(120,63,25) linear-gradient(rgb(120,63,25) 20%, rgb(167,91,41));\n"
"  box-shadow:\n"
"   0 2px rgb(86,38,6),\n"
"   0 1px 6px rgba(0,0,0,.4),\n"
"   inset 0 1px rgba(255,255,255,.3),\n"
"   inset 0 0 3px rgba(255,255,255,.5);\n"
"  -webkit-transform: translate(0, 4px);\n"
"  transform: translate(0,"
                        " 4px);\n"
"}"));

        retranslateUi(Reports);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Reports);
    } // setupUi

    void retranslateUi(QWidget *Reports)
    {
        Reports->setWindowTitle(QCoreApplication::translate("Reports", "Form", nullptr));
        PaySheet->setText(QCoreApplication::translate("Reports", "\320\240\320\260\321\201\321\207\321\221\321\202\320\275\321\213\320\271 \320\273\320\270\321\201\321\202", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Reports", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("Reports", "----", nullptr));
        pushButton->setText(QCoreApplication::translate("Reports", "\320\237\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\265 \320\276\320\261 \321\203\320\262\320\276\320\273\321\214\320\275\320\265\320\275\320\270\320\265", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Reports", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\262\320\260\320\272\320\260\320\275\321\201\320\270\320\271", nullptr));
        YearUp->setText(QCoreApplication::translate("Reports", "\320\223\320\276\320\264\320\276\320\262\320\276\320\271 \320\264\320\276\321\205\320\276\320\264 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Reports", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        Return->setText(QCoreApplication::translate("Reports", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
