#include "player.h"
#include "ui_player.h"
#include "downloadmusic.h"

#include <iostream>
#include <random>
#include<QDir>
#include<QMediaPlaylist>
#include<QTimer>
#include <chrono>
#include <thread>

int C_curr_row = -1;


player::player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::player)
{
    ui->setupUi(this);

    init_all();


}

player::~player()
{
    delete ui;
    delete m_pTimer;
}


//按下播放按钮时
void player::on_pb_bofang_clicked()
{

    //播放暂停 图片的切换  //歌曲的开始和暂停
    QIcon pb_icon;
    if(is_pause)
    {
        pb_icon = QIcon(":/res//icon_play.png");
        player_music->pause();
        is_pause = false;
    }
    else
    {
        pb_icon = QIcon(":/res//pause.png");
        //playlist->setCurrentIndex(curr_song_Index);
        ui->label_MusicName->setText(MusicName_list[curr_song_Index]);
        player_music->play();
        is_pause = true;
    }
    ui->pb_bofang->setIcon(pb_icon);

}


//按下上一首按钮时
void player::on_pb_lastsong_clicked()
{
    if(curr_song_Index == 0)
    {
        //提示这是第一首，没有上一首
        return;
    }
    curr_song_Index--;

//    playlist->setCurrentIndex(curr_song_Index);
//    //音乐的播放图片切换
//    change_play_icon();

    change_music(curr_song_Index);
}


//按下下一首按钮
void player::on_pb_nextsong_clicked()
{
    curr_song_Index++;
    if(curr_song_Index == song_nums)
    {
        //提示这是最后一首，没有下一首了
        //也可以设置循环
        curr_song_Index = 0;
    }

//    playlist->setCurrentIndex(curr_song_Index);
//    //音乐的播放图片切换
//    change_play_icon();

    change_music(curr_song_Index);
}


//初始化播放器和播放列表
void player::init_bofangqi()
{
//初始化播放列表
//    if(player_music != NULL)
//        {
//            player_music->stop();
//            player_music->setPlaylist(NULL); //先将播放器中的播放列表清除
//            delete player_music;
//            player_music = NULL;
//        }
//        if(playlist != NULL)
//        {
//            playlist->clear();
//            delete playlist;
//            playlist = NULL;
//        }

    //创建新的播放器和播放列表
    player_music = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    player_music->setVolume(m_volume);
    player_music->setPlaylist(playlist);


    //打开指定目录    //默认打开本地文件
    QDir dir("D:\\QT_file\\music\\music_box\\LocalMusic");      //默认打开此文件夹
    QStringList nameFileters;
    nameFileters<<"*.mp3";      //进行文件筛选

    //将本地文件内的mp3文件放入表格中 4.30弄
    QStringList files=dir.entryList(nameFileters,QDir::Files|QDir::Readable,QDir::Name);
    MusicName_list = files; //将文件名列表赋值给成员变量

    //将音乐路径添加进播放器列表
    for(QString file_name:files)
    {
        QString file_path =dir.path()+QString("/")+file_name;
        qDebug()<<file_path;
        playlist->addMedia(QUrl::fromLocalFile(file_path));    //将路径添加进去
    }
    playlist->setCurrentIndex(0);
    player_music->setPlaylist(playlist);

     song_nums = playlist->mediaCount();

    qDebug()<<"加载成功，共"<< song_nums <<"首音乐";

}


//切换播放按钮的图片置播放状态
void player::change_play_icon()
{
    //设置按钮图片
    QIcon pb_icon = QIcon(":/res//pause.png");
    ui->pb_bofang->setIcon(pb_icon);

    //音乐的结束和从新播放
    player_music->stop();
    player_music->play();
    is_pause= true;
}


//表格双击按钮槽
void player::table_doubleclick(int row,int col)
{
    qDebug()<<"in"<<row<<col;
    //双击表格切换现在正在播放的音乐
    /*
     * 1,更改现在选择的歌曲index
     * 2，列表改变当前选中列表
     * 2，音乐停止，再播放
    */
    curr_song_Index = row;
    change_music(curr_song_Index);

}

//根据index切换当前歌曲
void player::change_music(int index)
{
    /*
     * 用到change_music的几种情况
     * 1，双击表格
     * 2，上一首
     * 3，下一首
    */

    //根据Index更改当前列表选中的歌曲
    playlist->setCurrentIndex(index);

    //音乐的播放的暂停
    player_music->stop();
    player_music->play();
    is_pause= true;

    //图标的切换
    QIcon pb_icon = QIcon(":/res//pause.png");
    ui->pb_bofang->setIcon(pb_icon);

    //设置当前正在播放的歌曲名
    ui->label_MusicName->setText(MusicName_list[index]);

}


//监听C_curr变量
void player::listen_C_curr()
{
    static int last_curr_index = 0;
    //qDebug()<<"in player:"<<C_curr_row<<"last_curr_index:"<<last_curr_index;
    if(C_curr_row != -1 )
    {
        if(C_curr_row != last_curr_index)
        {
            last_curr_index = C_curr_row;
            table_doubleclick(C_curr_row,0);
        }

    }

    if(is_F5)
    {
        //如果需要更新
        /*
         * 1，播放器停止
         * 2，播放列表清空
         * 3，进度条和时间戳
         * 4，重新初始化播放器
         *
         * 这样做会出错，原因是如果要刷新的话，上一次的指针没有释放干净
          */
//        playlist->clear();
//        player_music->stop();

//        init_bofangqi();
        init_all();


        is_F5 =false;
    }


}

//进度条以及时间标签的设置
void player::jindutiao()
{

    //播放时
    connect(player_music,&QMediaPlayer::positionChanged,[=](qint64 duration){
        if(ui->jindutiao->isSliderDown())
        {
            return ;
        }
        postion  = duration;        //记录当前位置

        ui->jindutiao->blockSignals(true);
        ui->jindutiao->setSliderPosition(int(duration));
        ui->jindutiao->blockSignals(false);
        int secs = int(duration)/1000;
        int min = secs/60; //取整
        secs = secs%60; //剩余秒
        qDebug()<< QString::asprintf("%d:%d",min,secs);     //输出当前播放的时间
        ui->label_begin->setText(QString::asprintf("%d:%d",min,secs));

        //本首音乐播放完毕的情况  //这个不能要否则不能实现切换播放模式等功能
        if(player_music->duration() == postion && postion != 0)
        {

            qDebug()<<"当前歌已经播放完了"<<endl;
            //on_pb_nextsong_clicked();   //自动播放下一首
            //changePlayStyle(playModel);
            if(playModel == 0)
            {

                qDebug()<<"当前歌是："<<curr_song_Index<<endl;
                curr_song_Index++;
                qDebug()<<"playmodel是："<<playModel<<endl;
                qDebug()<<"下一首是："<<curr_song_Index<<endl;

                ui->label_MusicName->setText(MusicName_list[(curr_song_Index)%song_nums]);
                qDebug()<<MusicName_list[(curr_song_Index)%song_nums]<<endl;
                change_music(curr_song_Index);
            }

            if(playModel == 1)
            {

                qDebug()<<"下一首是："<<curr_song_Index<<endl;
                qDebug()<<"playmodel是："<<playModel<<endl;
//                ui->label_MusicName->setText(MusicName_list[(curr_song_Index)%song_nums]);
//                qDebug()<<MusicName_list[(curr_song_Index)%song_nums]<<endl;
                change_music(curr_song_Index);
            }

            if(playModel == 2)
            {

                //qDebug()<<"下一首是："<<curr_song_Index<<endl;
                qDebug()<<"playmodel是："<<playModel<<endl;


                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // 使用当前时间的时间戳作为种子
                std::this_thread::sleep_for(std::chrono::seconds(1)); // 延迟 1 秒

                std::mt19937 gen(seed); // 为随机数引擎设置种子，使用不同的种子生成不同的随机数序列
                std::uniform_int_distribution<> dis(0, 100); // 创建一个范围在 0 到 100 的均匀整数分布器

                int randomNumber = dis(gen); // 生成随机数
//                ui->label_MusicName->setText(MusicName_list[(curr_song_Index)%song_nums]);
//                qDebug()<<MusicName_list[(curr_song_Index)%song_nums]<<endl;


                std::cout << "random: " << randomNumber << std::endl;
                curr_song_Index = randomNumber%song_nums;
                qDebug()<<"下一首是："<<curr_song_Index<<endl;
                change_music(curr_song_Index);
            }


        }



    });

    //拖动进度条的响应
    connect(ui->jindutiao,&QSlider::sliderMoved,[=](int postion){
        player_music->setPosition(postion);

    });


    //设置进度条最大值
    connect(player_music,&QMediaPlayer::durationChanged,[=](qint64 duration){
        ui->jindutiao->setMaximum(int(duration));
        int secs = int(duration)/1000;
        int min = secs/60; //取整
        secs = secs%60; //剩余秒
        ui->label_end->setText(QString::asprintf("%d:%d",min,secs));
    });
}

//音量改变
void player::volume_change(int volume)
{
    m_volume = volume;
    player_music->setVolume(m_volume);
    ui->label_yinliang->setText(QString("%0").arg(m_volume));
}

void player::init_all()
{


    //设置音量条初始化
    ui->label_yinliang->setText(QString("%0").arg(m_volume));
    ui->hs_yinliang->setMaximum(100);
    ui->hs_yinliang->setValue(m_volume);

    is_pause = false;

    //初始化播放器和播放列表
    init_bofangqi();

    //设置一个定时器，时刻监控C_curr变量
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(listen_C_curr()));
    m_pTimer->start(TIMER_TIMEOUT);

    //设置一个定时器或者按钮，选择更新后，从新搜索音乐进列表
    //...

    //进度条和时间戳
    jindutiao();

    //音量
    connect(ui->hs_yinliang,&QSlider::sliderMoved,[=](int volume){
        volume_change(volume);
    });
}

void player::on_pushButton_clicked()//播放模式，单曲循环，列表循环，随机播放
{

    qDebug()<<"当前playmodel是："<<playModel<<endl;
    playModel = (playModel+1)%3;
    if(playModel==0){

        ui->pushButton->setStyleSheet("border-image: url(:/res/circle.png);");
//        playModel=0;
        //changePlayStyle(playModel);
        //ui->pushButton_8->setIcon(QIcon("://circle.png"));

        //playModel=1;
        //return ;
    }
    //单曲循环
    else if(playModel==1){

        ui->pushButton->setStyleSheet("border-image: url(:/res/circle1.png);");
        //playModel=1;
        //changePlayStyle(playModel);
        // ui->pushButton_8->setIcon(QIcon("://circle1.png"))
        //playModel=2;
//        qDebug()<<"当前playmodel是："<<playModel<<endl;
        //return ;
    }
    //随机播放
    else {


        ui->pushButton->setStyleSheet("border-image: url(:/res/random.png);");
        //playModel=2;
        //changePlayStyle(playModel);
        //ui->pushButton_8->setIcon(QIcon("://assets/random.png"));
        //playModel=0;
        //return ;
    }
    //playModel = (playModel++)%3;
    //playModel++;
    qDebug()<<"当前playmodel是："<<playModel<<endl;
    return ;
}


//void player::changePlayStyle(int playModelStyle){
//    //列表循环
//    if(playModelStyle==0){
//        //playlist->setPlaybackMode(QMediaPlaylist::Loop);
//        if(player_music->position()==player_music->duration()&&player_music->position()!=0&&player_music->duration()!=0){

//            //ui->label_MusicName->setText(MusicName_list[(curr_song_Index++)%song_nums]);


//            curr_song_Index++;
//            change_music(curr_song_Index);

//            QString currentMediaName = QFileInfo(playlist->currentMedia().canonicalUrl().toLocalFile()).baseName();

//            ui->label_MusicName->setText(currentMediaName);

//            //qDebug()<<(curr_song_Index)%song_nums<<endl;
//            //change_music(curr_song_Index);

//            //player_music->play();

//        }
//        return;

//    }
//    //单曲循环
//    else if(playModelStyle==1){
//        // player_music->setPlaylist(playlist);
//        //playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

//        if(player_music->position()==player_music->duration()&&player_music->position()!=0&&player_music->duration()!=0){

//           QString currentMediaName = QFileInfo(playlist->currentMedia().canonicalUrl().toLocalFile()).baseName();

//            ui->label_MusicName->setText(currentMediaName);

//            qDebug()<<"currentMediaName"<<endl;

//              player_music->play();
//            //change_music(curr_song_Index);

//        }
//    }
//    //随机播放
//    else if(playModelStyle==2) {
//        //playlist->setPlaybackMode(QMediaPlaylist::Random);
//        if(player_music->position()==player_music->duration()&&player_music->position()!=0&&player_music->duration()!=0){

//            QString currentMediaName = QFileInfo(playlist->currentMedia().canonicalUrl().toLocalFile()).baseName();

//            ui->label_MusicName->setText(currentMediaName);

//            player_music->play();

//        }
//    }

//}

