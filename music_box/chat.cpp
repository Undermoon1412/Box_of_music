#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    ui->connectBtn->setStyleSheet("background-color: rgb(6,163,220)");
    ui->sendBtn->setStyleSheet("background-color: rgb(6,163,220)");
    ui->leport->setStyleSheet("color:blue");
    ui->leipAddress->setStyleSheet("color:blue");

    //ui->listWeiget->setStyleSheet("border:2px solid blue");

    socket = new QTcpSocket(this);
    connectState = false;     //未连接状态

    messageSound = new QSound(":/new/prefix1/sounds/iphone.wav", this);
    connectSound = new QSound(":/new/prefix1/sounds/keke.wav", this);

//    this->setWindowIcon(QIcon(":/new/prefix1/image/qq.png"));

    name = ui->leport_2->text();

    connect(socket, &QTcpSocket::readyRead, this, &chat::readMessage);    //接收信息
    connect(socket, &QTcpSocket::disconnected, this, &chat::disconnectSlot);   //打印断开连接信息
}

chat::~chat()
{
    delete ui;
}

void chat::readMessage()    //接收信息
{
    messageSound->play();
    QByteArray arr = socket->readAll();
//    QString str;
//    str = QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss") + '\n' + arr.data();
//    qDebug()<<arr.data()<<endl;

//    name = ui->leport_2->text();
    //ui->textReceive->append(QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss"));
    ui->textReceive->append(arr.data());     //显示信息
}


void chat::disconnectSlot()    //打印连接断开信息
{
//    ui->listWidget->addItem("clint disconnected");
    QMessageBox::warning(this, "连接断开", socket->errorString());
}


void chat::on_connectBtn_clicked()      //与客户端连接或者断开
{
    QString ipStr = ui->leipAddress->text();    //界面显示的地址
    quint16 currentPort = ui->leport->text().toInt();   //界面显示的当前端口
    if(!connectState)    //客户端还未连接服务端
    {
        socket->connectToHost(ipStr, currentPort);   //连接服务端
        if(socket->waitForConnected())   //等待连接成功
        {
           // ui->listWidget->addItem("连接成功");
            QMessageBox::information(this, "连上服务器", "欢迎上线");
            ui->connectBtn->setText("关闭连接");
            connectSound->play();
            connectState = true;
        }

        else     //连接失败
        {
            QMessageBox::warning(this, "连接失败", socket->errorString());   //连接错误信息提醒
        }
    }
    else   //客户端已经连接
    {
        socket->close();   //关闭套接字，此时会发送disconnected信号
        connectSound->play();
        ui->connectBtn->setText("连接");
        connectState = false;
    }
}


void chat::on_sendBtn_clicked()    //给服务端发送信息
{
    QString str = ui->textSend->toPlainText();
    name = ui->leport_2->text();
    qDebug()<<name+": "+str<<endl;

    if(socket->isOpen() && socket->isValid())
    {
        socket->write((name+": "+str).toUtf8());    //给服务端发送信息
        ui->textSend->clear();
    }

    QString showStr = QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss") + '\n' +name+": "+ str;
    ui->textReceive->append(showStr);     //显示自己发送的信息
}
