#ifndef SERCHMUSIC_H
#define SERCHMUSIC_H

#include <QWidget>

#include"serchresult.h"

namespace Ui {
class SerchMusic;
}

class SerchMusic : public QWidget
{
    Q_OBJECT

public:
    explicit SerchMusic(QWidget *parent = nullptr);
    ~SerchMusic();

private slots:
    void on_pb_serch_clicked();

private:
    Ui::SerchMusic *ui;

    SerchResult *sr;

    QString song_text;
};

#endif // SERCHMUSIC_H
