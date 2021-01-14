#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QVector>
#include <iostream>



using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("象棋");
    //按鈕
    set = new QPushButton("設定棋子",this);
    set->setGeometry(1020,400,150,80);
    connect(set,SIGNAL(clicked(bool)),this,SLOT(settingmodeclicked()));

    select = new QLabel(this);

    start = new QPushButton("開始遊戲",this);
    start->setGeometry(1020,200,150,80);
    connect(start,SIGNAL(clicked(bool)),this,SLOT(startgameclicked()));

    restart = new QPushButton("重新開始",this);
    restart->setGeometry(1020,600,150,80);
    connect(restart,SIGNAL(clicked(bool)),this,SLOT(restartclicked()));


    massage = new QLabel(this);
    massage->setGeometry(10,10,260,100);
    QFont font;
    font.setPointSize(40);
    font.setBold(true);
    massage->setFont(font);


    QPixmap p1(":/img/shuai.png");
    QPixmap p2(":/img/hongshi.png");
    QPixmap p3(":/img/hongxiang.png");
    QPixmap p4(":/img/hongma.png");
    QPixmap p5(":/img/hongju.png");
    QPixmap p6(":/img/hongpao.png");
    QPixmap p7(":/img/bing.png");
    QPixmap p8(":/img/jiang.png");
    QPixmap p9(":/img/heishi.png");
    QPixmap p10(":/img/heixiang.png");
    QPixmap p11(":/img/heima.png");
    QPixmap p12(":/img/heiju.png");
    QPixmap p13(":/img/heipao.png");
    QPixmap p14(":/img/zu.png");
    QPixmap p15(":/img/test1.png");

    for(short i=0;i<90;++i)
    {
        move[i] = new QLabel(this);
        move[i]->setPixmap(p15.scaled(60,60,Qt::KeepAspectRatio));
        move[i]->setGeometry(0,0,0,0);
    }


    select->setPixmap(p15.scaled(60,60,Qt::KeepAspectRatio));
    select->setGeometry(0,0,0,0);

    for(short i=0;i<14;++i)
    {
        setchess[i] = new  QLabel(this);
    }

    setchess[0]->setPixmap(p1.scaled(60,60,Qt::KeepAspectRatio));
    setchess[0]->setGeometry(0,0,0,0);
    setchess[1]->setPixmap(p2.scaled(60,60,Qt::KeepAspectRatio));
    setchess[1]->setGeometry(0,0,0,0);
    setchess[2]->setPixmap(p3.scaled(60,60,Qt::KeepAspectRatio));
    setchess[2]->setGeometry(0,0,0,0);
    setchess[3]->setPixmap(p4.scaled(60,60,Qt::KeepAspectRatio));
    setchess[3]->setGeometry(0,0,0,0);
    setchess[4]->setPixmap(p5.scaled(60,60,Qt::KeepAspectRatio));
    setchess[4]->setGeometry(0,0,0,0);
    setchess[5]->setPixmap(p6.scaled(60,60,Qt::KeepAspectRatio));
    setchess[5]->setGeometry(0,0,0,0);
    setchess[6]->setPixmap(p7.scaled(60,60,Qt::KeepAspectRatio));
    setchess[6]->setGeometry(0,0,0,0);
    setchess[7]->setPixmap(p8.scaled(60,60,Qt::KeepAspectRatio));
    setchess[7]->setGeometry(0,0,0,0);
    setchess[8]->setPixmap(p9.scaled(60,60,Qt::KeepAspectRatio));
    setchess[8]->setGeometry(0,0,0,0);
    setchess[9]->setPixmap(p10.scaled(60,60,Qt::KeepAspectRatio));
    setchess[9]->setGeometry(0,0,0,0);
    setchess[10]->setPixmap(p11.scaled(60,60,Qt::KeepAspectRatio));
    setchess[10]->setGeometry(0,0,0,0);
    setchess[11]->setPixmap(p12.scaled(60,60,Qt::KeepAspectRatio));
    setchess[11]->setGeometry(0,0,0,0);
    setchess[12]->setPixmap(p13.scaled(60,60,Qt::KeepAspectRatio));
    setchess[12]->setGeometry(0,0,0,0);
    setchess[13]->setPixmap(p14.scaled(60,60,Qt::KeepAspectRatio));
    setchess[13]->setGeometry(0,0,0,0);

    mousepoint = new QLabel(this);
    mousepoint->setText("mousepoint:");
    mousepoint->setFixedWidth(200);
    statusBar()->addPermanentWidget(mousepoint);

    for(short i=0;i<32;i++)
    {
        chess.push_back(new Chess);
    }


    for(short i=0;i<32;++i)
    {
        chess[i]->label =new QLabel(this);
    }

{
    chess[0]->label->setPixmap(p8.scaled(60,60,Qt::KeepAspectRatio));
    chess[0]->label->setGeometry(0,0,0,0);

    chess[1]->label->setPixmap(p9.scaled(60,60,Qt::KeepAspectRatio));
    chess[1]->label->setGeometry(0,0,0,0);

    chess[2]->label->setPixmap(p9.scaled(60,60,Qt::KeepAspectRatio));
    chess[2]->label->setGeometry(0,0,0,0);

    chess[3]->label->setPixmap(p10.scaled(60,60,Qt::KeepAspectRatio));
    chess[3]->label->setGeometry(0,0,0,0);

    chess[4]->label->setPixmap(p10.scaled(60,60,Qt::KeepAspectRatio));
    chess[4]->label->setGeometry(0,0,0,0);

    chess[5]->label->setPixmap(p11.scaled(60,60,Qt::KeepAspectRatio));
    chess[5]->label->setGeometry(0,0,0,0);

    chess[6]->label->setPixmap(p11.scaled(60,60,Qt::KeepAspectRatio));
    chess[6]->label->setGeometry(0,0,0,0);

    chess[7]->label->setPixmap(p12.scaled(60,60,Qt::KeepAspectRatio));
    chess[7]->label->setGeometry(0,0,0,0);

    chess[8]->label->setPixmap(p12.scaled(60,60,Qt::KeepAspectRatio));
    chess[8]->label->setGeometry(0,0,0,0);

    chess[9]->label->setPixmap(p13.scaled(60,60,Qt::KeepAspectRatio));
    chess[9]->label->setGeometry(0,0,0,0);

    chess[10]->label->setPixmap(p13.scaled(60,60,Qt::KeepAspectRatio));
    chess[10]->label->setGeometry(0,0,0,0);

    chess[11]->label->setPixmap(p14.scaled(60,60,Qt::KeepAspectRatio));
    chess[11]->label->setGeometry(0,0,0,0);

    chess[12]->label->setPixmap(p14.scaled(60,60,Qt::KeepAspectRatio));
    chess[12]->label->setGeometry(0,0,0,0);

    chess[13]->label->setPixmap(p14.scaled(60,60,Qt::KeepAspectRatio));
    chess[13]->label->setGeometry(0,0,0,0);

    chess[14]->label->setPixmap(p14.scaled(60,60,Qt::KeepAspectRatio));
    chess[14]->label->setGeometry(0,0,0,0);

    chess[15]->label->setPixmap(p14.scaled(60,60,Qt::KeepAspectRatio));
    chess[15]->label->setGeometry(0,0,0,0);

    chess[16]->label->setPixmap(p1.scaled(60,60,Qt::KeepAspectRatio));
    chess[16]->label->setGeometry(0,0,0,0);

    chess[17]->label->setPixmap(p2.scaled(60,60,Qt::KeepAspectRatio));
    chess[17]->label->setGeometry(0,0,0,0);

    chess[18]->label->setPixmap(p2.scaled(60,60,Qt::KeepAspectRatio));
    chess[18]->label->setGeometry(0,0,0,0);

    chess[19]->label->setPixmap(p3.scaled(60,60,Qt::KeepAspectRatio));
    chess[19]->label->setGeometry(0,0,0,0);

    chess[20]->label->setPixmap(p3.scaled(60,60,Qt::KeepAspectRatio));
    chess[20]->label->setGeometry(0,0,0,0);

    chess[21]->label->setPixmap(p4.scaled(60,60,Qt::KeepAspectRatio));
    chess[21]->label->setGeometry(0,0,0,0);

    chess[22]->label->setPixmap(p4.scaled(60,60,Qt::KeepAspectRatio));
    chess[22]->label->setGeometry(0,0,0,0);

    chess[23]->label->setPixmap(p5.scaled(60,60,Qt::KeepAspectRatio));
    chess[23]->label->setGeometry(0,0,0,0);

    chess[24]->label->setPixmap(p5.scaled(60,60,Qt::KeepAspectRatio));
    chess[24]->label->setGeometry(0,0,0,0);

    chess[25]->label->setPixmap(p6.scaled(60,60,Qt::KeepAspectRatio));
    chess[25]->label->setGeometry(0,0,0,0);

    chess[26]->label->setPixmap(p6.scaled(60,60,Qt::KeepAspectRatio));
    chess[26]->label->setGeometry(0,0,0,0);

    chess[27]->label->setPixmap(p7.scaled(60,60,Qt::KeepAspectRatio));
    chess[27]->label->setGeometry(0,0,0,0);

    chess[28]->label->setPixmap(p7.scaled(60,60,Qt::KeepAspectRatio));
    chess[28]->label->setGeometry(0,0,0,0);

    chess[29]->label->setPixmap(p7.scaled(60,60,Qt::KeepAspectRatio));
    chess[29]->label->setGeometry(0,0,0,0);

    chess[30]->label->setPixmap(p7.scaled(60,60,Qt::KeepAspectRatio));
    chess[30]->label->setGeometry(0,0,0,0);

    chess[31]->label->setPixmap(p7.scaled(60,60,Qt::KeepAspectRatio));
    chess[31]->label->setGeometry(0,0,0,0);
}

    setMouseTracking(true);

}

int MainWindow::getcolumn(int x)
{
    return (x-170)/80;
}

int MainWindow::getrow(int y)
{
    return (y+30)/80;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mousepoint->setText("("+QString::number(e->x())+", "+QString :: number(e->y())+")");
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{  
    //走棋(第二次點擊)or設定棋子位子
    if(e->button()==Qt::LeftButton&&mouse==true)
    {
        for(short i=0;i<90;++i)
        {
            move[i]->setGeometry(0,0,0,0);
        }
        int row = getrow(e->y());
        int column = getcolumn(e->x());
        select->setGeometry(0,0,0,0);
        //設定棋子位子
        if(settingmode)
        {
            if(row<1||row>10||column<1||column>9)
            {
                mouse=false;
                return;
            }
            if(insert)//插入棋子
            {
                for(short i=0;i<range;++i)
                {
                    if(chess[chesstype]->exist)
                    {
                        chesstype++;
                    }
                    else
                    {
                        break;
                    }
                    if(i==range-1)
                    {
                        mouse = false;
                        return;
                    }
                }
                //檢查目的地有沒有棋子
                for(short i=0;i<32;++i)
                {
                    if(chess[i]->row==row&&chess[i]->column==column)
                    {
                        mouse = false;
                        return;
                    }
                }
                chess[chesstype]->label->setGeometry(200+80*getcolumn(e->x())-30,80*getrow(e->y())-30,60,60);
                chess[chesstype]->row = row;
                chess[chesstype]->column = column;
                chess[chesstype]->exist=true;
                mouse=false;
                return;
            }
            else//移動盤面內的棋子
            {
                //檢查目的地有沒有棋子
                for(short i=0;i<32;++i)
                {
                    if(chess[i]->row==row&&chess[i]->column==column)
                    {
                        mouse = false;
                        return;
                    }
                }
                //檢查目的地是否在棋盤內
                if(row<1||row>10||column<1||column>9)
                {
                    mouse=false;
                    return;
                }
                chess[record]->label->setGeometry(200+80*getcolumn(e->x())-30,80*getrow(e->y())-30,60,60);
                chess[record]->row = row;
                chess[record]->column = column;
                mouse=false;
                return;
            }
        }

        //走棋
        //檢查走法是否有效
        if(!canmove(chess,chess[record],chess[record]->type,row,column))
        {
            mouse = false;
            return;
        }
        //檢查目的地有沒有棋子
        for(short i=0;i<32;++i)
        {
            short tmp = i;
            //如果是同色棋則重選
            if(chess[i]->row==row&&chess[i]->column==column&&chess[i]->redorblack==turn)
            {
                mouse = false;
                return;
            }
            //不同色棋則吃掉
            else if(chess[i]->row==row&&chess[i]->column==column&&chess[i]->redorblack==(!turn))
            {
                chess[tmp]->label->setGeometry(0,0,0,0);
                chess[tmp]->row = 0;
                chess[tmp]->column = 0;
                chess[tmp]->exist = false;
                chess[record]->label->setGeometry(200+80*getcolumn(e->x())-30,80*getrow(e->y())-30,60,60);
                chess[record]->row = row;
                chess[record]->column = column;
                mouse=false;
                turn=!turn;
                if(chess[0]->exist==false)
                {
                    massage->setText("紅方獲勝");
                    gameend = true;
                    return;
                }
                else if(chess[16]->exist==false)
                {
                    massage->setText("黑方獲勝");
                    gameend = true;
                    return;
                }
                else if(!turn)
                {
                    massage->setText("輪到黑方");
                }
                else if(turn)
                {
                    massage->setText("輪到紅方");
                }
                return;
            }
        }
        //檢查目的地是否在棋盤內
        if(row<1||row>10||column<1||column>9)
        {
            mouse=false;
            return;
        }
        mousepoint->setText("R("+QString::number(e->x())+", "+QString :: number(e->y())+")");
        chess[record]->label->setGeometry(200+80*getcolumn(e->x())-30,80*getrow(e->y())-30,60,60);
        chess[record]->row = row;
        chess[record]->column = column;
        mouse=false;
        turn=!turn;
        if(!turn)
        {
            massage->setText("輪到黑方");
        }
        else
        {
            massage->setText("輪到紅方");
        }
        return;
    }
    //移除棋子
    else if(e->button()==Qt::RightButton&&settingmode)
    {
        int row = getrow(e->y());
        int column = getcolumn(e->x());
        //選取為位置是否在棋盤內
        if(row<1||row>10||column<1||column>9)
        {
            return;
        }
        else if(abs(e->x()-(200+80*column))<20&&abs(e->y()-(80*row))<20)
        {
            //選取位置是否有棋子
            for(short i=0;i<32;++i)
            {
                if(chess[i]->row==row&&chess[i]->column==column)
                {
                    chess[i]->label->setGeometry(0,0,0,0);
                    chess[i]->row=0;
                    chess[i]->column=0;
                    chess[i]->exist=false;
                    return;
                }
            }
        }
        return;
    }
    //選棋(第一次點擊)
    else if(e->button()==Qt::LeftButton)
    {
        if(gameend)
        {
            return;
        }
        mouse=true;
        mousepoint->setText("R("+QString::number(e->x())+", "+QString :: number(e->y())+")");
        int row = getrow(e->y());
        int column = getcolumn(e->x());
        //選取要設定的棋子
        if(settingmode==true)
        {
            range=2;
            if(column>0||column<-1||row<4||row>10)//移動盤面內的棋子
            {
                if(abs(e->x()-(200+80*column))<20&&abs(e->y()-(80*row))<20)
                {
                    insert = false;
                    //選取位置是否有棋子
                    for(short i=0;i<32;++i)
                    {
                        if(chess[i]->row==row&&chess[i]->column==column)
                        {
                            record=i;
                            select->setGeometry(170+column*80,-30+row*80,60,60);
                            return;
                        }
                    }
                    mouse=false;
                    return;
                }
                mouse=false;
                return;
            }
            else if(abs(e->x()-(120+80*column))<20&&abs(e->y()-(80*row))<20)//插入棋子
            {
                insert = true;
                if(column==0)
                {
                    if(row==4)
                    {
                        range = 1;
                        chesstype = 0;
                    }
                    else if(row==5)
                    {
                        chesstype = 1;
                    }
                    else if(row==6)
                    {
                        chesstype = 3;
                    }
                    else if(row==7)
                    {
                        chesstype = 5;
                    }
                    else if(row==8)
                    {
                        chesstype = 7;
                    }
                    else if(row==9)
                    {
                        chesstype = 9;
                    }
                    else if(row==10)
                    {
                        range = 5;
                        chesstype =11;
                    }

                }
                else
                {
                    if(row==4)
                    {
                        range = 1;
                        chesstype = 16;
                    }
                    else if(row==5)
                    {
                        chesstype = 17;
                    }
                    else if(row==6)
                    {
                        chesstype = 19;
                    }
                    else if(row==7)
                    {
                        chesstype = 21;
                    }
                    else if(row==8)
                    {
                        chesstype = 23;
                    }
                    else if(row==9)
                    {
                        chesstype = 25;
                    }
                    else if(row==10)
                    {
                        range = 5;
                        chesstype =27;
                    }
                }
                select->setGeometry(90+column*80,-30+row*80,60,60);
                return;
            }
        }

        else if(row<1||row>10||column<1||column>9)
        {
            mouse=false;
            return;
        }
        //選取位置是否在棋盤內
        else if(abs(e->x()-(200+80*column))<20&&abs(e->y()-(80*row))<20)
        {
            //選取位置是否有棋子
            for(short i=0;i<32;++i)
            {
                if(chess[i]->row==row&&chess[i]->column==column)
                {
                    record=i;
                    //檢查輪到誰
                    if(turn!=chess[record]->redorblack)
                    {
                        mouse = false;
                        return;
                    }
                    select->setGeometry(170+column*80,-30+row*80,60,60);
                    canmove2(chess,chess[record],chess[record]->type,move);
                    return;
                }
            }
            mouse=false;
            return;
        }
        mouse=false;
        return;
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(Qt::black);
    QRect rect(260,60,680,760);
    painter.fillRect(rect,QColor(245,222,179));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(280,80,280,800);
    painter.drawLine(920,80,920,800);
    painter.drawLine(520,80,680,240);
    painter.drawLine(520,640,680,800);
    painter.drawLine(680,80,520,240);
    painter.drawLine(680,640,520,800);
    for(short i =0;i<10;++i)
    {
        painter.drawLine(280,80+80*i,920,80+80*i);
    }
    for(short i=1;i<8;++i)
    {
        painter.drawLine(280+80*i,80,280+80*i,400);
        painter.drawLine(280+80*i,480,280+80*i,800);
    }
    painter.setFont(QFont("楷体",40));
    painter.drawText(380,460,"楚河");
    painter.drawText(720,460,"漢界");
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawRect(260,60,680,760);
}


void MainWindow::settingmodeclicked()
{
    gameend=false;
    hasset=true;
    massage->setText("");
    if(settingmode==false)
    {
        settingmode = true;
        for(short i=0;i<14;i++)
        {
            if(i<7)
            {
                setchess[i]->setGeometry(10,290+80*i,60,60);
            }
            else
            {
                setchess[i]->setGeometry(90,290+80*(i-7),60,60);
            }
        }
    }
    else
    {
        settingmode = false;
        for(short i=0;i<14;++i)
        {
            setchess[i]->setGeometry(0,0,0,0);
        }
    }
}

void MainWindow::startgameclicked()
{
        gameend = false;
        massage->setText("輪到紅方");
        turn=true;
        if(hasset)
        {
            return;
        }

        chess[0]->label->setGeometry(570,50,60,60);
        chess[0]->row=chess[0]->getrow(50);
        chess[0]->column=chess[0]->getcolumn(570);
        chess[0]->redorblack=false;
        chess[0]->type = 11;
        chess[0]->exist =true;

        chess[1]->label->setGeometry(490,50,60,60);
        chess[1]->row=chess[1]->getrow(50);
        chess[1]->column=chess[1]->getcolumn(490);
        chess[1]->redorblack=false;
        chess[1]->type = 9;
        chess[1]->exist =true;

        chess[2]->label->setGeometry(650,50,60,60);
        chess[2]->row=chess[2]->getrow(50);
        chess[2]->column=chess[2]->getcolumn(650);
        chess[2]->redorblack=false;
        chess[2]->type = 9;
        chess[2]->exist =true;

        chess[3]->label->setGeometry(410,50,60,60);
        chess[3]->row=chess[3]->getrow(50);
        chess[3]->column=chess[3]->getcolumn(410);
        chess[3]->redorblack=false;
        chess[3]->type = 7;
        chess[3]->exist =true;

        chess[4]->label->setGeometry(730,50,60,60);
        chess[4]->row=chess[4]->getrow(50);
        chess[4]->column=chess[4]->getcolumn(730);
        chess[4]->redorblack=false;
        chess[4]->type = 7;
        chess[4]->exist =true;

        chess[5]->label->setGeometry(330,50,60,60);
        chess[5]->row=chess[5]->getrow(50);
        chess[5]->column=chess[5]->getcolumn(330);
        chess[5]->redorblack=false;
        chess[5]->type = 5;
        chess[5]->exist =true;

        chess[6]->label->setGeometry(810,50,60,60);
        chess[6]->row=chess[6]->getrow(50);
        chess[6]->column=chess[6]->getcolumn(810);
        chess[6]->redorblack=false;
        chess[6]->type = 5;
        chess[6]->exist =true;

        chess[7]->label->setGeometry(250,50,60,60);
        chess[7]->row=chess[7]->getrow(50);
        chess[7]->column=chess[7]->getcolumn(250);
        chess[7]->redorblack=false;
        chess[7]->type = 4;
        chess[7]->exist =true;

        chess[8]->label->setGeometry(890,50,60,60);
        chess[8]->row=chess[8]->getrow(50);
        chess[8]->column=chess[8]->getcolumn(890);
        chess[8]->redorblack=false;
        chess[8]->type = 4;
        chess[8]->exist =true;

        chess[9]->label->setGeometry(330,210,60,60);
        chess[9]->row=chess[9]->getrow(210);
        chess[9]->column=chess[9]->getcolumn(330);
        chess[9]->redorblack=false;
        chess[9]->type = 3;
        chess[9]->exist =true;

        chess[10]->label->setGeometry(810,210,60,60);
        chess[10]->row=chess[10]->getrow(210);
        chess[10]->column=chess[10]->getcolumn(810);
        chess[10]->redorblack=false;
        chess[10]->type = 3;
        chess[10]->exist =true;

        chess[11]->label->setGeometry(250,290,60,60);
        chess[11]->row=chess[11]->getrow(290);
        chess[11]->column=chess[11]->getcolumn(250);
        chess[11]->redorblack=false;
        chess[11]->type = 2;
        chess[11]->exist =true;

        chess[12]->label->setGeometry(410,290,60,60);
        chess[12]->row=chess[12]->getrow(290);
        chess[12]->column=chess[12]->getcolumn(410);
        chess[12]->redorblack=false;
        chess[12]->type = 2;
        chess[12]->exist =true;

        chess[13]->label->setGeometry(570,290,60,60);
        chess[13]->row=chess[13]->getrow(290);
        chess[13]->column=chess[13]->getcolumn(570);
        chess[13]->redorblack=false;
        chess[13]->type = 2;
        chess[13]->exist =true;

        chess[14]->label->setGeometry(730,290,60,60);
        chess[14]->row=chess[14]->getrow(290);
        chess[14]->column=chess[14]->getcolumn(730);
        chess[14]->redorblack=false;
        chess[14]->type = 2;
        chess[14]->exist =true;

        chess[15]->label->setGeometry(890,290,60,60);
        chess[15]->row=chess[15]->getrow(290);
        chess[15]->column=chess[15]->getcolumn(890);
        chess[15]->redorblack=false;
        chess[15]->type = 2;
        chess[15]->exist =true;

        chess[16]->label->setGeometry(570,770,60,60);
        chess[16]->row=chess[16]->getrow(770);
        chess[16]->column=chess[16]->getcolumn(570);
        chess[16]->redorblack=true;
        chess[16]->type = 10;
        chess[16]->exist =true;

        chess[17]->label->setGeometry(490,770,60,60);
        chess[17]->row=chess[17]->getrow(770);
        chess[17]->column=chess[17]->getcolumn(490);
        chess[17]->redorblack=true;
        chess[17]->type = 8;
        chess[17]->exist =true;

        chess[18]->label->setGeometry(650,770,60,60);
        chess[18]->row=chess[18]->getrow(770);
        chess[18]->column=chess[18]->getcolumn(650);
        chess[18]->redorblack=true;
        chess[18]->type = 8;
        chess[18]->exist =true;

        chess[19]->label->setGeometry(410,770,60,60);
        chess[19]->row=chess[19]->getrow(770);
        chess[19]->column=chess[19]->getcolumn(410);
        chess[19]->redorblack=true;
        chess[19]->type = 6;
        chess[19]->exist =true;

        chess[20]->label->setGeometry(730,770,60,60);
        chess[20]->row=chess[20]->getrow(770);
        chess[20]->column=chess[20]->getcolumn(730);
        chess[20]->redorblack=true;
        chess[20]->type = 6;
        chess[20]->exist =true;

        chess[21]->label->setGeometry(330,770,60,60);
        chess[21]->row=chess[21]->getrow(770);
        chess[21]->column=chess[21]->getcolumn(330);
        chess[21]->redorblack=true;
        chess[21]->type = 5;
        chess[21]->exist =true;

        chess[22]->label->setGeometry(810,770,60,60);
        chess[22]->row=chess[22]->getrow(770);
        chess[22]->column=chess[22]->getcolumn(810);
        chess[22]->redorblack=true;
        chess[22]->type = 5;
        chess[22]->exist =true;

        chess[23]->label->setGeometry(250,770,60,60);
        chess[23]->row=chess[23]->getrow(770);
        chess[23]->column=chess[23]->getcolumn(250);
        chess[23]->redorblack=true;
        chess[23]->type = 4;
        chess[23]->exist =true;

        chess[24]->label->setGeometry(890,770,60,60);
        chess[24]->row=chess[24]->getrow(770);
        chess[24]->column=chess[24]->getcolumn(890);
        chess[24]->redorblack=true;
        chess[24]->type = 4;
        chess[24]->exist =true;

        chess[25]->label->setGeometry(330,610,60,60);
        chess[25]->row=chess[25]->getrow(610);
        chess[25]->column=chess[25]->getcolumn(330);
        chess[25]->redorblack=true;
        chess[25]->type = 3;
        chess[25]->exist =true;

        chess[26]->label->setGeometry(810,610,60,60);
        chess[26]->row=chess[26]->getrow(610);
        chess[26]->column=chess[26]->getcolumn(810);
        chess[26]->redorblack=true;
        chess[26]->type = 3;
        chess[26]->exist =true;

        chess[27]->label->setGeometry(250,530,60,60);
        chess[27]->row=chess[27]->getrow(530);
        chess[27]->column=chess[27]->getcolumn(250);
        chess[27]->redorblack=true;
        chess[27]->type = 1;
        chess[27]->exist =true;

        chess[28]->label->setGeometry(410,530,60,60);
        chess[28]->row=chess[28]->getrow(530);
        chess[28]->column=chess[28]->getcolumn(410);
        chess[28]->redorblack=true;
        chess[28]->type = 1;
        chess[28]->exist =true;

        chess[29]->label->setGeometry(570,530,60,60);
        chess[29]->row=chess[29]->getrow(530);
        chess[29]->column=chess[29]->getcolumn(570);
        chess[29]->redorblack=true;
        chess[29]->type = 1;
        chess[29]->exist =true;

        chess[30]->label->setGeometry(730,530,60,60);
        chess[30]->row=chess[30]->getrow(530);
        chess[30]->column=chess[30]->getcolumn(730);
        chess[30]->redorblack=true;
        chess[30]->type = 1;
        chess[30]->exist =true;

        chess[31]->label->setGeometry(890,530,60,60);
        chess[31]->row=chess[31]->getrow(530);
        chess[31]->column=chess[31]->getcolumn(890);
        chess[31]->redorblack=true;
        chess[31]->type = 1;
        chess[31]->exist =true;
}

void MainWindow::restartclicked()
{
    hasset=false;
    massage->setText("");
    for(short i=0;i<32;++i)
    {
        chess[i]->label->setGeometry(0,0,0,0);
        chess[i]->row=0;
        chess[i]->column=0;
        chess[i]->exist=false;
    }
}
