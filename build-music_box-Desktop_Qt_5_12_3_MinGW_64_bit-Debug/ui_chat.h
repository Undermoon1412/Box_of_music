/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QLineEdit *leport;
    QLabel *label_2;
    QPlainTextEdit *textSend;
    QPushButton *sendBtn;
    QPushButton *connectBtn;
    QLineEdit *leipAddress;
    QTableWidget *tableWidget;
    QTextEdit *textReceive;
    QLabel *label;

    void setupUi(QWidget *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QString::fromUtf8("chat"));
        chat->resize(620, 337);
        leport = new QLineEdit(chat);
        leport->setObjectName(QString::fromUtf8("leport"));
        leport->setGeometry(QRect(360, 20, 81, 21));
        label_2 = new QLabel(chat);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 20, 72, 15));
        textSend = new QPlainTextEdit(chat);
        textSend->setObjectName(QString::fromUtf8("textSend"));
        textSend->setGeometry(QRect(30, 280, 291, 31));
        sendBtn = new QPushButton(chat);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(330, 280, 81, 28));
        connectBtn = new QPushButton(chat);
        connectBtn->setObjectName(QString::fromUtf8("connectBtn"));
        connectBtn->setGeometry(QRect(490, 20, 81, 28));
        leipAddress = new QLineEdit(chat);
        leipAddress->setObjectName(QString::fromUtf8("leipAddress"));
        leipAddress->setGeometry(QRect(100, 20, 151, 21));
        tableWidget = new QTableWidget(chat);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(430, 60, 171, 251));
        textReceive = new QTextEdit(chat);
        textReceive->setObjectName(QString::fromUtf8("textReceive"));
        textReceive->setGeometry(QRect(30, 60, 381, 201));
        label = new QLabel(chat);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 20, 72, 15));

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Form", nullptr));
        leport->setText(QApplication::translate("chat", "8888", nullptr));
        label_2->setText(QApplication::translate("chat", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        sendBtn->setText(QApplication::translate("chat", "\345\217\221\351\200\201", nullptr));
        connectBtn->setText(QApplication::translate("chat", "\350\277\236\346\216\245", nullptr));
        leipAddress->setText(QApplication::translate("chat", "10.148.41.88", nullptr));
        label->setText(QApplication::translate("chat", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
