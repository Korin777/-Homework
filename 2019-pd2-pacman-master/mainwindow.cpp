#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPen>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(1760,700);
    scene->setSceneRect(0,0,1758,698);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    background = new Background();
    background->setPos(0,0);
    scene->addItem(background);
    sup = new QLabel(this);
    sup->setGeometry(0,0,300,100);
    sup->setFont(QFont("Arial",40));
    sup->setText("分數:");
    gameoverpix.load(":/img/gameover.png");
    countscore = new QLabel(this);
    countscore->setGeometry(160,0,300,100);
    countscore->setFont(QFont("Arial",40));
    countscore->setNum(score);
    QPen pen(Qt::black);
    scene->addRect(0,0,1758,698,pen);
    pen.setColor(Qt::blue);
    pen.setWidth(2);
{
//build the map
    QGraphicsLineItem *line1 = new QGraphicsLineItem(0,0,0,170);
    line1->setPos(140,100);
    line1->setPen(pen);
    scene->addItem(line1);
    QGraphicsLineItem *line2 = new QGraphicsLineItem(0,0,0,-170);
    line2->setPos(140,600);
    line2->setPen(pen);
    scene->addItem(line2);
    QGraphicsLineItem *line5 = new QGraphicsLineItem(0,0,0,170);
    line5->setPos(1620,100);
    line5->setPen(pen);
    scene->addItem(line5);
    QGraphicsLineItem *line6 = new QGraphicsLineItem(0,0,0,-170);
    line6->setPos(1620,600);
    line6->setPen(pen);
    scene->addItem(line6);

    QGraphicsLineItem *line3 = new QGraphicsLineItem(0,0,1480,0);
    line3->setPos(140,100);
    line3->setPen(pen);
    scene->addItem(line3);
    QGraphicsLineItem *line4 = new QGraphicsLineItem(0,0,520,0);
    line4->setPos(140,600);
    line4->setPen(pen);
    scene->addItem(line4);
    QGraphicsLineItem *line4x = new QGraphicsLineItem(0,0,360,0);
    line4x->setPos(710,600);
    line4x->setPen(pen);
    scene->addItem(line4x);
    QGraphicsLineItem *line4y = new QGraphicsLineItem(0,0,500,0);
    line4y->setPos(1120,600);
    line4y->setPen(pen);
    scene->addItem(line4y);

    QGraphicsLineItem *line7 = new QGraphicsLineItem(0,0,160,0);
    line7->setPos(140,270);
    line7->setPen(pen);
    scene->addItem(line7);
    QGraphicsLineItem *line8 = new QGraphicsLineItem(0,0,160,0);
    line8->setPos(140,320);
    line8->setPen(pen);
    scene->addItem(line8);
    QGraphicsLineItem *line9 = new QGraphicsLineItem(0,0,0,50);
    line9->setPos(300,270);
    line9->setPen(pen);
    scene->addItem(line9);
    QGraphicsLineItem *line10 = new QGraphicsLineItem(0,0,160,0);
    line10->setPos(140,380);
    line10->setPen(pen);
    scene->addItem(line10);
    QGraphicsLineItem *line11 = new QGraphicsLineItem(0,0,160,0);
    line11->setPos(140,430);
    line11->setPen(pen);
    scene->addItem(line11);
    QGraphicsLineItem *line12 = new QGraphicsLineItem(0,0,0,50);
    line12->setPos(300,380);
    line12->setPen(pen);
    scene->addItem(line12);

    QGraphicsLineItem *line13 = new QGraphicsLineItem(0,0,100,0);
    line13->setPos(200,160);
    line13->setPen(pen);
    scene->addItem(line13);
    QGraphicsLineItem *line14 = new QGraphicsLineItem(0,0,100,0);
    line14->setPos(200,210);
    line14->setPen(pen);
    scene->addItem(line14);
    QGraphicsLineItem *line15 = new QGraphicsLineItem(0,0,0,50);
    line15->setPos(200,160);
    line15->setPen(pen);
    scene->addItem(line15);
    QGraphicsLineItem *line16 = new QGraphicsLineItem(0,0,0,50);
    line16->setPos(300,160);
    line16->setPen(pen);
    scene->addItem(line16);

    QGraphicsLineItem *line17 = new QGraphicsLineItem(0,0,100,0);
    line17->setPos(200,490);
    line17->setPen(pen);
    scene->addItem(line17);
    QGraphicsLineItem *line18 = new QGraphicsLineItem(0,0,100,0);
    line18->setPos(200,540);
    line18->setPen(pen);
    scene->addItem(line18);
    QGraphicsLineItem *line19 = new QGraphicsLineItem(0,0,0,50);
    line19->setPos(200,490);
    line19->setPen(pen);
    scene->addItem(line19);
    QGraphicsLineItem *line20 = new QGraphicsLineItem(0,0,0,50);
    line20->setPos(300,490);
    line20->setPen(pen);
    scene->addItem(line20);


    QGraphicsLineItem *line21 = new QGraphicsLineItem(0,0,0,270);
    line21->setPos(360,160);
    line21->setPen(pen);
    scene->addItem(line21);
    QGraphicsLineItem *line22 = new QGraphicsLineItem(0,0,260,0);
    line22->setPos(360,160);
    line22->setPen(pen);
    scene->addItem(line22);
    QGraphicsLineItem *line23 = new QGraphicsLineItem(0,0,0,45);
    line23->setPos(620,160);
    line23->setPen(pen);
    scene->addItem(line23);
    QGraphicsLineItem *line24 = new QGraphicsLineItem(0,0,-200,0);
    line24->setPos(620,205);
    line24->setPen(pen);
    scene->addItem(line24);
    QGraphicsLineItem *line25 = new QGraphicsLineItem(0,0,0,180);
    line25->setPos(420,205);
    line25->setPen(pen);
    scene->addItem(line25);
    QGraphicsLineItem *line26 = new QGraphicsLineItem(0,0,140,0);
    line26->setPos(420,385);
    line26->setPen(pen);
    scene->addItem(line26);
    QGraphicsLineItem *line27 = new QGraphicsLineItem(0,0,0,-60);
    line27->setPos(560,385);
    line27->setPen(pen);
    scene->addItem(line27);
    QGraphicsLineItem *line28 = new QGraphicsLineItem(0,0,-80,0);
    line28->setPos(560,325);
    line28->setPen(pen);
    scene->addItem(line28);
    QGraphicsLineItem *line29 = new QGraphicsLineItem(0,0,0,-60);
    line29->setPos(480,325);
    line29->setPen(pen);
    scene->addItem(line29);
    QGraphicsLineItem *line30 = new QGraphicsLineItem(0,0,140,0);
    line30->setPos(480,265);
    line30->setPen(pen);
    scene->addItem(line30);
    QGraphicsLineItem *line31 = new QGraphicsLineItem(0,0,0,165);
    line31->setPos(620,265);
    line31->setPen(pen);
    scene->addItem(line31);
    QGraphicsLineItem *line32 = new QGraphicsLineItem(0,0,-260,0);
    line32->setPos(620,430);
    line32->setPen(pen);
    scene->addItem(line32);

    QGraphicsLineItem *line33 = new QGraphicsLineItem(0,0,240,0);
    line33->setPos(360,490);
    line33->setPen(pen);
    scene->addItem(line33);
    QGraphicsLineItem *line34 = new QGraphicsLineItem(0,0,0,50);
    line34->setPos(600,490);
    line34->setPen(pen);
    scene->addItem(line34);
    QGraphicsLineItem *line35 = new QGraphicsLineItem(0,0,-240,0);
    line35->setPos(600,540);
    line35->setPen(pen);
    scene->addItem(line35);
    QGraphicsLineItem *line36 = new QGraphicsLineItem(0,0,0,-50);
    line36->setPos(360,540);
    line36->setPen(pen);
    scene->addItem(line36);

    QGraphicsLineItem *line37 = new QGraphicsLineItem(0,0,520,0);
    line37->setPos(680,160);
    line37->setPen(pen);
    scene->addItem(line37);
    QGraphicsLineItem *line38 = new QGraphicsLineItem(0,0,0,50);
    line38->setPos(1200,160);
    line38->setPen(pen);
    scene->addItem(line38);
    QGraphicsLineItem *line39 = new QGraphicsLineItem(0,0,-520,0);
    line39->setPos(1200,210);
    line39->setPen(pen);
    scene->addItem(line39);
    QGraphicsLineItem *line40 = new QGraphicsLineItem(0,0,0,-50);
    line40->setPos(680,210);
    line40->setPen(pen);
    scene->addItem(line40);

    QGraphicsLineItem *line41 = new QGraphicsLineItem(0,0,175,0);
    line41->setPos(680,270);
    line41->setPen(pen);
    scene->addItem(line41);
    QGraphicsLineItem *line42 = new QGraphicsLineItem(0,0,0,160);
    line42->setPos(855,270);
    line42->setPen(pen);
    scene->addItem(line42);
    QGraphicsLineItem *line43 = new QGraphicsLineItem(0,0,-175,0);
    line43->setPos(855,430);
    line43->setPen(pen);
    scene->addItem(line43);
    QGraphicsLineItem *line44 = new QGraphicsLineItem(0,0,0,-160);
    line44->setPos(680,430);
    line44->setPen(pen);
    scene->addItem(line44);

    QGraphicsLineItem *line45 = new QGraphicsLineItem(0,0,285,0);
    line45->setPos(915,270);
    line45->setPen(pen);
    scene->addItem(line45);
    QGraphicsLineItem *line46 = new QGraphicsLineItem(0,0,0,160);
    line46->setPos(1200,270);
    line46->setPen(pen);
    scene->addItem(line46);
    QGraphicsLineItem *line47 = new QGraphicsLineItem(0,0,-285,0);
    line47->setPos(1200,430);
    line47->setPen(pen);
    scene->addItem(line47);
    QGraphicsLineItem *line48 = new QGraphicsLineItem(0,0,0,-160);
    line48->setPos(915,430);
    line48->setPen(pen);
    scene->addItem(line48);

    QGraphicsLineItem *line49 = new QGraphicsLineItem(0,0,240,0);
    line49->setPos(770,490);
    line49->setPen(pen);
    scene->addItem(line49);
    QGraphicsLineItem *line50 = new QGraphicsLineItem(0,0,0,50);
    line50->setPos(1010,490);
    line50->setPen(pen);
    scene->addItem(line50);
    QGraphicsLineItem *line51 = new QGraphicsLineItem(0,0,-240,0);
    line51->setPos(1010,540);
    line51->setPen(pen);
    scene->addItem(line51);
    QGraphicsLineItem *line52 = new QGraphicsLineItem(0,0,0,-50);
    line52->setPos(770,540);
    line52->setPen(pen);
    scene->addItem(line52);

    QGraphicsLineItem *line53 = new QGraphicsLineItem(0,0,240,0);
    line53->setPos(1180,490);
    line53->setPen(pen);
    scene->addItem(line53);
    QGraphicsLineItem *line54 = new QGraphicsLineItem(0,0,0,50);
    line54->setPos(1420,490);
    line54->setPen(pen);
    scene->addItem(line54);
    QGraphicsLineItem *line55 = new QGraphicsLineItem(0,0,-240,0);
    line55->setPos(1420,540);
    line55->setPen(pen);
    scene->addItem(line55);
    QGraphicsLineItem *line56 = new QGraphicsLineItem(0,0,0,-50);
    line56->setPos(1180,540);
    line56->setPen(pen);
    scene->addItem(line56);

    QGraphicsLineItem *line57 = new QGraphicsLineItem(0,0,0,-110);
    line57->setPos(660,600);
    line57->setPen(pen);
    scene->addItem(line57);
    QGraphicsLineItem *line58 = new QGraphicsLineItem(0,0,50,0);
    line58->setPos(660,490);
    line58->setPen(pen);
    scene->addItem(line58);
    QGraphicsLineItem *line59 = new QGraphicsLineItem(0,0,0,110);
    line59->setPos(710,490);
    line59->setPen(pen);
    scene->addItem(line59);
    QGraphicsLineItem *line60 = new QGraphicsLineItem(0,0,0,-110);
    line60->setPos(1070,600);
    line60->setPen(pen);
    scene->addItem(line60);
    QGraphicsLineItem *line61 = new QGraphicsLineItem(0,0,50,0);
    line61->setPos(1070,490);
    line61->setPen(pen);
    scene->addItem(line61);
    QGraphicsLineItem *line62 = new QGraphicsLineItem(0,0,0,110);
    line62->setPos(1120,490);
    line62->setPen(pen);
    scene->addItem(line62);

    QGraphicsLineItem *line63 = new QGraphicsLineItem(0,0,80,0);
    line63->setPos(1480,490);
    line63->setPen(pen);
    scene->addItem(line63);
    QGraphicsLineItem *line64 = new QGraphicsLineItem(0,0,0,50);
    line64->setPos(1560,490);
    line64->setPen(pen);
    scene->addItem(line64);
    QGraphicsLineItem *line65 = new QGraphicsLineItem(0,0,-80,0);
    line65->setPos(1560,540);
    line65->setPen(pen);
    scene->addItem(line65);
    QGraphicsLineItem *line66 = new QGraphicsLineItem(0,0,0,-50);
    line66->setPos(1480,540);
    line66->setPen(pen);
    scene->addItem(line66);

    QGraphicsLineItem *line67 = new QGraphicsLineItem(0,0,200,0);
    line67->setPos(1260,160);
    line67->setPen(pen);
    scene->addItem(line67);
    QGraphicsLineItem *line68 = new QGraphicsLineItem(0,0,0,270);
    line68->setPos(1260,160);
    line68->setPen(pen);
    scene->addItem(line68);
    QGraphicsLineItem *line69 = new QGraphicsLineItem(0,0,-200,0);
    line69->setPos(1460,430);
    line69->setPen(pen);
    scene->addItem(line69);
    QGraphicsLineItem *line70 = new QGraphicsLineItem(0,0,0,-270);
    line70->setPos(1460,430);
    line70->setPen(pen);
    scene->addItem(line70);

    QGraphicsLineItem *line71 = new QGraphicsLineItem(0,0,40,0);
    line71->setPos(1520,160);
    line71->setPen(pen);
    scene->addItem(line71);
    QGraphicsLineItem *line72 = new QGraphicsLineItem(0,0,0,50);
    line72->setPos(1520,160);
    line72->setPen(pen);
    scene->addItem(line72);
    QGraphicsLineItem *line73 = new QGraphicsLineItem(0,0,-40,0);
    line73->setPos(1560,210);
    line73->setPen(pen);
    scene->addItem(line73);
    QGraphicsLineItem *line74 = new QGraphicsLineItem(0,0,0,-50);
    line74->setPos(1560,210);
    line74->setPen(pen);
    scene->addItem(line74);

    QGraphicsLineItem *line75 = new QGraphicsLineItem(0,0,-100,0);
    line75->setPos(1620,270);
    line75->setPen(pen);
    scene->addItem(line75);
    QGraphicsLineItem *line76 = new QGraphicsLineItem(0,0,0,50);
    line76->setPos(1520,270);
    line76->setPen(pen);
    scene->addItem(line76);
    QGraphicsLineItem *line77 = new QGraphicsLineItem(0,0,100,0);
    line77->setPos(1520,320);
    line77->setPen(pen);
    scene->addItem(line77);
    QGraphicsLineItem *line78 = new QGraphicsLineItem(0,0,-100,0);
    line78->setPos(1620,380);
    line78->setPen(pen);
    scene->addItem(line78);
    QGraphicsLineItem *line79 = new QGraphicsLineItem(0,0,0,50);
    line79->setPos(1520,380);
    line79->setPen(pen);
    scene->addItem(line79);
    QGraphicsLineItem *line80 = new QGraphicsLineItem(0,0,100,0);
    line80->setPos(1520,430);
    line80->setPen(pen);
    scene->addItem(line80);
}

    pacman = new Pacman();
    pacmanptr = new movableitem();
    pacmanptr = pacman;
    //點點
    scene->addItem(pacman);
{
    QPixmap dot;
    dot.load(":/img/dot.png");
    for(int i=0;i<34;++i)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(200+40*i,120);
    }
    for(int i=0;i<12;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(320,120+40*i);
    }
    for(int i=0;i<3;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(160,160+40*i);
    }
    for(int i=0;i<3;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(160,450+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1580,160+40*i);
    }
    for(int i=0;i<3;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(440,270+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(480+40*i,350);
    }
    for(int i=0;i<3;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1580,450+40*i);
    }
    for(int i=0;i<3;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(200+40*i,240);
    }
    for(int i=0;i<3;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(200+40*i,450);
    }
    for(int i=0;i<12;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(360+40*i,450);
    }
    for(int i=0;i<16;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(940+40*i,450);
    }
    for(int i=0;i<3;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(200+40*i,560);
    }
    for(int i=0;i<7;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(360+40*i,560);
    }
    for(int i=0;i<8;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(740+40*i,560);
    }
    for(int i=0;i<11;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1140+40*i,560);
    }
    for(int i=0;i<19;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(440+40*i,230);
    }
    for(int i=0;i<7;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1220,170+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(640,150+40*i);
    }
    for(int i=0;i<4;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(640,280+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(620,490+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(730,490+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1030,490+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1140,490+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1440,490+40*i);
    }
    for(int i=0;i<7;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1480,170+40*i);
    }
    for(int i=0;i<2;i++)
    {
        ball.insert(i,new QGraphicsPixmapItem());
        ball[i]->setPixmap(dot.scaled(20,20,Qt::KeepAspectRatio));
        scene->addItem(ball[i]);
        ball[i]->setPos(1520+40*i,230);
    }
}

    powerball.insert(0,new PowerBall());
    scene->addItem(powerball[0]);
    powerball[0]->setPos(150,110);
    powerball.insert(1,new PowerBall());
    scene->addItem(powerball[1]);
    powerball[1]->setPos(150,550);
    powerball.insert(2,new PowerBall());
    scene->addItem(powerball[2]);
    powerball[2]->setPos(1570,110);
    powerball.insert(3,new PowerBall());
    scene->addItem(powerball[3]);
    powerball[3]->setPos(1570,550);

    ghost = new Ghost();
    scene->addItem(ghost);
    ghost->ghostleft.load(":/img/ghostleft1.png");
    ghost->ghostright.load(":/img/ghostright1.png");
    ghost->ghostup.load(":/img/ghostup1.png");
    ghost->ghostdown.load(":/img/ghostdown1.png");
    ghost->ghostafraid.load(":/img/ghostafraid.png");
    ghost->setPos(1560,540);
    ghost2 = new Ghost();
    scene->addItem(ghost2);
    ghost2->ghostleft.load(":/img/ghostleft2.png");
    ghost2->ghostright.load(":/img/ghostright2.png");
    ghost2->ghostup.load(":/img/ghostup2.png");
    ghost2->ghostdown.load(":/img/ghostdown2.png");
    ghost2->ghostafraid.load(":/img/ghostafraid.png");
    ghost2->setPos(1560,100);
    ghost3 = new Ghost();
    scene->addItem(ghost3);
    ghost3->ghostleft.load(":/img/ghostleft3.png");
    ghost3->ghostright.load(":/img/ghostright3.png");
    ghost3->ghostup.load(":/img/ghostup3.png");
    ghost3->ghostdown.load(":/img/ghostdown3.png");
    ghost3->ghostafraid.load(":/img/ghostafraid.png");
    ghost3->setPos(140,540);
    ghost4 = new Ghost();
    scene->addItem(ghost4);
    ghost4->ghostleft.load(":/img/ghostleft4.png");
    ghost4->ghostright.load(":/img/ghostright4.png");
    ghost4->ghostup.load(":/img/ghostup4.png");
    ghost4->ghostdown.load(":/img/ghostdown4.png");
    ghost4->ghostafraid.load(":/img/ghostafraid.png");
    ghost4->setPos(140,100);

    ghostptr1 = new movableitem();
    ghostptr1 = ghost;
    ghostptr2 = new movableitem();
    ghostptr2 = ghost2;
    ghostptr3 = new movableitem();
    ghostptr3 = ghost3;
    ghostptr4 = new movableitem();
    ghostptr4 = ghost4;

    gameover = new QGraphicsPixmapItem;

    timer = new QTimer(this);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);
    timer4 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(ghostupdater()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(ghostupdater2()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(ghostupdater3()));
    connect(timer4,SIGNAL(timeout()),this,SLOT(ghostupdater4()));
    connect(timer,SIGNAL(timeout()),this,SLOT(updater()));
    timer->start(50);
    timer1->start(50);
    timer2->start(50);
    timer3->start(50);
    timer4->start(50);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updater()
{
    if(ball.size()==0&&powerball.size()==0)
    {
        timer->stop();
        timer1->stop();
        timer2->stop();
        timer3->stop();
        timer4->stop();
        return;
    }
    if(ghoststop1)
    {
        recordghost1++;
    }
    if(recordghost1>150)
    {
        recordghost1 = 0;
        ghost->setPos(1560,540);
        ghost->beeaten = false;
        ghoststop1 = false;
        ghost->Ghostafraid = false;
        timer1->start(50);
    }
    if(ghoststop2)
    {
        recordghost2++;
    }
    if(recordghost2>150)
    {
        recordghost2 = 0;
        ghost2->setPos(1560,100);
        ghost2->beeaten = false;
        ghost2->Ghostafraid = false;
        ghoststop2 = false;
        timer2->start(50);
    }
    if(ghoststop3)
    {
        recordghost3++;
    }
    if(recordghost3>150)
    {
        recordghost3 = 0;
        ghost3->setPos(140,540);
        ghost3->beeaten = false;
        ghoststop3 = false;
        ghost3->Ghostafraid = false;
        timer3->start(50);
    }
    if(ghoststop4)
    {
        recordghost4++;
    }
    if(recordghost4>150)
    {
        recordghost4 = 0;
        ghost4->setPos(140,100);
        ghost4->beeaten = false;
        ghost4->Ghostafraid = false;
        ghoststop4 = false;
        timer4->start(50);
    }

    if(record>500)
    {
        record = 0;
        pacman->eatghost = false;
        ghost->Ghostafraid = false;
        ghost2->Ghostafraid = false;
        ghost3->Ghostafraid = false;
        ghost4->Ghostafraid = false;
    }
    if(pacman->eatghost)
    {
        record++;
    }
    for(int i=0;i<ball.size();++i)
    {
        if(ball[i]->collidesWithItem(pacman,Qt::ContainsItemShape))
        {
            delete ball[i];
            ball.remove(i);
            score = score + 10;
            countscore->setNum(score);
        }
    }
    for(int i=0;i<powerball.size();++i)
    {
        if(powerball[i]->collidesWithItem(pacman,Qt::ContainsItemShape))
        {
            record = 0;
            delete powerball[i];
            powerball.remove(i);
            pacman->eatghost = true;
            ghost->Ghostafraid = true;
            ghost2->Ghostafraid = true;
            ghost3->Ghostafraid = true;
            ghost4->Ghostafraid = true;
        }
    }
    pacmanptr->move();
    if((pacman->collidesWithItem(ghost,Qt::ContainsItemShape)||pacman->collidesWithItem(ghost2,Qt::ContainsItemShape)||pacman->collidesWithItem(ghost3,Qt::ContainsItemShape)||pacman->collidesWithItem(ghost4,Qt::ContainsItemShape))&&!pacman->eatghost)
    {
        gameover->setPos(730,250);
        gameover->setPixmap(gameoverpix.scaled(200,200,Qt::KeepAspectRatio));
        scene->addItem(gameover);
        timer->stop();
        timer1->stop();
        timer2->stop();
        timer3->stop();
        timer4->stop();
        return;
    }
}
void MainWindow::ghostupdater()
{
    if(ghost->collidesWithItem(pacman,Qt::IntersectsItemShape)&&pacman->eatghost)
    {
        score = score + 50;
        timer1->stop();
        ghoststop1 = true;
        ghost->setPos(0,0);
        ghost->beeaten = true;
    }
    ghost->restrict();
    if(ghost->collidesWithItem(ghost2,Qt::IntersectsItemShape))
    {
        ghost->speedx = - ghost->speedx;
        ghost->speedy = - ghost->speedy;
        if(ghost->left)
        {
            ghost->left = false;
            ghost->right = true;
        }
        else if(ghost->right)
        {
            ghost->left = true;
            ghost->right = false;
        }
        if(ghost->up)
        {
            ghost->up = false;
            ghost->down = true;
        }
        else if(ghost->down)
        {
            ghost->up = true;
            ghost->down = false;
        }
    }
    if(ghost->collidesWithItem(ghost3,Qt::IntersectsItemShape))
    {
        ghost->speedx = - ghost->speedx;
        ghost->speedy = - ghost->speedy;
        if(ghost->left)
        {
            ghost->left = false;
            ghost->right = true;
        }
        else if(ghost->right)
        {
            ghost->left = true;
            ghost->right = false;
        }
        if(ghost->up)
        {
            ghost->up = false;
            ghost->down = true;
        }
        else if(ghost->down)
        {
            ghost->up = true;
            ghost->down = false;
        }
    }
    if(ghost->collidesWithItem(ghost4,Qt::IntersectsItemShape))
    {
        ghost->speedx = - ghost->speedx;
        ghost->speedy = - ghost->speedy;
        if(ghost->left)
        {
            ghost->left = false;
            ghost->right = true;
        }
        else if(ghost->right)
        {
            ghost->left = true;
            ghost->right = false;
        }
        if(ghost->up)
        {
            ghost->up = false;
            ghost->down = true;
        }
        else if(ghost->down)
        {
            ghost->up = true;
            ghost->down = false;
        }
    }
    //if(change){
    if(ghost->decide())
    {
        ghost->moveleft = true;
        ghost->moveright = true;
        ghost->moveup = true;
        ghost->movedown = true;
        ghost->left = true;
        ghost->right = true;
        ghost->up = true;
        ghost->down = true;
        ghost->restrict();
        qreal absx,absy;
        absx = ghost->x()-pacman->x();
        absy = ghost->y()-pacman->y();
        {
        if(absx<0)
            absx = -absx;
        if(absy<0)
            absy = -absy;
        }
    if(absx>absy){
    if(ghost->x()>pacman->x())
    {
        if(ghost->moveleft)
        {

            ghost->right = false;
            ghost->up = false;
            ghost->down = false;
            ghost->speedx = -5;
            ghost->speedy = 0;
        }
        else if(ghost->moveup)
        {
            ghost->right = false;
            ghost->left = false;
            ghost->down = false;
            ghost->speedx = 0;
            ghost->speedy = -5;
        }
        else if(ghost->movedown)
        {
            ghost->right = false;
            ghost->left = false;
            ghost->up = false;
            ghost->speedx = 0;
            ghost->speedy = 5;
        }
        else if(ghost->moveright)
        {
            ghost->up = false;
            ghost->left = false;
            ghost->down = false;
            ghost->speedx = 5;
            ghost->speedy = 0;
        }
    }
    else if(ghost->x()<pacman->x())
    {
        if(ghost->moveright)
        {
            ghost->up = false;
            ghost->left = false;
            ghost->down = false;
            ghost->speedx = 5;
            ghost->speedy = 0;
        }
        else if(ghost->moveup)
        {
            ghost->right = false;
            ghost->left = false;
            ghost->down = false;
            ghost->speedx = 0;
            ghost->speedy = -5;
        }
        else if(ghost->movedown)
        {
            ghost->right = false;
            ghost->left = false;
            ghost->up = false;
            ghost->speedx = 0;
            ghost->speedy = 5;
        }
        else if(ghost->moveleft)
        {

            ghost->right = false;
            ghost->up = false;
            ghost->down = false;
            ghost->speedx = -5;
            ghost->speedy = 0;
        }
    }
        else if(ghost->y()>pacman->y())
        {
            if(ghost->moveup)
            {
                ghost->right = false;
                ghost->left = false;
                ghost->down = false;
                ghost->speedx = 0;
                ghost->speedy = -5;
            }
            else if(ghost->moveright)
            {
                ghost->up = false;
                ghost->left = false;
                ghost->down = false;
                ghost->speedx = 5;
                ghost->speedy = 0;
            }
            else if(ghost->moveleft)
            {

                ghost->right = false;
                ghost->up = false;
                ghost->down = false;
                ghost->speedx = -5;
                ghost->speedy = 0;
            }
            else if(ghost->movedown)
            {
                ghost->right = false;
                ghost->left = false;
                ghost->up = false;
                ghost->speedx = 0;
                ghost->speedy = 5;
            }
        }
        else if(ghost->y()<pacman->y())
        {
            if(ghost->movedown)
            {
                ghost->right = false;
                ghost->left = false;
                ghost->up = false;
                ghost->speedx = 0;
                ghost->speedy = 5;
            }
            else if(ghost->moveright)
            {
                ghost->up = false;
                ghost->left = false;
                ghost->down = false;
                ghost->speedx = 5;
                ghost->speedy = 0;
            }
            else if(ghost->moveleft)
            {

                ghost->right = false;
                ghost->up = false;
                ghost->down = false;
                ghost->speedx = -5;
                ghost->speedy = 0;
            }
            else if(ghost->moveup)
            {
                ghost->right = false;
                ghost->left = false;
                ghost->down = false;
                ghost->speedx = 0;
                ghost->speedy = -5;
            }
        }
    }
    else
    {
        if(ghost->y()>pacman->y())
        {
            if(ghost->moveup)
            {
                ghost->right = false;
                ghost->left = false;
                ghost->down = false;
                ghost->speedx = 0;
                ghost->speedy = -5;
            }
            else if(ghost->moveright)
            {
                ghost->up = false;
                ghost->left = false;
                ghost->down = false;
                ghost->speedx = 5;
                ghost->speedy = 0;
            }
            else if(ghost->moveleft)
            {

                ghost->right = false;
                ghost->up = false;
                ghost->down = false;
                ghost->speedx = -5;
                ghost->speedy = 0;
            }
            else if(ghost->movedown)
            {
                ghost->right = false;
                ghost->left = false;
                ghost->up = false;
                ghost->speedx = 0;
                ghost->speedy = 5;
            }
        }
        else if(ghost->y()<pacman->y())
        {
            if(ghost->movedown)
            {
                ghost->right = false;
                ghost->left = false;
                ghost->up = false;
                ghost->speedx = 0;
                ghost->speedy = 5;
            }
            else if(ghost->moveright)
            {
                ghost->up = false;
                ghost->left = false;
                ghost->down = false;
                ghost->speedx = 5;
                ghost->speedy = 0;
            }
            else if(ghost->moveleft)
            {

                ghost->right = false;
                ghost->up = false;
                ghost->down = false;
                ghost->speedx = -5;
                ghost->speedy = 0;
            }
            else if(ghost->moveup)
            {
                ghost->right = false;
                ghost->left = false;
                ghost->down = false;
                ghost->speedx = 0;
                ghost->speedy = -5;
            }
        }
        else if(ghost->x()>pacman->x())
        {
        if(ghost->moveleft)
        {

            ghost->right = false;
            ghost->up = false;
            ghost->down = false;
            ghost->speedx = -5;
            ghost->speedy = 0;
        }
        else if(ghost->moveup)
        {
            ghost->right = false;
            ghost->left = false;
            ghost->down = false;
            ghost->speedx = 0;
            ghost->speedy = -5;
        }
        else if(ghost->movedown)
        {
            ghost->right = false;
            ghost->left = false;
            ghost->up = false;
            ghost->speedx = 0;
            ghost->speedy = 5;
        }
        else if(ghost->moveright)
        {
            ghost->up = false;
            ghost->left = false;
            ghost->down = false;
            ghost->speedx = 5;
            ghost->speedy = 0;
        }
    }
    else if(ghost->x()<pacman->x())
    {
        if(ghost->moveright)
        {
            ghost->up = false;
            ghost->left = false;
            ghost->down = false;
            ghost->speedx = 5;
            ghost->speedy = 0;
        }
        else if(ghost->moveup)
        {
            ghost->right = false;
            ghost->left = false;
            ghost->down = false;
            ghost->speedx = 0;
            ghost->speedy = -5;
        }
        else if(ghost->movedown)
        {
            ghost->right = false;
            ghost->left = false;
            ghost->up = false;
            ghost->speedx = 0;
            ghost->speedy = 5;
        }
        else if(ghost->moveleft)
        {

            ghost->right = false;
            ghost->up = false;
            ghost->down = false;
            ghost->speedx = -5;
            ghost->speedy = 0;
        }
    }
    }
    }
    ghostptr1->move();
}

void MainWindow::ghostupdater2()
{
    if(ghost2->collidesWithItem(pacman,Qt::IntersectsItemShape)&&pacman->eatghost)
    {
        score = score + 50;
        timer2->stop();
        ghoststop2 = true;
        ghost2->setPos(0,0);
        ghost2->beeaten = true;
    }
    ghost2->restrict();
    if(ghost2->collidesWithItem(ghost,Qt::IntersectsItemShape))
    {
        ghost2->speedx = - ghost2->speedx;
        ghost2->speedy = - ghost2->speedy;
        if(ghost2->left)
        {
            ghost2->left = false;
            ghost2->right = true;
        }
        else if(ghost2->right)
        {
            ghost2->left = true;
            ghost2->right = false;
        }
        if(ghost2->up)
        {
            ghost2->up = false;
            ghost2->down = true;
        }
        else if(ghost2->down)
        {
            ghost2->up = true;
            ghost2->down = false;
        }
    }
    if(ghost2->collidesWithItem(ghost3,Qt::IntersectsItemShape))
    {
        ghost2->speedx = - ghost2->speedx;
        ghost2->speedy = - ghost2->speedy;
        if(ghost2->left)
        {
            ghost2->left = false;
            ghost2->right = true;
        }
        else if(ghost2->right)
        {
            ghost2->left = true;
            ghost2->right = false;
        }
        if(ghost2->up)
        {
            ghost2->up = false;
            ghost2->down = true;
        }
        else if(ghost2->down)
        {
            ghost2->up = true;
            ghost2->down = false;
        }
    }
    if(ghost2->collidesWithItem(ghost4,Qt::IntersectsItemShape))
    {
        ghost2->speedx = - ghost2->speedx;
        ghost2->speedy = - ghost2->speedy;
        if(ghost2->left)
        {
            ghost2->left = false;
            ghost2->right = true;
        }
        else if(ghost2->right)
        {
            ghost2->left = true;
            ghost2->right = false;
        }
        if(ghost2->up)
        {
            ghost2->up = false;
            ghost2->down = true;
        }
        else if(ghost2->down)
        {
            ghost2->up = true;
            ghost2->down = false;
        }
    }
    if(ghost2->decide())
    {
        ghost2->moveleft = true;
        ghost2->moveright = true;
        ghost2->moveup = true;
        ghost2->movedown = true;
        ghost2->left = true;
        ghost2->right = true;
        ghost2->up = true;
        ghost2->down = true;
        ghost2->restrict();
        qreal absx,absy;
        absx = ghost2->x()-pacman->x();
        absy = ghost2->y()-pacman->y();
        {
        if(absx<0)
            absx = -absx;
        if(absy<0)
            absy = -absy;
        }
    if(absx>absy){
    if(ghost2->x()>pacman->x()-320)
    {
        if(ghost2->moveleft)
        {

            ghost2->right = false;
            ghost2->up = false;
            ghost2->down = false;
            ghost2->speedx = -5;
            ghost2->speedy = 0;
        }
        else if(ghost2->moveup)
        {
            ghost2->right = false;
            ghost2->left = false;
            ghost2->down = false;
            ghost2->speedx = 0;
            ghost2->speedy = -5;
        }
        else if(ghost2->movedown)
        {
            ghost2->right = false;
            ghost2->left = false;
            ghost2->up = false;
            ghost2->speedx = 0;
            ghost2->speedy = 5;
        }
        else if(ghost2->moveright)
        {
            ghost2->up = false;
            ghost2->left = false;
            ghost2->down = false;
            ghost2->speedx = 5;
            ghost2->speedy = 0;
        }
    }
    else if(ghost2->x()<pacman->x()-320)
    {
        if(ghost2->moveright)
        {
            ghost2->up = false;
            ghost2->left = false;
            ghost2->down = false;
            ghost2->speedx = 5;
            ghost2->speedy = 0;
        }
        else if(ghost2->moveup)
        {
            ghost2->right = false;
            ghost2->left = false;
            ghost2->down = false;
            ghost2->speedx = 0;
            ghost2->speedy = -5;
        }
        else if(ghost2->movedown)
        {
            ghost2->right = false;
            ghost2->left = false;
            ghost2->up = false;
            ghost2->speedx = 0;
            ghost2->speedy = 5;
        }
        else if(ghost2->moveleft)
        {

            ghost2->right = false;
            ghost2->up = false;
            ghost2->down = false;
            ghost2->speedx = -5;
            ghost2->speedy = 0;
        }
    }
        else if(ghost2->y()>pacman->y()-160)
        {
            if(ghost2->moveup)
            {
                ghost2->right = false;
                ghost2->left = false;
                ghost2->down = false;
                ghost2->speedx = 0;
                ghost2->speedy = -5;
            }
            else if(ghost2->moveright)
            {
                ghost2->up = false;
                ghost2->left = false;
                ghost2->down = false;
                ghost2->speedx = 5;
                ghost2->speedy = 0;
            }
            else if(ghost2->moveleft)
            {

                ghost2->right = false;
                ghost2->up = false;
                ghost2->down = false;
                ghost2->speedx = -5;
                ghost2->speedy = 0;
            }
            else if(ghost2->movedown)
            {
                ghost2->right = false;
                ghost2->left = false;
                ghost2->up = false;
                ghost2->speedx = 0;
                ghost2->speedy = 5;
            }
        }
        else if(ghost2->y()<pacman->y()-160)
        {
            if(ghost2->movedown)
            {
                ghost2->right = false;
                ghost2->left = false;
                ghost2->up = false;
                ghost2->speedx = 0;
                ghost2->speedy = 5;
            }
            else if(ghost2->moveright)
            {
                ghost2->up = false;
                ghost2->left = false;
                ghost2->down = false;
                ghost2->speedx = 5;
                ghost2->speedy = 0;
            }
            else if(ghost2->moveleft)
            {

                ghost2->right = false;
                ghost2->up = false;
                ghost2->down = false;
                ghost2->speedx = -5;
                ghost2->speedy = 0;
            }
            else if(ghost2->moveup)
            {
                ghost2->right = false;
                ghost2->left = false;
                ghost2->down = false;
                ghost2->speedx = 0;
                ghost2->speedy = -5;
            }
        }
    }
    else
    {
        if(ghost2->y()>pacman->y()-160)
        {
            if(ghost2->moveup)
            {
                ghost2->right = false;
                ghost2->left = false;
                ghost2->down = false;
                ghost2->speedx = 0;
                ghost2->speedy = -5;
            }
            else if(ghost2->moveright)
            {
                ghost2->up = false;
                ghost2->left = false;
                ghost2->down = false;
                ghost2->speedx = 5;
                ghost2->speedy = 0;
            }
            else if(ghost2->moveleft)
            {

                ghost2->right = false;
                ghost2->up = false;
                ghost2->down = false;
                ghost2->speedx = -5;
                ghost2->speedy = 0;
            }
            else if(ghost2->movedown)
            {
                ghost2->right = false;
                ghost2->left = false;
                ghost2->up = false;
                ghost2->speedx = 0;
                ghost2->speedy = 5;
            }
        }
        else if(ghost2->y()<pacman->y()-160)
        {
            if(ghost2->movedown)
            {
                ghost2->right = false;
                ghost2->left = false;
                ghost2->up = false;
                ghost2->speedx = 0;
                ghost2->speedy = 5;
            }
            else if(ghost2->moveright)
            {
                ghost2->up = false;
                ghost2->left = false;
                ghost2->down = false;
                ghost2->speedx = 5;
                ghost2->speedy = 0;
            }
            else if(ghost2->moveleft)
            {

                ghost2->right = false;
                ghost2->up = false;
                ghost2->down = false;
                ghost2->speedx = -5;
                ghost2->speedy = 0;
            }
            else if(ghost2->moveup)
            {
                ghost2->right = false;
                ghost2->left = false;
                ghost2->down = false;
                ghost2->speedx = 0;
                ghost2->speedy = -5;
            }
        }
        else if(ghost2->x()>pacman->x()-320)
        {
        if(ghost2->moveleft)
        {

            ghost2->right = false;
            ghost2->up = false;
            ghost2->down = false;
            ghost2->speedx = -5;
            ghost2->speedy = 0;
        }
        else if(ghost2->moveup)
        {
            ghost2->right = false;
            ghost2->left = false;
            ghost2->down = false;
            ghost2->speedx = 0;
            ghost2->speedy = -5;
        }
        else if(ghost2->movedown)
        {
            ghost2->right = false;
            ghost2->left = false;
            ghost2->up = false;
            ghost2->speedx = 0;
            ghost2->speedy = 5;
        }
        else if(ghost2->moveright)
        {
            ghost2->up = false;
            ghost2->left = false;
            ghost2->down = false;
            ghost2->speedx = 5;
            ghost2->speedy = 0;
        }
    }
    else if(ghost2->x()<pacman->x()-320)
    {
        if(ghost2->moveright)
        {
            ghost2->up = false;
            ghost2->left = false;
            ghost2->down = false;
            ghost2->speedx = 5;
            ghost2->speedy = 0;
        }
        else if(ghost2->moveup)
        {
            ghost2->right = false;
            ghost2->left = false;
            ghost2->down = false;
            ghost2->speedx = 0;
            ghost2->speedy = -5;
        }
        else if(ghost2->movedown)
        {
            ghost2->right = false;
            ghost2->left = false;
            ghost2->up = false;
            ghost2->speedx = 0;
            ghost2->speedy = 5;
        }
        else if(ghost2->moveleft)
        {

            ghost2->right = false;
            ghost2->up = false;
            ghost2->down = false;
            ghost2->speedx = -5;
            ghost2->speedy = 0;
        }
    }
    }
    }
    ghostptr2->move();
}


void MainWindow::ghostupdater3()
{
    {
    if(ghost3->collidesWithItem(pacman,Qt::IntersectsItemShape)&&pacman->eatghost)
    {
        score = score + 50;
        timer3->stop();
        ghoststop3 = true;
        ghost3->setPos(0,0);
        ghost3->beeaten = true;
    }
    ghost3->restrict();
    if(ghost3->collidesWithItem(ghost,Qt::IntersectsItemShape))
    {
        ghost3->speedx = - ghost3->speedx;
        ghost3->speedy = - ghost3->speedy;
        if(ghost3->left)
        {
            ghost3->left = false;
            ghost3->right = true;
        }
        else if(ghost3->right)
        {
            ghost3->left = true;
            ghost3->right = false;
        }
        if(ghost3->up)
        {
            ghost3->up = false;
            ghost3->down = true;
        }
        else if(ghost3->down)
        {
            ghost3->up = true;
            ghost3->down = false;
        }
    }
    if(ghost3->collidesWithItem(ghost2,Qt::IntersectsItemShape))
    {
        ghost3->speedx = - ghost3->speedx;
        ghost3->speedy = - ghost3->speedy;
        if(ghost3->left)
        {
            ghost3->left = false;
            ghost3->right = true;
        }
        else if(ghost3->right)
        {
            ghost3->left = true;
            ghost3->right = false;
        }
        if(ghost3->up)
        {
            ghost3->up = false;
            ghost3->down = true;
        }
        else if(ghost3->down)
        {
            ghost3->up = true;
            ghost3->down = false;
        }
    }
    if(ghost3->collidesWithItem(ghost4,Qt::IntersectsItemShape))
    {
        ghost3->speedx = - ghost3->speedx;
        ghost3->speedy = - ghost3->speedy;
        if(ghost3->left)
        {
            ghost3->left = false;
            ghost3->right = true;
        }
        else if(ghost3->right)
        {
            ghost3->left = true;
            ghost3->right = false;
        }
        if(ghost3->up)
        {
            ghost3->up = false;
            ghost3->down = true;
        }
        else if(ghost3->down)
        {
            ghost3->up = true;
            ghost3->down = false;
        }
    }
    }
    if(ghost3->decide())
    {
        ghost3->moveleft = true;
        ghost3->moveright = true;
        ghost3->moveup = true;
        ghost3->movedown = true;
        ghost3->left = true;
        ghost3->right = true;
        ghost3->up = true;
        ghost3->down = true;
        ghost3->restrict();
        qreal absx,absy;
        absx = ghost3->x()-pacman->x();
        absy = ghost3->y()-pacman->y();
        {
        if(absx<0)
            absx = -absx;
        if(absy<0)
            absy = -absy;
        }
        qreal absx1,absy1;
        absx1 = ghost3->x()-ghost->x();
        absy1 = ghost3->y()-ghost->y();
        {
        if(absx1<0)
            absx1 = -absx1;
        if(absy1<0)
            absy1 = -absy1;
        }
        if(absx1 >200&& absy1 >100){
    if(absx>absy){
    if(ghost3->x()>pacman->x()+320)
    {
        if(ghost3->moveleft)
        {

            ghost3->right = false;
            ghost3->up = false;
            ghost3->down = false;
            ghost3->speedx = -5;
            ghost3->speedy = 0;
        }
        else if(ghost3->moveup)
        {
            ghost3->right = false;
            ghost3->left = false;
            ghost3->down = false;
            ghost3->speedx = 0;
            ghost3->speedy = -5;
        }
        else if(ghost3->movedown)
        {
            ghost3->right = false;
            ghost3->left = false;
            ghost3->up = false;
            ghost3->speedx = 0;
            ghost3->speedy = 5;
        }
        else if(ghost3->moveright)
        {
            ghost3->up = false;
            ghost3->left = false;
            ghost3->down = false;
            ghost3->speedx = 5;
            ghost3->speedy = 0;
        }
    }
    else if(ghost3->x()<pacman->x()+320)
    {
        if(ghost3->moveright)
        {
            ghost3->up = false;
            ghost3->left = false;
            ghost3->down = false;
            ghost3->speedx = 5;
            ghost3->speedy = 0;
        }
        else if(ghost3->moveup)
        {
            ghost3->right = false;
            ghost3->left = false;
            ghost3->down = false;
            ghost3->speedx = 0;
            ghost3->speedy = -5;
        }
        else if(ghost3->movedown)
        {
            ghost3->right = false;
            ghost3->left = false;
            ghost3->up = false;
            ghost3->speedx = 0;
            ghost3->speedy = 5;
        }
        else if(ghost3->moveleft)
        {

            ghost3->right = false;
            ghost3->up = false;
            ghost3->down = false;
            ghost3->speedx = -5;
            ghost3->speedy = 0;
        }
    }
        else if(ghost3->y()>pacman->y()+160)
        {
            if(ghost3->moveup)
            {
                ghost3->right = false;
                ghost3->left = false;
                ghost3->down = false;
                ghost3->speedx = 0;
                ghost3->speedy = -5;
            }
            else if(ghost3->moveright)
            {
                ghost3->up = false;
                ghost3->left = false;
                ghost3->down = false;
                ghost3->speedx = 5;
                ghost3->speedy = 0;
            }
            else if(ghost3->moveleft)
            {

                ghost3->right = false;
                ghost3->up = false;
                ghost3->down = false;
                ghost3->speedx = -5;
                ghost3->speedy = 0;
            }
            else if(ghost3->movedown)
            {
                ghost3->right = false;
                ghost3->left = false;
                ghost3->up = false;
                ghost3->speedx = 0;
                ghost3->speedy = 5;
            }
        }
        else if(ghost3->y()<pacman->y()+160)
        {
            if(ghost3->movedown)
            {
                ghost3->right = false;
                ghost3->left = false;
                ghost3->up = false;
                ghost3->speedx = 0;
                ghost3->speedy = 5;
            }
            else if(ghost3->moveright)
            {
                ghost3->up = false;
                ghost3->left = false;
                ghost3->down = false;
                ghost3->speedx = 5;
                ghost3->speedy = 0;
            }
            else if(ghost3->moveleft)
            {

                ghost3->right = false;
                ghost3->up = false;
                ghost3->down = false;
                ghost3->speedx = -5;
                ghost3->speedy = 0;
            }
            else if(ghost3->moveup)
            {
                ghost3->right = false;
                ghost3->left = false;
                ghost3->down = false;
                ghost3->speedx = 0;
                ghost3->speedy = -5;
            }
        }
    }
    else
    {
        if(ghost3->y()>pacman->y()+160)
        {
            if(ghost3->moveup)
            {
                ghost3->right = false;
                ghost3->left = false;
                ghost3->down = false;
                ghost3->speedx = 0;
                ghost3->speedy = -5;
            }
            else if(ghost3->moveright)
            {
                ghost3->up = false;
                ghost3->left = false;
                ghost3->down = false;
                ghost3->speedx = 5;
                ghost3->speedy = 0;
            }
            else if(ghost3->moveleft)
            {

                ghost3->right = false;
                ghost3->up = false;
                ghost3->down = false;
                ghost3->speedx = -5;
                ghost3->speedy = 0;
            }
            else if(ghost3->movedown)
            {
                ghost3->right = false;
                ghost3->left = false;
                ghost3->up = false;
                ghost3->speedx = 0;
                ghost3->speedy = 5;
            }
        }
        else if(ghost3->y()<pacman->y()+160)
        {
            if(ghost3->movedown)
            {
                ghost3->right = false;
                ghost3->left = false;
                ghost3->up = false;
                ghost3->speedx = 0;
                ghost3->speedy = 5;
            }
            else if(ghost3->moveright)
            {
                ghost3->up = false;
                ghost3->left = false;
                ghost3->down = false;
                ghost3->speedx = 5;
                ghost3->speedy = 0;
            }
            else if(ghost3->moveleft)
            {

                ghost3->right = false;
                ghost3->up = false;
                ghost3->down = false;
                ghost3->speedx = -5;
                ghost3->speedy = 0;
            }
            else if(ghost3->moveup)
            {
                ghost3->right = false;
                ghost3->left = false;
                ghost3->down = false;
                ghost3->speedx = 0;
                ghost3->speedy = -5;
            }
        }
        else if(ghost3->x()>pacman->x()+320)
        {
        if(ghost3->moveleft)
        {

            ghost3->right = false;
            ghost3->up = false;
            ghost3->down = false;
            ghost3->speedx = -5;
            ghost3->speedy = 0;
        }
        else if(ghost3->moveup)
        {
            ghost3->right = false;
            ghost3->left = false;
            ghost3->down = false;
            ghost3->speedx = 0;
            ghost3->speedy = -5;
        }
        else if(ghost3->movedown)
        {
            ghost3->right = false;
            ghost3->left = false;
            ghost3->up = false;
            ghost3->speedx = 0;
            ghost3->speedy = 5;
        }
        else if(ghost3->moveright)
        {
            ghost3->up = false;
            ghost3->left = false;
            ghost3->down = false;
            ghost3->speedx = 5;
            ghost3->speedy = 0;
        }
    }
    else if(ghost3->x()<pacman->x()+320)
    {
        if(ghost3->moveright)
        {
            ghost3->up = false;
            ghost3->left = false;
            ghost3->down = false;
            ghost3->speedx = 5;
            ghost3->speedy = 0;
        }
        else if(ghost3->moveup)
        {
            ghost3->right = false;
            ghost3->left = false;
            ghost3->down = false;
            ghost3->speedx = 0;
            ghost3->speedy = -5;
        }
        else if(ghost3->movedown)
        {
            ghost3->right = false;
            ghost3->left = false;
            ghost3->up = false;
            ghost3->speedx = 0;
            ghost3->speedy = 5;
        }
        else if(ghost3->moveleft)
        {

            ghost3->right = false;
            ghost3->up = false;
            ghost3->down = false;
            ghost3->speedx = -5;
            ghost3->speedy = 0;
        }
    }
    }
        }
    else
    {
            if(absx1>absy1){
            if(ghost3->x()>140)
            {
                if(ghost3->moveleft)
                {

                    ghost3->right = false;
                    ghost3->up = false;
                    ghost3->down = false;
                    ghost3->speedx = -5;
                    ghost3->speedy = 0;
                }
                else if(ghost3->moveup)
                {
                    ghost3->right = false;
                    ghost3->left = false;
                    ghost3->down = false;
                    ghost3->speedx = 0;
                    ghost3->speedy = -5;
                }
                else if(ghost3->movedown)
                {
                    ghost3->right = false;
                    ghost3->left = false;
                    ghost3->up = false;
                    ghost3->speedx = 0;
                    ghost3->speedy = 5;
                }
                else if(ghost3->moveright)
                {
                    ghost3->up = false;
                    ghost3->left = false;
                    ghost3->down = false;
                    ghost3->speedx = 5;
                    ghost3->speedy = 0;
                }
            }
            else if(ghost3->x()<=140)
            {
                if(ghost3->moveright)
                {
                    ghost3->up = false;
                    ghost3->left = false;
                    ghost3->down = false;
                    ghost3->speedx = 5;
                    ghost3->speedy = 0;
                }
                else if(ghost3->moveup)
                {
                    ghost3->right = false;
                    ghost3->left = false;
                    ghost3->down = false;
                    ghost3->speedx = 0;
                    ghost3->speedy = -5;
                }
                else if(ghost3->movedown)
                {
                    ghost3->right = false;
                    ghost3->left = false;
                    ghost3->up = false;
                    ghost3->speedx = 0;
                    ghost3->speedy = 5;
                }
                else if(ghost3->moveleft)
                {

                    ghost3->right = false;
                    ghost3->up = false;
                    ghost3->down = false;
                    ghost3->speedx = -5;
                    ghost3->speedy = 0;
                }
            }
                else if(ghost3->y()>=540)
                {
                    if(ghost3->moveup)
                    {
                        ghost3->right = false;
                        ghost3->left = false;
                        ghost3->down = false;
                        ghost3->speedx = 0;
                        ghost3->speedy = -5;
                    }
                    else if(ghost3->moveright)
                    {
                        ghost3->up = false;
                        ghost3->left = false;
                        ghost3->down = false;
                        ghost3->speedx = 5;
                        ghost3->speedy = 0;
                    }
                    else if(ghost3->moveleft)
                    {

                        ghost3->right = false;
                        ghost3->up = false;
                        ghost3->down = false;
                        ghost3->speedx = -5;
                        ghost3->speedy = 0;
                    }
                    else if(ghost3->movedown)
                    {
                        ghost3->right = false;
                        ghost3->left = false;
                        ghost3->up = false;
                        ghost3->speedx = 0;
                        ghost3->speedy = 5;
                    }
                }
                else if(ghost3->y()<540)
                {
                    if(ghost3->movedown)
                    {
                        ghost3->right = false;
                        ghost3->left = false;
                        ghost3->up = false;
                        ghost3->speedx = 0;
                        ghost3->speedy = 5;
                    }
                    else if(ghost3->moveright)
                    {
                        ghost3->up = false;
                        ghost3->left = false;
                        ghost3->down = false;
                        ghost3->speedx = 5;
                        ghost3->speedy = 0;
                    }
                    else if(ghost3->moveleft)
                    {

                        ghost3->right = false;
                        ghost3->up = false;
                        ghost3->down = false;
                        ghost3->speedx = -5;
                        ghost3->speedy = 0;
                    }
                    else if(ghost3->moveup)
                    {
                        ghost3->right = false;
                        ghost3->left = false;
                        ghost3->down = false;
                        ghost3->speedx = 0;
                        ghost3->speedy = -5;
                    }
                }
            }
            else
            {
                if(ghost3->y()>540)
                {
                    if(ghost3->moveup)
                    {
                        ghost3->right = false;
                        ghost3->left = false;
                        ghost3->down = false;
                        ghost3->speedx = 0;
                        ghost3->speedy = -5;
                    }
                    else if(ghost3->moveright)
                    {
                        ghost3->up = false;
                        ghost3->left = false;
                        ghost3->down = false;
                        ghost3->speedx = 5;
                        ghost3->speedy = 0;
                    }
                    else if(ghost3->moveleft)
                    {

                        ghost3->right = false;
                        ghost3->up = false;
                        ghost3->down = false;
                        ghost3->speedx = -5;
                        ghost3->speedy = 0;
                    }
                    else if(ghost3->movedown)
                    {
                        ghost3->right = false;
                        ghost3->left = false;
                        ghost3->up = false;
                        ghost3->speedx = 0;
                        ghost3->speedy = 5;
                    }
                }
                else if(ghost3->y()<540)
                {
                    if(ghost3->movedown)
                    {
                        ghost3->right = false;
                        ghost3->left = false;
                        ghost3->up = false;
                        ghost3->speedx = 0;
                        ghost3->speedy = 5;
                    }
                    else if(ghost3->moveright)
                    {
                        ghost3->up = false;
                        ghost3->left = false;
                        ghost3->down = false;
                        ghost3->speedx = 5;
                        ghost3->speedy = 0;
                    }
                    else if(ghost3->moveleft)
                    {

                        ghost3->right = false;
                        ghost3->up = false;
                        ghost3->down = false;
                        ghost3->speedx = -5;
                        ghost3->speedy = 0;
                    }
                    else if(ghost3->moveup)
                    {
                        ghost3->right = false;
                        ghost3->left = false;
                        ghost3->down = false;
                        ghost3->speedx = 0;
                        ghost3->speedy = -5;
                    }
                }
                else if(ghost3->x()>140)
                {
                if(ghost3->moveleft)
                {

                    ghost3->right = false;
                    ghost3->up = false;
                    ghost3->down = false;
                    ghost3->speedx = -5;
                    ghost3->speedy = 0;
                }
                else if(ghost3->moveup)
                {
                    ghost3->right = false;
                    ghost3->left = false;
                    ghost3->down = false;
                    ghost3->speedx = 0;
                    ghost3->speedy = -5;
                }
                else if(ghost3->movedown)
                {
                    ghost3->right = false;
                    ghost3->left = false;
                    ghost3->up = false;
                    ghost3->speedx = 0;
                    ghost3->speedy = 5;
                }
                else if(ghost3->moveright)
                {
                    ghost3->up = false;
                    ghost3->left = false;
                    ghost3->down = false;
                    ghost3->speedx = 5;
                    ghost3->speedy = 0;
                }
            }
            else if(ghost3->x()<140)
            {
                if(ghost3->moveright)
                {
                    ghost3->up = false;
                    ghost3->left = false;
                    ghost3->down = false;
                    ghost3->speedx = 5;
                    ghost3->speedy = 0;
                }
                else if(ghost3->moveup)
                {
                    ghost3->right = false;
                    ghost3->left = false;
                    ghost3->down = false;
                    ghost3->speedx = 0;
                    ghost3->speedy = -5;
                }
                else if(ghost3->movedown)
                {
                    ghost3->right = false;
                    ghost3->left = false;
                    ghost3->up = false;
                    ghost3->speedx = 0;
                    ghost3->speedy = 5;
                }
                else if(ghost3->moveleft)
                {

                    ghost3->right = false;
                    ghost3->up = false;
                    ghost3->down = false;
                    ghost3->speedx = -5;
                    ghost3->speedy = 0;
                }
            }
            }
    }
    }
    ghostptr3->move();
}

void MainWindow::ghostupdater4()
{
    if(ghost4->collidesWithItem(pacman,Qt::IntersectsItemShape)&&pacman->eatghost)
    {
        score = score + 50;
        timer4->stop();
        ghoststop4 = true;
        ghost4->setPos(0,0);
        ghost4->beeaten = true;
    }
    ghost4->restrict();
    if(ghost4->collidesWithItem(ghost,Qt::IntersectsItemShape))
    {
        ghost4->speedx = - ghost4->speedx;
        ghost4->speedy = - ghost4->speedy;
        if(ghost4->left)
        {
            ghost4->left = false;
            ghost4->right = true;
        }
        else if(ghost4->right)
        {
            ghost4->left = true;
            ghost4->right = false;
        }
        if(ghost4->up)
        {
            ghost4->up = false;
            ghost4->down = true;
        }
        else if(ghost4->down)
        {
            ghost4->up = true;
            ghost4->down = false;
        }
    }
    if(ghost4->collidesWithItem(ghost2,Qt::IntersectsItemShape))
    {
        ghost4->speedx = - ghost4->speedx;
        ghost4->speedy = - ghost4->speedy;
        if(ghost3->left)
        {
            ghost4->left = false;
            ghost4->right = true;
        }
        else if(ghost4->right)
        {
            ghost4->left = true;
            ghost4->right = false;
        }
        if(ghost4->up)
        {
            ghost4->up = false;
            ghost4->down = true;
        }
        else if(ghost4->down)
        {
            ghost4->up = true;
            ghost4->down = false;
        }
    }
    if(ghost4->collidesWithItem(ghost3,Qt::IntersectsItemShape))
    {
        ghost4->speedx = - ghost4->speedx;
        ghost4->speedy = - ghost4->speedy;
        if(ghost3->left)
        {
            ghost4->left = false;
            ghost4->right = true;
        }
        else if(ghost4->right)
        {
            ghost4->left = true;
            ghost4->right = false;
        }
        if(ghost4->up)
        {
            ghost4->up = false;
            ghost4->down = true;
        }
        else if(ghost4->down)
        {
            ghost4->up = true;
            ghost4->down = false;
        }
    }
    if(ghost4->decide())
    {
        ghost4->moveleft = true;
        ghost4->moveright = true;
        ghost4->moveup = true;
        ghost4->movedown = true;
        ghost4->left = true;
        ghost4->right = true;
        ghost4->up = true;
        ghost4->down = true;
        ghost4->restrict();
        qreal absx,absy;
        absx = ghost4->x()-pacman->x();
        absy = ghost4->y()-pacman->y();
        {
        if(absx<0)
            absx = -absx;
        if(absy<0)
            absy = -absy;
        }
        if(absx >200&& absy >100){
    if(absx>absy){
    if(ghost4->x()>ghost->x())
    {
        if(ghost4->moveleft)
        {

            ghost4->right = false;
            ghost4->up = false;
            ghost4->down = false;
            ghost4->speedx = -5;
            ghost4->speedy = 0;
        }
        else if(ghost4->moveup)
        {
            ghost4->right = false;
            ghost4->left = false;
            ghost4->down = false;
            ghost4->speedx = 0;
            ghost4->speedy = -5;
        }
        else if(ghost4->movedown)
        {
            ghost4->right = false;
            ghost4->left = false;
            ghost4->up = false;
            ghost4->speedx = 0;
            ghost4->speedy = 5;
        }
        else if(ghost4->moveright)
        {
            ghost4->up = false;
            ghost4->left = false;
            ghost4->down = false;
            ghost4->speedx = 5;
            ghost4->speedy = 0;
        }
    }
    else if(ghost4->x()<ghost->x())
    {
        if(ghost4->moveright)
        {
            ghost4->up = false;
            ghost4->left = false;
            ghost4->down = false;
            ghost4->speedx = 5;
            ghost4->speedy = 0;
        }
        else if(ghost4->moveup)
        {
            ghost4->right = false;
            ghost4->left = false;
            ghost4->down = false;
            ghost4->speedx = 0;
            ghost4->speedy = -5;
        }
        else if(ghost4->movedown)
        {
            ghost4->right = false;
            ghost4->left = false;
            ghost4->up = false;
            ghost4->speedx = 0;
            ghost4->speedy = 5;
        }
        else if(ghost4->moveleft)
        {

            ghost4->right = false;
            ghost4->up = false;
            ghost4->down = false;
            ghost4->speedx = -5;
            ghost4->speedy = 0;
        }
    }
        else if(ghost4->y()>ghost->y())
        {
            if(ghost4->moveup)
            {
                ghost4->right = false;
                ghost4->left = false;
                ghost4->down = false;
                ghost4->speedx = 0;
                ghost4->speedy = -5;
            }
            else if(ghost4->moveright)
            {
                ghost4->up = false;
                ghost4->left = false;
                ghost4->down = false;
                ghost4->speedx = 5;
                ghost4->speedy = 0;
            }
            else if(ghost4->moveleft)
            {

                ghost4->right = false;
                ghost4->up = false;
                ghost4->down = false;
                ghost4->speedx = -5;
                ghost4->speedy = 0;
            }
            else if(ghost4->movedown)
            {
                ghost4->right = false;
                ghost4->left = false;
                ghost4->up = false;
                ghost4->speedx = 0;
                ghost4->speedy = 5;
            }
        }
        else if(ghost4->y()<ghost->y())
        {
            if(ghost4->movedown)
            {
                ghost4->right = false;
                ghost4->left = false;
                ghost4->up = false;
                ghost4->speedx = 0;
                ghost4->speedy = 5;
            }
            else if(ghost4->moveright)
            {
                ghost4->up = false;
                ghost4->left = false;
                ghost4->down = false;
                ghost4->speedx = 5;
                ghost4->speedy = 0;
            }
            else if(ghost4->moveleft)
            {

                ghost4->right = false;
                ghost4->up = false;
                ghost4->down = false;
                ghost4->speedx = -5;
                ghost4->speedy = 0;
            }
            else if(ghost4->moveup)
            {
                ghost4->right = false;
                ghost4->left = false;
                ghost4->down = false;
                ghost4->speedx = 0;
                ghost4->speedy = -5;
            }
        }
    }
    else
    {
        if(ghost4->y()>ghost->y())
        {
            if(ghost4->moveup)
            {
                ghost4->right = false;
                ghost4->left = false;
                ghost4->down = false;
                ghost4->speedx = 0;
                ghost4->speedy = -5;
            }
            else if(ghost4->moveright)
            {
                ghost4->up = false;
                ghost4->left = false;
                ghost4->down = false;
                ghost4->speedx = 5;
                ghost4->speedy = 0;
            }
            else if(ghost4->moveleft)
            {

                ghost4->right = false;
                ghost4->up = false;
                ghost4->down = false;
                ghost4->speedx = -5;
                ghost4->speedy = 0;
            }
            else if(ghost4->movedown)
            {
                ghost4->right = false;
                ghost4->left = false;
                ghost4->up = false;
                ghost4->speedx = 0;
                ghost4->speedy = 5;
            }
        }
        else if(ghost4->y()<ghost->y())
        {
            if(ghost4->movedown)
            {
                ghost4->right = false;
                ghost4->left = false;
                ghost4->up = false;
                ghost4->speedx = 0;
                ghost4->speedy = 5;
            }
            else if(ghost4->moveright)
            {
                ghost4->up = false;
                ghost4->left = false;
                ghost4->down = false;
                ghost4->speedx = 5;
                ghost4->speedy = 0;
            }
            else if(ghost4->moveleft)
            {

                ghost4->right = false;
                ghost4->up = false;
                ghost4->down = false;
                ghost4->speedx = -5;
                ghost4->speedy = 0;
            }
            else if(ghost4->moveup)
            {
                ghost4->right = false;
                ghost4->left = false;
                ghost4->down = false;
                ghost4->speedx = 0;
                ghost4->speedy = -5;
            }
        }
        else if(ghost4->x()>ghost->x())
        {
        if(ghost4->moveleft)
        {

            ghost4->right = false;
            ghost4->up = false;
            ghost4->down = false;
            ghost4->speedx = -5;
            ghost4->speedy = 0;
        }
        else if(ghost4->moveup)
        {
            ghost4->right = false;
            ghost4->left = false;
            ghost4->down = false;
            ghost4->speedx = 0;
            ghost4->speedy = -5;
        }
        else if(ghost4->movedown)
        {
            ghost4->right = false;
            ghost4->left = false;
            ghost4->up = false;
            ghost4->speedx = 0;
            ghost4->speedy = 5;
        }
        else if(ghost4->moveright)
        {
            ghost4->up = false;
            ghost4->left = false;
            ghost4->down = false;
            ghost4->speedx = 5;
            ghost4->speedy = 0;
        }
    }
    else if(ghost4->x()<ghost->x())
    {
        if(ghost4->moveright)
        {
            ghost4->up = false;
            ghost4->left = false;
            ghost4->down = false;
            ghost4->speedx = 5;
            ghost4->speedy = 0;
        }
        else if(ghost4->moveup)
        {
            ghost4->right = false;
            ghost4->left = false;
            ghost4->down = false;
            ghost4->speedx = 0;
            ghost4->speedy = -5;
        }
        else if(ghost4->movedown)
        {
            ghost4->right = false;
            ghost4->left = false;
            ghost4->up = false;
            ghost4->speedx = 0;
            ghost4->speedy = 5;
        }
        else if(ghost4->moveleft)
        {

            ghost4->right = false;
            ghost4->up = false;
            ghost4->down = false;
            ghost4->speedx = -5;
            ghost4->speedy = 0;
        }
    }
    }
        }
        else
        {
            absx = ghost2->x()-140;
            absy = ghost2->y()-540;
            {
            if(absx<0)
                absx = -absx;
            if(absy<0)
                absy = -absy;
            }
            if(absx>absy){
            if(ghost4->x()>140)
            {
                if(ghost4->moveleft)
                {

                    ghost4->right = false;
                    ghost4->up = false;
                    ghost4->down = false;
                    ghost4->speedx = -5;
                    ghost4->speedy = 0;
                }
                else if(ghost4->moveup)
                {
                    ghost4->right = false;
                    ghost4->left = false;
                    ghost4->down = false;
                    ghost4->speedx = 0;
                    ghost4->speedy = -5;
                }
                else if(ghost4->movedown)
                {
                    ghost4->right = false;
                    ghost4->left = false;
                    ghost4->up = false;
                    ghost4->speedx = 0;
                    ghost4->speedy = 5;
                }
                else if(ghost4->moveright)
                {
                    ghost4->up = false;
                    ghost4->left = false;
                    ghost4->down = false;
                    ghost4->speedx = 5;
                    ghost4->speedy = 0;
                }
            }
            else if(ghost4->x()<140)
            {
                if(ghost4->moveright)
                {
                    ghost4->up = false;
                    ghost4->left = false;
                    ghost4->down = false;
                    ghost4->speedx = 5;
                    ghost4->speedy = 0;
                }
                else if(ghost4->moveup)
                {
                    ghost4->right = false;
                    ghost4->left = false;
                    ghost4->down = false;
                    ghost4->speedx = 0;
                    ghost4->speedy = -5;
                }
                else if(ghost4->movedown)
                {
                    ghost4->right = false;
                    ghost4->left = false;
                    ghost4->up = false;
                    ghost4->speedx = 0;
                    ghost4->speedy = 5;
                }
                else if(ghost4->moveleft)
                {

                    ghost4->right = false;
                    ghost4->up = false;
                    ghost4->down = false;
                    ghost4->speedx = -5;
                    ghost4->speedy = 0;
                }
            }
                else if(ghost4->y()>540)
                {
                    if(ghost4->moveup)
                    {
                        ghost4->right = false;
                        ghost4->left = false;
                        ghost4->down = false;
                        ghost4->speedx = 0;
                        ghost4->speedy = -5;
                    }
                    else if(ghost4->moveright)
                    {
                        ghost4->up = false;
                        ghost4->left = false;
                        ghost4->down = false;
                        ghost4->speedx = 5;
                        ghost4->speedy = 0;
                    }
                    else if(ghost4->moveleft)
                    {

                        ghost4->right = false;
                        ghost4->up = false;
                        ghost4->down = false;
                        ghost4->speedx = -5;
                        ghost4->speedy = 0;
                    }
                    else if(ghost4->movedown)
                    {
                        ghost4->right = false;
                        ghost4->left = false;
                        ghost4->up = false;
                        ghost4->speedx = 0;
                        ghost4->speedy = 5;
                    }
                }
                else if(ghost4->y()<540)
                {
                    if(ghost4->movedown)
                    {
                        ghost4->right = false;
                        ghost4->left = false;
                        ghost4->up = false;
                        ghost4->speedx = 0;
                        ghost4->speedy = 5;
                    }
                    else if(ghost4->moveright)
                    {
                        ghost4->up = false;
                        ghost4->left = false;
                        ghost4->down = false;
                        ghost4->speedx = 5;
                        ghost4->speedy = 0;
                    }
                    else if(ghost4->moveleft)
                    {

                        ghost4->right = false;
                        ghost4->up = false;
                        ghost4->down = false;
                        ghost4->speedx = -5;
                        ghost4->speedy = 0;
                    }
                    else if(ghost4->moveup)
                    {
                        ghost4->right = false;
                        ghost4->left = false;
                        ghost4->down = false;
                        ghost4->speedx = 0;
                        ghost4->speedy = -5;
                    }
                }
            }
            else
            {
                if(ghost4->y()>ghost->y())
                {
                    if(ghost4->moveup)
                    {
                        ghost4->right = false;
                        ghost4->left = false;
                        ghost4->down = false;
                        ghost4->speedx = 0;
                        ghost4->speedy = -5;
                    }
                    else if(ghost4->moveright)
                    {
                        ghost4->up = false;
                        ghost4->left = false;
                        ghost4->down = false;
                        ghost4->speedx = 5;
                        ghost4->speedy = 0;
                    }
                    else if(ghost4->moveleft)
                    {

                        ghost4->right = false;
                        ghost4->up = false;
                        ghost4->down = false;
                        ghost4->speedx = -5;
                        ghost4->speedy = 0;
                    }
                    else if(ghost4->movedown)
                    {
                        ghost4->right = false;
                        ghost4->left = false;
                        ghost4->up = false;
                        ghost4->speedx = 0;
                        ghost4->speedy = 5;
                    }
                }
                else if(ghost4->y()<540)
                {
                    if(ghost4->movedown)
                    {
                        ghost4->right = false;
                        ghost4->left = false;
                        ghost4->up = false;
                        ghost4->speedx = 0;
                        ghost4->speedy = 5;
                    }
                    else if(ghost4->moveright)
                    {
                        ghost4->up = false;
                        ghost4->left = false;
                        ghost4->down = false;
                        ghost4->speedx = 5;
                        ghost4->speedy = 0;
                    }
                    else if(ghost4->moveleft)
                    {

                        ghost4->right = false;
                        ghost4->up = false;
                        ghost4->down = false;
                        ghost4->speedx = -5;
                        ghost4->speedy = 0;
                    }
                    else if(ghost4->moveup)
                    {
                        ghost4->right = false;
                        ghost4->left = false;
                        ghost4->down = false;
                        ghost4->speedx = 0;
                        ghost4->speedy = -5;
                    }
                }
                else if(ghost4->x()>140)
                {
                if(ghost4->moveleft)
                {

                    ghost4->right = false;
                    ghost4->up = false;
                    ghost4->down = false;
                    ghost4->speedx = -5;
                    ghost4->speedy = 0;
                }
                else if(ghost4->moveup)
                {
                    ghost4->right = false;
                    ghost4->left = false;
                    ghost4->down = false;
                    ghost4->speedx = 0;
                    ghost4->speedy = -5;
                }
                else if(ghost4->movedown)
                {
                    ghost4->right = false;
                    ghost4->left = false;
                    ghost4->up = false;
                    ghost4->speedx = 0;
                    ghost4->speedy = 5;
                }
                else if(ghost4->moveright)
                {
                    ghost4->up = false;
                    ghost4->left = false;
                    ghost4->down = false;
                    ghost4->speedx = 5;
                    ghost4->speedy = 0;
                }
            }
            else if(ghost4->x()<140)
            {
                if(ghost4->moveright)
                {
                    ghost4->up = false;
                    ghost4->left = false;
                    ghost4->down = false;
                    ghost4->speedx = 5;
                    ghost4->speedy = 0;
                }
                else if(ghost4->moveup)
                {
                    ghost4->right = false;
                    ghost4->left = false;
                    ghost4->down = false;
                    ghost4->speedx = 0;
                    ghost4->speedy = -5;
                }
                else if(ghost4->movedown)
                {
                    ghost4->right = false;
                    ghost4->left = false;
                    ghost4->up = false;
                    ghost4->speedx = 0;
                    ghost4->speedy = 5;
                }
                else if(ghost4->moveleft)
                {

                    ghost4->right = false;
                    ghost4->up = false;
                    ghost4->down = false;
                    ghost4->speedx = -5;
                    ghost4->speedy = 0;
                }
            }
            }
        }
}
    ghostptr4->move();
}
