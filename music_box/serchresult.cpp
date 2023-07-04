#include "serchresult.h"
#include "ui_serchresult.h"
#include "downloadmusic.h"
#include "player.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QPropertyAnimation>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include<QFile>
#include<QMenu>
#include<QMessageBox>
#include<QAction>

//将msecond转换为时长
QString msecondToString(qint64 msecond);

SerchResult::SerchResult(QString Text,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerchResult)
{
    ui->setupUi(this);

    serch_text = Text;

    //初始化表格
    inittable();

    //开始搜索
    serch_music();

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);   //设置右键菜单
}



SerchResult::~SerchResult()
{
    delete ui;
}


//初始化表格
void SerchResult::inittable()
{
    //设置表头格式
    ui->tableWidget->setColumnCount(COL_NUMS);
    QStringList headers{ QString("标题"),
                        QString("作者"),
                        QString("专辑"),
                        QString("时长") };
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    QFont font ;//定义一个字体变量
    font.setBold(true);  //设置粗体
    ui->tableWidget->horizontalHeader()->setFont(font);//把字体变量属性加进表头中
    ui->tableWidget->setFrameShape(QFrame::NoFrame); //设置无边框
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //设置表头充满表格的宽度
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置表格内容不可编辑
    //设置表头宽度
    ui->tableWidget->horizontalHeader()->resizeSection(titleCol,300);
    ui->tableWidget->horizontalHeader()->resizeSection(artistCol,110);
    ui->tableWidget->horizontalHeader()->resizeSection(albumCol,110);
    ui->tableWidget->horizontalHeader()->resizeSection(durationCol,110);


    //设置选择行为时每次一行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    this->setWindowTitle(tittle_text + serch_text);
    this->setWindowIcon(tittle_icon);

}



//开始搜索
void SerchResult::serch_music()
{
    //爬取前的准备
    QString url = "http://iwxyi.com:3000/search?keywords=" + serch_text.toUtf8().toPercentEncoding();
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest* request = new QNetworkRequest(url);

    request->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded; charset=UTF-8");
    request->setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.111 Safari/537.36");

    connect(manager,&QNetworkAccessManager::finished,this,[=](QNetworkReply* reply){
        //爬取该网站的所有内容
        QByteArray data = reply->readAll();

        //qDebug()<<data;


        //将内容变成JSON数据
        QJsonParseError error;
        QJsonDocument document = QJsonDocument::fromJson(data, &error);
        if (error.error != QJsonParseError::NoError)
        {
            //检错
            qDebug() << error.errorString();
            return;
        }

        QJsonObject json = document.object();
        if (json.value("code").toInt() != 200)
        {
            qDebug() << ("返回结果不为200：") << json.value("message").toString();
            return;
        }

        //将JSON数据里面的result下的songs的数据全部转到QJSON Array里面
        QJsonArray musics = json.value("result").toObject().value("songs").toArray();


        //将解析出来的数据存放到 searchResultSongs list列表中
        searchResultSongs.clear();		//searchResultSongs ==》 Qlist<Music>
        int song_nums = 0;
        foreach(QJsonValue val, musics)
        {
            //只存放搜索结果的前十条
            if(song_nums >= MAX_SONGS)
            {
                break;
            }
            song_nums++;
            searchResultSongs << Music::fromJson(val.toObject());		//此处调用了静态方法，解析JSONObject数据返回Music数据类型

        }

        //将searchResultSongs放到列表中
        //只能在此处append 放在connect外面则为空
        append_table();
    });

    manager->get(*request);



}


//开始下载
bool SerchResult::down_music()
{
    //判定downloadingsong里面有没有内容
    if(!downloadingSong.isValid())
    {
        qDebug()<<"downloadingSong 是空的！";
        return false;
    }

    QString API_DOMAIN = "http://iwxyi.com:3000/";
    qDebug()<<"searchResultSongs size:"<<searchResultSongs.size();
    //准备
    //downloadingSong = searchResultSongs.at(0);
    QString url = API_DOMAIN + "/song/url?id=" + snum(downloadingSong.id);	//http://iwxyi.com:3000/song/url?id=347230
    qDebug() << QString::fromLocal8Bit("获取歌曲信息：") << downloadingSong.simpleString();
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest* request = new QNetworkRequest(url);
    request->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded; charset=UTF-8");
    request->setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.111 Safari/537.36");

    //触发事件：正式下载
    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply)
            {
                //读取爬下来的数据
                QByteArray baData = reply->readAll();
                QJsonParseError error;
                QJsonDocument document = QJsonDocument::fromJson(baData, &error);
                if (error.error != QJsonParseError::NoError)
                {
                    qDebug() << error.errorString();
                    return;
                }
                QJsonObject json = document.object();
                if (json.value("code").toInt() != 200)
                {
                    qDebug() << QString::fromLocal8Bit("返回结果不为200：") << json.value("message").toString();
                    return;
                }
                QJsonArray array = json.value("data").toArray();

                if (!array.size())
                {
                    qDebug() << QString::fromLocal8Bit("未找到歌曲：") << downloadingSong.simpleString();                                                                downloadingSong = Music();  // 清空		//downloadingSong 一个music
                    //downloadNext();
                    return;
                }

                //数据筛选；获取歌曲信息
                json = array.first().toObject();
                QString url = JVAL_STR(url);
                int br = JVAL_INT(br); // 比率320000
                int size = JVAL_INT(size);
                QString type = JVAL_STR(type); // mp3
                QString encodeType = JVAL_STR(encodeType); // mp3
                qDebug() << QString::fromLocal8Bit(" 信息：" )<< br << size << type << encodeType << url;
                    if (size == 0)
                {
                    qDebug() << QString::fromLocal8Bit("下载失败， 可能没有版权") << downloadingSong.simpleString();
                        return;
                }

                // 下载歌曲本身
                QNetworkAccessManager manager;
                QEventLoop loop;
                QNetworkReply *reply1 = manager.get(QNetworkRequest(QUrl(url)));
                // 请求结束并完成下载后退出子事件循环
                qDebug()<<"开始下载";
                connect(reply1, &QNetworkReply::finished, &loop, &QEventLoop::quit);

                // 开启子事件循环
                loop.exec();
                QByteArray baData1 = reply1->readAll();

                QString strPath = QString("D:\\QT_file\\music\\music_box\\LocalMusic\\%0.mp3").arg(downloadingSong.name) ;
                QFile file(strPath);
                file.open(QIODevice::WriteOnly);
                file.write(baData1);
                file.flush();
                file.close();

                qDebug()<<"下载完成";
                is_F5 = true;       //如果将这个变量置为真，则表明需要更新本地列表了


            });


    manager->get(*request);

    return true;    //return 必须放在最下面

}

//添加进表格
void SerchResult::append_table()
{
    // 设置列长度
    QFontMetrics fm(font());
    int fw = fm.horizontalAdvance("一二三四五六七八九十十一十二十三十四十五");
    auto createItem = [=](QString s) {
        QTableWidgetItem *item = new QTableWidgetItem();
        if (s.length() > 16 && fm.horizontalAdvance(s) > fw)
        {
            item->setToolTip(s);
            s = s.left(15) + "...";
        }
        item->setText(s);
        return item;
    };

    qDebug()<<"in append table"<<searchResultSongs.size();
    //添加进表
    ui->tableWidget->setRowCount(searchResultSongs.size());
    for (int row = 0; row < searchResultSongs.size(); row++)
    {
        Music song = searchResultSongs.at(row);
        ui->tableWidget->setItem(row, titleCol, createItem(song.name));                             //歌曲名
        ui->tableWidget->setItem(row, artistCol, createItem(song.artistNames));                     //歌手
        ui->tableWidget->setItem(row, albumCol, createItem(song.album.name));                       //专辑
        ui->tableWidget->setItem(row, durationCol, createItem(msecondToString(song.duration)));		//时长
    }

    //自动对齐列宽
    QTimer::singleShot(0, [=]
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
     });

}

QString msecondToString(qint64 msecond)
{
    return QString("%1:%2").arg(msecond / 1000 / 60, 2, 10, QLatin1Char('0'))
        .arg(msecond / 1000 % 60, 2, 10, QLatin1Char('0'));
}

//右键菜单
void SerchResult::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{

    //添加菜单1
    QMenu menu;
    QAction *download = menu.addAction(tr("下载"));
    menu.addSeparator();


    unsigned int curr_row = ui->tableWidget->currentRow();
    downloadingSong = searchResultSongs.at(curr_row);

    qDebug()<<downloadingSong.name<<downloadingSong.artistNames;

    //点击了右击菜单
    connect(download,&QAction::triggered,[=]{

        bool is_down = down_music();
        qDebug()<<is_down;
        if(is_down)
        {   //成功
            //弹窗
            QMessageBox msgBox;
            msgBox.setText("下载成功！");
            msgBox.exec();

        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("下载失败！");
            msgBox.exec();
        }

    });


    qDebug()<<pos<<ui->tableWidget->currentRow();
    menu.exec(QCursor::pos());  //菜单出现的位置  //这条语句必须放下面，不然Action不能响应

}
