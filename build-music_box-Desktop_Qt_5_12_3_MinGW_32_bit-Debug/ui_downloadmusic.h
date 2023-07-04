/********************************************************************************
** Form generated from reading UI file 'downloadmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADMUSIC_H
#define UI_DOWNLOADMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_downloadMusic
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *downloadMusic)
    {
        if (downloadMusic->objectName().isEmpty())
            downloadMusic->setObjectName(QString::fromUtf8("downloadMusic"));
        downloadMusic->resize(631, 287);
        verticalLayout = new QVBoxLayout(downloadMusic);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(downloadMusic);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);


        verticalLayout->addWidget(widget);


        retranslateUi(downloadMusic);

        QMetaObject::connectSlotsByName(downloadMusic);
    } // setupUi

    void retranslateUi(QWidget *downloadMusic)
    {
        downloadMusic->setWindowTitle(QApplication::translate("downloadMusic", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class downloadMusic: public Ui_downloadMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADMUSIC_H
