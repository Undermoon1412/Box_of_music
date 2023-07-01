#ifndef SERCHRESULT_H
#define SERCHRESULT_H

#include <QWidget>
#include<QIcon>

#include"MusicBeans.h"

#define COL_NUMS 4
#define MAX_SONGS 10
enum
{
    titleCol,       //标题列
    artistCol,      //歌手列
    albumCol,       //专辑列
    durationCol     //时长列
};


namespace Ui {
class SerchResult;
}

class SerchResult : public QWidget
{
    Q_OBJECT

public:
    explicit SerchResult(QString Text,QWidget *parent = nullptr);
    ~SerchResult();

    //初始化表格
    void inittable();

    //开始搜索
    void serch_music();

    //开始下载
    bool down_music();

    //添加进表格
    void append_table();


    /*
     * 在表格上添加一个右击事件，触发以下事件
     * 1，下载
     * 2，提示下载完成
     * 3，初始化表格
    */



private slots:
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);


private:
    Ui::SerchResult *ui;

    QIcon tittle_icon=QIcon(".//res//iTunes.ico");
    QString serch_text;     //搜索关键词，由构造函数 传过来
    QString tittle_text = QString("搜索结果:");


    SongList searchResultSongs;     //搜索结果集
    Music downloadingSong;      //下载单曲

};

#endif // SERCHRESULT_H
