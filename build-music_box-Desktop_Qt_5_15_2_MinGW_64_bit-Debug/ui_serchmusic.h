/********************************************************************************
** Form generated from reading UI file 'serchmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERCHMUSIC_H
#define UI_SERCHMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerchMusic
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *pb_serch;
    QLineEdit *le_SerchText;

    void setupUi(QWidget *SerchMusic)
    {
        if (SerchMusic->objectName().isEmpty())
            SerchMusic->setObjectName(QString::fromUtf8("SerchMusic"));
        SerchMusic->resize(736, 290);
        verticalLayout = new QVBoxLayout(SerchMusic);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SerchMusic);
        widget->setObjectName(QString::fromUtf8("widget"));
        pb_serch = new QPushButton(widget);
        pb_serch->setObjectName(QString::fromUtf8("pb_serch"));
        pb_serch->setGeometry(QRect(500, 90, 161, 61));
        le_SerchText = new QLineEdit(widget);
        le_SerchText->setObjectName(QString::fromUtf8("le_SerchText"));
        le_SerchText->setGeometry(QRect(100, 90, 351, 61));

        verticalLayout->addWidget(widget);


        retranslateUi(SerchMusic);

        QMetaObject::connectSlotsByName(SerchMusic);
    } // setupUi

    void retranslateUi(QWidget *SerchMusic)
    {
        SerchMusic->setWindowTitle(QCoreApplication::translate("SerchMusic", "Form", nullptr));
        pb_serch->setText(QCoreApplication::translate("SerchMusic", "\345\274\200\345\247\213\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerchMusic: public Ui_SerchMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERCHMUSIC_H
