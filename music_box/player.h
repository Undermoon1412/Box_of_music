#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include<QMediaPlayer>
#include<QUrl>
#define TIMER_TIMEOUT 1000


extern int C_curr_row ;      //此变量代表所选的行数，用来接受表格双击的行号


namespace Ui {
class player;
}

class player : public QWidget
{
    Q_OBJECT

public:
    explicit player(QWidget *parent = nullptr);
    ~player();

public:
    void init_all();            //初始化全部
    void init_bofangqi();       //初始化播放器
    void button_bofan();        //播放按钮的操作
    void change_play_icon();    //改变播放按钮的操作

    void change_music(int index);   //根据index切换当前歌曲

    void jindutiao();           //进度条以及时间标签的设置

    void volume_change(int volume);       //音量改变
    void changePlayStyle(int);

signals:


public slots:
    void table_doubleclick(int row,int col);
    void listen_C_curr();


private slots:
    void on_pb_bofang_clicked();        //播放

    void on_pb_lastsong_clicked();      //上一首

    void on_pb_nextsong_clicked();      //下一首

    //表格按钮点击事件



    void on_pushButton_clicked();

private:
    Ui::player *ui;
    bool is_pause;                      //标志位：表示是否处于暂停状态
    unsigned int song_nums = 0;         //表示当前获取到的歌曲数
    unsigned int curr_song_Index = 0;   //表示当前选取的歌曲index
    unsigned int postion = 0;           //表示当前播放的位置
    unsigned int m_volume = 50;           //表示当前音量
    QStringList MusicName_list;         //存放当列表中的歌曲名

    QMediaPlayer *player_music;   //播放器
    QMediaPlaylist *playlist ;  //播放列表
    QTimer *m_pTimer;
    int playModel=0;
    float rate = 1.0;
};

#endif // PLAYER_H
