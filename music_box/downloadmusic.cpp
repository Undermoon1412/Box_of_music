#include "downloadmusic.h"
#include "ui_downloadmusic.h"
#include<QTimer>
#include<QDir>

#include"player.h"
#include<QTableWidget>

#define COL_NUMS 1
//#define COL_NUMS 4


bool is_F5 = false;     //不需要刷新

enum
{
    titleCol,       //标题列
    artistCol,      //歌手列
    albumCol,       //专辑列
    durationCol     //时长列
};

downloadMusic::downloadMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadMusic)
{
    ui->setupUi(this);

    //初始化表格
    init_table();

    //读取文件夹里面的内容将其添加到列表中
    init_SongList();

    //player * p = new player;
    //双击列表触发槽函数
    //该信号会发送到palyer里面处理
    connect(ui->tableWidget,&QTableWidget::cellDoubleClicked,[&](int row,int col){
        C_curr_row = row;   //改变player.h 里面定义的一个全局变量
        qDebug()<<C_curr_row;
    });

    //设置一个定时器，时刻监控 is_F5 变量
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(listen_F5()));
    m_pTimer->start(TIMER_TIMEOUT);

}

downloadMusic::~downloadMusic()
{
    delete ui;
}

void downloadMusic::init_table()
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
}

//初始化表格
bool downloadMusic::init_SongList()
{
    //默认打开本地文件
    QDir dir("D:\\QT_file\\music\\music_box\\LocalMusic");      //默认打开此文件夹
    QStringList nameFileters;
    nameFileters<<"*.mp3";      //进行文件筛选


//    QStringList filer;
//    filer << "*.jpg";//设定需要的文件类型(*为所有类型)
//    QFileInfoList list = dir.entryInfoList(filer);
//    //QList<QFileInfo> *list= new QList<QFileInfo>(dir.entryInfoList(filter));


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

    //将本地文件内的mp3文件放入表格中 4.30弄
    QStringList files=dir.entryList(nameFileters,QDir::Files|QDir::Readable,QDir::Name);
    qDebug()<<files.size();   //输出文件名数
    ui->tableWidget->setRowCount(files.size());
    for (int row = 0; row < files.size(); row++)
    {
        ui->tableWidget->setItem(row, titleCol, createItem(files.at(row)));                         //添加歌手
        ui->tableWidget->setItem(row, artistCol, createItem(""));                 //添加歌手
        ui->tableWidget->setItem(row, albumCol, createItem(""));                   //添加专辑
        ui->tableWidget->setItem(row, durationCol, createItem("")); //添加时长
    }

    //设置一个定时器，每隔0秒后自动对齐一下表格宽度
    QTimer::singleShot(0, [=]{
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    });

    //以上只是将文件夹内的文件名添加到了表格中
    //需要将点选的文件播放
    return true;
}


void downloadMusic::listen_F5()
{
    if(is_F5)
    {
        //如果检测到F5变为真了，说明已经下载了一首音乐，需要更新列表\
        //此处不改变，在 player.cpp里面再监听一次
        init_SongList();
    }

}



