#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QDateTime>
#include <QMessageBox>
#include <QSound>
#include <QIcon>
#include <QNetworkProxy>
#include <QWidget>
#include <QString>

namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();
    QSound *messageSound;
    QSound *connectSound;

private slots:
    void on_connectBtn_clicked();   //连接按钮

    void on_sendBtn_clicked();      //发送按钮

    void readMessage();         //接收信息

    void disconnectSlot();          //断开连接槽函数

private:
    Ui::chat *ui;


    QString name = "";
    QTcpSocket *socket;
    bool connectState;  //客户端连接状态
};

#endif // CHAT_H
