#include "serchmusic.h"
#include "ui_serchmusic.h"


SerchMusic::SerchMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerchMusic)
{
    ui->setupUi(this);


}

SerchMusic::~SerchMusic()
{
    delete ui;

    delete sr;
}




//搜索按钮槽
void SerchMusic::on_pb_serch_clicked()
{

    //拿到搜索框内容
    song_text = ui->le_SerchText->text();
    sr = new SerchResult(song_text);   //初始化搜索界面

    //显示窗口
    sr->show();

}

