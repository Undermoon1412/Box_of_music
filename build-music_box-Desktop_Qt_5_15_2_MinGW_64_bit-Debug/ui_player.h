/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_player
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QPushButton *pb_lastsong;
    QPushButton *pb_nextsong;
    QPushButton *pb_bofang;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_begin;
    QSlider *jindutiao;
    QLabel *label_end;
    QLabel *label_MusicName;
    QSlider *hs_yinliang;
    QLabel *label_yltext;
    QLabel *label_yinliang;
    QPushButton *pushButton;

    void setupUi(QWidget *player)
    {
        if (player->objectName().isEmpty())
            player->setObjectName(QString::fromUtf8("player"));
        player->resize(755, 114);
        verticalLayout = new QVBoxLayout(player);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(player);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setLayoutDirection(Qt::LeftToRight);
        pb_lastsong = new QPushButton(widget);
        pb_lastsong->setObjectName(QString::fromUtf8("pb_lastsong"));
        pb_lastsong->setGeometry(QRect(260, 40, 51, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/lastsong.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_lastsong->setIcon(icon);
        pb_lastsong->setIconSize(QSize(25, 25));
        pb_nextsong = new QPushButton(widget);
        pb_nextsong->setObjectName(QString::fromUtf8("pb_nextsong"));
        pb_nextsong->setGeometry(QRect(460, 40, 51, 51));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/nextsong.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_nextsong->setIcon(icon1);
        pb_nextsong->setIconSize(QSize(25, 25));
        pb_bofang = new QPushButton(widget);
        pb_bofang->setObjectName(QString::fromUtf8("pb_bofang"));
        pb_bofang->setGeometry(QRect(360, 40, 51, 51));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icon_play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_bofang->setIcon(icon2);
        pb_bofang->setIconSize(QSize(25, 25));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 741, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_begin = new QLabel(layoutWidget);
        label_begin->setObjectName(QString::fromUtf8("label_begin"));
        label_begin->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(label_begin);

        jindutiao = new QSlider(layoutWidget);
        jindutiao->setObjectName(QString::fromUtf8("jindutiao"));
        jindutiao->setStyleSheet(QString::fromUtf8("/*horizontal \357\274\232\346\260\264\345\271\263QSlider*/\n"
"QSlider::groove:horizontal {\n"
"border: 0px solid #bbb;\n"
"}\n"
"\n"
"/*1.\346\273\221\345\212\250\350\277\207\347\232\204\346\247\275\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::sub-page:horizontal {\n"
" /*\346\247\275\351\242\234\350\211\262*/\n"
"background: rgb(80, 255, 86);\n"
" /*\345\244\226\347\216\257\345\214\272\345\237\237\345\200\222\345\234\206\350\247\222\345\272\246*/\n"
"border-radius: 2px;\n"
" /*\344\270\212\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"margin-top:8px;\n"
" /*\344\270\213\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"margin-bottom:8px;\n"
"/*width\345\234\250\350\277\231\351\207\214\346\227\240\346\225\210\357\274\214\344\270\215\345\206\231\345\215\263\345\217\257*/\n"
"}\n"
"\n"
"/*2.\346\234\252\346\273\221\345\212\250\350\277\207\347\232\204\346\247\275\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::add-page:h"
                        "orizontal {\n"
"/*\346\247\275\351\242\234\350\211\262*/\n"
"background: rgb(255,255, 255);\n"
"/*\345\244\226\347\216\257\345\244\247\345\260\2170px\345\260\261\346\230\257\344\270\215\346\230\276\347\244\272\357\274\214\351\273\230\350\256\244\344\271\237\346\230\2570*/\n"
"border: 0px solid #777;\n"
"/*\345\244\226\347\216\257\345\214\272\345\237\237\345\200\222\345\234\206\350\247\222\345\272\246*/\n"
"border-radius: 2px;\n"
" /*\344\270\212\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"margin-top:9px;\n"
" /*\344\270\213\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"margin-bottom:9px;\n"
"}\n"
" \n"
"/*3.\345\271\263\346\227\266\346\273\221\345\212\250\347\232\204\346\273\221\345\235\227\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::handle:horizontal {\n"
"/*\346\273\221\345\235\227\351\242\234\350\211\262*/\n"
"background: rgb(193,204,208);\n"
"/*\346\273\221\345\235\227\347\232\204\345\256\275\345\272\246*/\n"
"width: 20px;"
                        "\n"
"/*\346\273\221\345\235\227\345\244\226\347\216\257\344\270\2721px\357\274\214\345\206\215\345\212\240\351\242\234\350\211\262*/\n"
"border: 1px solid rgb(193,204,208);\n"
" /*\346\273\221\345\235\227\345\244\226\347\216\257\345\200\222\345\234\206\350\247\222\345\272\246*/\n"
"border-radius: 2px; \n"
" /*\344\270\212\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"margin-top:6px;\n"
" /*\344\270\213\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"margin-bottom:6px;\n"
"}\n"
"\n"
"/*4.\346\211\213\345\212\250\346\213\211\345\212\250\346\227\266\346\230\276\347\244\272\347\232\204\346\273\221\345\235\227\350\256\276\350\256\241\345\217\202\346\225\260*/\n"
"QSlider::handle:horizontal:hover {\n"
"/*\346\273\221\345\235\227\351\242\234\350\211\262*/\n"
"background: rgb(193,204,208);\n"
"/*\346\273\221\345\235\227\347\232\204\345\256\275\345\272\246*/\n"
"width: 10px;\n"
"/*\346\273\221\345\235\227\345\244\226\347\216\257\344\270\2721px\357\274\214\345"
                        "\206\215\345\212\240\351\242\234\350\211\262*/\n"
"border: 1px solid rgb(80, 255, 86);\n"
" /*\346\273\221\345\235\227\345\244\226\347\216\257\345\200\222\345\234\206\350\247\222\345\272\246*/\n"
"border-radius: 5px; \n"
" /*\344\270\212\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"margin-top:4px;\n"
" /*\344\270\213\351\201\256\344\275\217\345\214\272\345\237\237\351\253\230\345\272\246*/\n"
"margin-bottom:4px;\n"
"}\n"
""));
        jindutiao->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(jindutiao);

        label_end = new QLabel(layoutWidget);
        label_end->setObjectName(QString::fromUtf8("label_end"));
        label_end->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        horizontalLayout->addWidget(label_end);

        label_MusicName = new QLabel(widget);
        label_MusicName->setObjectName(QString::fromUtf8("label_MusicName"));
        label_MusicName->setGeometry(QRect(30, 50, 171, 31));
        label_MusicName->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        hs_yinliang = new QSlider(widget);
        hs_yinliang->setObjectName(QString::fromUtf8("hs_yinliang"));
        hs_yinliang->setGeometry(QRect(560, 60, 160, 16));
        hs_yinliang->setOrientation(Qt::Horizontal);
        label_yltext = new QLabel(widget);
        label_yltext->setObjectName(QString::fromUtf8("label_yltext"));
        label_yltext->setGeometry(QRect(580, 70, 41, 20));
        label_yltext->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        label_yinliang = new QLabel(widget);
        label_yinliang->setObjectName(QString::fromUtf8("label_yinliang"));
        label_yinliang->setGeometry(QRect(630, 70, 31, 20));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 40, 51, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/res/random.png);\n"
"border-image: url(:/res/circle1.png);\n"
"border-image: url(:/res/circle.png);"));

        verticalLayout->addWidget(widget);


        retranslateUi(player);

        QMetaObject::connectSlotsByName(player);
    } // setupUi

    void retranslateUi(QWidget *player)
    {
        player->setWindowTitle(QCoreApplication::translate("player", "Form", nullptr));
        pb_lastsong->setText(QString());
        pb_nextsong->setText(QString());
        pb_bofang->setText(QString());
        label_begin->setText(QCoreApplication::translate("player", "00:00", nullptr));
        label_end->setText(QCoreApplication::translate("player", "00:00", nullptr));
        label_MusicName->setText(QCoreApplication::translate("player", "\346\232\202\346\227\240\346\222\255\346\224\276\351\237\263\344\271\220", nullptr));
        label_yltext->setText(QCoreApplication::translate("player", "\351\237\263\351\207\217\357\274\232", nullptr));
        label_yinliang->setText(QCoreApplication::translate("player", "0", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class player: public Ui_player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
