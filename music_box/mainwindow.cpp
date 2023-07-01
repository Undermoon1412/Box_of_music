#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"player.h"


#include<QFileDialog>

//创建一个web服务器
//此web服务器用来接受金和发送表格的双击信息和播放器的上一首下一首信息


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //music_table = new downloadMusic;



}

MainWindow::~MainWindow()
{
    delete ui;
}




