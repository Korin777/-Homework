#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include<QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QtDebug>
#include <QPainter>
#include "chess.h"
#include <QVector>
#include <QPixmap>
#include <QPushButton>

namespace Ui {
class MainWindow;
class CScene;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    QLabel *mousepoint;
    bool mouse=false;
    int getcolumn(int x);
    int getrow(int y);
    short record;
    bool turn = true;
    QVector<Chess*> chess;
    bool settingmode = false;
    QLabel *setchess[14];
    QLabel *select;
    QLabel *massage;
    QLabel *move[90];
    short chesstype;
    short range;
    bool gameend =false;
    bool insert;
    bool hasset;

private:
    Ui::MainWindow *ui;
    QPushButton *set;
    QPushButton *start;
    QPushButton *restart;

    QPushButton *shuai;
    QPushButton *hongshi;
    QPushButton *hongxiang;
    QPushButton *hongma;
    QPushButton *hongju;
    QPushButton *hongpao;
    QPushButton *bing;
    QPushButton *jiang;
    QPushButton *heishi;
    QPushButton *heixiang;
    QPushButton *heima;
    QPushButton *heiju;
    QPushButton *heipao;
    QPushButton *zu;

private slots:
    void settingmodeclicked();
    void startgameclicked();
    void restartclicked();

protected:
    void paintEvent(QPaintEvent *e);


};



#endif // MAINWINDOW_H
