#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMediaPlayer>



#include"MusicBeans.h"
#include"downloadmusic.h"
#include"player.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:

    //检索本地音乐文件并添加进songlist
    //bool init_SongList();

private slots:


private:
    Ui::MainWindow *ui;



    //界面空间
    downloadMusic *music_table;         //音乐表格
            //播放器
            //搜索页面



    SongList localSongs;

};
#endif // MAINWINDOW_H
