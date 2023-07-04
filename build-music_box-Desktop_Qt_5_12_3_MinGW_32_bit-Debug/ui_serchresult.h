/********************************************************************************
** Form generated from reading UI file 'serchresult.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERCHRESULT_H
#define UI_SERCHRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerchResult
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *serch_result;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *SerchResult)
    {
        if (SerchResult->objectName().isEmpty())
            SerchResult->setObjectName(QString::fromUtf8("SerchResult"));
        SerchResult->resize(800, 550);
        horizontalLayout = new QHBoxLayout(SerchResult);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        serch_result = new QWidget(SerchResult);
        serch_result->setObjectName(QString::fromUtf8("serch_result"));
        horizontalLayout_2 = new QHBoxLayout(serch_result);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(serch_result);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);

        horizontalLayout_2->addWidget(tableWidget);


        horizontalLayout->addWidget(serch_result);


        retranslateUi(SerchResult);

        QMetaObject::connectSlotsByName(SerchResult);
    } // setupUi

    void retranslateUi(QWidget *SerchResult)
    {
        SerchResult->setWindowTitle(QApplication::translate("SerchResult", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerchResult: public Ui_SerchResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERCHRESULT_H
