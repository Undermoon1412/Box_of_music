/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <chat.h>
#include <downloadmusic.h>
#include <player.h>
#include <serchmusic.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QWidget *main_widget;
    QTabWidget *tabWidget;
    SerchMusic *tab;
    downloadMusic *tab_2;
    chat *tab_3;
    player *musicplayer_widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(832, 528);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/iTunes.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        main_widget = new QWidget(widget);
        main_widget->setObjectName(QString::fromUtf8("main_widget"));
        main_widget->setGeometry(QRect(-10, 0, 831, 381));
        tabWidget = new QTabWidget(main_widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 801, 351));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget QTabBar::tab\n"
"{\n"
"	font-size:25px;\n"
"}\n"
"\n"
"QTabWidget QTabBar\n"
"{\n"
"	font-size: 25px;\n"
"	font-weight:bold;\n"
"	width:400;\n"
"	\n"
"}\n"
""));
        tabWidget->setIconSize(QSize(25, 25));
        tabWidget->setDocumentMode(false);
        tabWidget->setMovable(false);
        tab = new SerchMusic();
        tab->setObjectName(QString::fromUtf8("tab"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon1, QString());
        tab_2 = new downloadMusic();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, icon1, QString());
        tab_3 = new chat();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        musicplayer_widget = new player(widget);
        musicplayer_widget->setObjectName(QString::fromUtf8("musicplayer_widget"));
        musicplayer_widget->setGeometry(QRect(10, 380, 801, 131));

        verticalLayout_2->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\256\200\346\230\223\346\222\255\346\224\276\345\231\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\346\220\234\347\264\242\351\237\263\344\271\220", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
