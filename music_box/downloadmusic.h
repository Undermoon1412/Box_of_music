#ifndef DOWNLOADMUSIC_H
#define DOWNLOADMUSIC_H

#include <QWidget>
#include<QTimer>

extern bool is_F5;      //表明是否需要刷新？

namespace Ui {
class downloadMusic;
}

class downloadMusic : public QWidget
{
    Q_OBJECT

public:
    explicit downloadMusic(QWidget *parent = nullptr);
    ~downloadMusic();

    //初始化表格
    void init_table();

    //检索本地列表并添加到表格中
    bool init_SongList();

public slots:
    //void tbale_doubleclick(int row,int col);
    void listen_F5();


private:
    Ui::downloadMusic *ui;
    QTimer *m_pTimer;    //监控 is_F5

};

#endif // DOWNLOADMUSIC_H
