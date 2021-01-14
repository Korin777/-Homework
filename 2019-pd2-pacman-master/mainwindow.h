#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QLabel>


#include "movableitem.h"
#include "ghost.h"
#include "pacman.h"
#include "background.h"
#include "powerball.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QGraphicsScene *scene;

    QTimer *timer,*timer1,*timer2,*timer3,*timer4;
    int record = 0;
    int recordghost1 = 0;
    int recordghost2 = 0;
    int recordghost3 = 0;
    int recordghost4 = 0;
    bool ghoststop1 = false;
    bool ghoststop2 = false;
    bool ghoststop3 = false;
    bool ghoststop4 = false;
    QLabel *countscore;
    QLabel *sup;
    int score = 0;

    QPixmap gameoverpix;
    QGraphicsPixmapItem *gameover;

    Ghost *ghost;
    Ghost *ghost2;
    Ghost *ghost3;
    Ghost *ghost4;
    movableitem *ghostptr1;
    movableitem *ghostptr2;
    movableitem *ghostptr3;
    movableitem *ghostptr4;

    Background *background;

    QVector<QGraphicsPixmapItem*> ball;
    QVector<PowerBall*> powerball;

    Pacman *pacman;
    movableitem *pacmanptr;

private slots:
    void updater();
    void ghostupdater();
    void ghostupdater2();
    void ghostupdater3();
    void ghostupdater4();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
