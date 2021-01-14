#include "pacman.h"
#include <QDebug>

Pacman::Pacman()
{
    speedx = 5;
    speedy = 0;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    pacleft1.load(":/img/newpacmanleft1 1st.png");
    pacleft2.load(":/img/newpacmanleft2 2nd.png");
    pacleft3.load(":/img/newpacmanleft3 3rd.png");
    pacright1.load(":/img/newpacmanright1 1st.png");
    pacright2.load(":/img/newpacmanright2 2nd.png");
    pacright3.load(":/img/newpacmanright3 3rd.png");
    pacup1.load(":/img/newpacmanup1 1st.png");
    pacup2.load(":/img/newpacmanup2 2nd.png");
    pacup3.load(":/img/newpacmanup3 3rd.png");
    pacdown1.load(":/img/newpacmandown1 1st.png");
    pacdown2.load(":/img/newpacmandown2 2nd.png");
    pacdown3.load(":/img/newpacmandown3 3rd.png");
    setPos(855,430);
}

void Pacman::restrict()
{
    //四邊
    if(y()<=100)
    {
        speedy = 0;
        moveup = false;
    }
    if(y()>=540)
    {
        speedy = 0;
        movedown = false;
    }
    if(x()<=140)
    {
        speedx = 0;
        moveleft = false;
    }
    if(x()>=1560)
    {
        speedx = 0;
        moveright = false;
    }

    //左側兩長方形
    if((y()==100||y()==430)&&x()>140&&x()<300)
    {
        speedy = 0;
        movedown = false;
    }
    if((y()==210||y()==540)&&x()>140&&x()<300)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==140&&((y()>100&&y()<210)||(y()>430&&y()<540)))
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==300&&((y()>100&&y()<210)||(y()>430&&y()<540)))
    {
        speedx = 0;
        moveleft = false;
    }
    //左側水平線
    if(y()==210&&x()>=140&&x()<300)
    {
        speedy = 0;
        movedown = false;
    }
    if(y()==320&&x()>=140&&x()<300)
    {
        speedy = 0;
        movedown = false;
        moveup = false;
    }
    if(y()==430&&x()>=140&&x()<300)
    {
        speedy = 0;
        moveup = false;
    }
    //左側垂直線
    if(x()==300&&((y()>210&&y()<320)||(y()>320&&y()<430)))
    {
        speedx = 0;
        moveleft = 0;
    }
    //G字形
    if(y()==100&&x()>300&&x()<620)
    {
        speedy = 0;
        movedown =false;
    }
    if(x()==620&&((y()>100&&y()<205)||(y()>205&&y()<430)))
    {
        speedx = 0;
        moveleft = false;
    }
    if(y()==430&&x()>300&&x()<620)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==300&&y()>100&&y()<430)
    {
        speedx = 0;
        moveright =false;
    }
    if(y()==205&&x()>360&&x()<620)
    {
        speedy = 0;
        moveup = 0;
    }
    if(y()==205&&x()>420&&x()<620)
    {
        speedy = 0;
        movedown = false;
    }
    if(y()==325&&x()>420&&x()<560)
    {
        speedy = 0;
        moveup = false;
    }
    if(y()==325&&x()>360&&x()<560)
    {
        speedy = 0;
        movedown = false;
    }
    if(x()==420&&y()>145&&y()<385)
    {
        speedx = 0;
        moveleft = false;
    }
    if(x()==420&&y()>205&&y()<325)
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==480&&y()>265&&y()<385)
    {
        speedx = 0;
        moveright =false;
    }
    //G下面長條
    if(y()==430&&x()>300&&x()<600)
    {
        speedy = 0;
        movedown = false;
    }

    if(y()==540&&x()>300&&x()<600)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==300&&y()>430&&y()<540)
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==600&&y()>430&&y()<540)
    {
        speedx = 0;
        moveleft = false;
    }
    //下面突起物
    if((x()==600||x()==1010)&&y()>430&&y()<600)
    {
        speedx = 0;
        moveright = false;
    }
    if((x()==710||x()==1120)&&y()>430&&y()<600)
    {
        speedx = 0;
        moveleft = false;
    }
    if(y()==430&&((x()>600&&x()<710)||(x()>1010&&x()<1120)))
    {
        speedy = 0;
        movedown =false;
    }
    //兩大矩形
    if(y()==210&&((x()>620&&x()<855)||(x()>855&&x()<1200)))
    {
        speedy = 0;
        movedown =false;
    }
    if(y()==430&&((x()>620&&x()<855)||(x()>855&&x()<1200)))
    {
        speedy = 0;
        moveup =false;
    }
    if((x()==620||x()==855)&&y()>210&&y()<430)
    {
        speedx = 0;
        moveright = false;
    }
    if((x()==855||x()==1200)&&y()>210&&y()<430)
    {
        speedx = 0;
        moveleft = false;
    }
    //矩形上長條
    if(y()==100&&x()>620&&x()<1200)
    {
        speedy = 0;
        movedown = false;
    }

    if(y()==210&&x()>620&&x()<1200)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==620&&y()>100&&y()<210)
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==1200&&y()>100&&y()<210)
    {
        speedx = 0;
        moveleft = false;
    }
    //矩形下長條
    if(y()==430&&x()>710&&x()<1010)
    {
        speedy = 0;
        movedown = false;
    }

    if(y()==540&&x()>710&&x()<1010)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==710&&y()>430&&y()<540)
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==1010&&y()>430&&y()<540)
    {
        speedx = 0;
        moveleft = false;
    }
    //右側長方形
    if(y()==100&&x()>1200&&x()<1460)
    {
        speedy = 0;
        movedown = false;
    }

    if(y()==430&&x()>1200&&x()<1460)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==1200&&y()>100&&y()<430)
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==1460&&y()>100&&y()<430)
    {
        speedx = 0;
        moveleft = false;
    }
    //長方形下長條
    if(y()==430&&x()>1120&&x()<1420)
    {
        speedy = 0;
        movedown = false;
    }

    if(y()==540&&x()>1120&&x()<1420)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==1120&&y()>430&&y()<540)
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==1420&&y()>430&&y()<540)
    {
        speedx = 0;
        moveleft = false;
    }
    //右側兩長條
    if(y()==100&&x()>1460&&x()<1560)
    {
        speedy = 0;
        movedown = false;
    }

    if(y()==210&&x()>1460&&x()<1560)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==1460&&y()>100&&y()<210)
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==1560&&y()>100&&y()<210)
    {
        speedx = 0;
        moveleft = false;
    }
    if(y()==430&&x()>1420&&x()<1560)
    {
        speedy = 0;
        movedown = false;
    }

    if(y()==540&&x()>1420&&x()<1560)
    {
        speedy = 0;
        moveup = false;
    }
    if(x()==1420&&y()>430&&y()<540)
    {
        speedx = 0;
        moveright = false;
    }
    if(x()==1560&&y()>430&&y()<540)
    {
        speedx = 0;
        moveleft = false;
    }
    //右側水平線
    if(y()==210&&x()>1460&&x()<1620)
    {
        speedy = 0;
        movedown = false;
    }
    if(y()==320&&x()>1460&&x()<1620)
    {
        speedy = 0;
        movedown = false;
        moveup = false;
    }
    if(y()==430&&x()>1460&&x()<1620)
    {
        speedy = 0;
        moveup = false;
    }
    //右側垂直線
    if(x()==1460&&((y()>210&&y()<320)||(y()>320&&y()<430)))
    {
        speedx = 0;
        moveright = 0;
    }
}
void Pacman::move()
{
    setPos(this->x()+speedx,this->y()+speedy);
    change++;
    if(change>3)
    {
        change = 0;
    }
}

QRectF Pacman::boundingRect() const
{
    return QRectF(0,0,60,60);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    moveleft = true;
    moveright = true;
    moveup = true;
    movedown = true;
    restrict();
    if(left)
    {
        if(change%3==1)
            painter->drawPixmap(0,0,60,60,pacleft1.scaled(60,60,Qt::KeepAspectRatio));
        else if(change%3==2)
        {
            painter->drawPixmap(0,0,60,60,pacleft2.scaled(60,60,Qt::KeepAspectRatio));
        }
        else if(change%3==0)
        {
            painter->drawPixmap(0,0,60,60,pacleft3.scaled(60,60,Qt::KeepAspectRatio));
        }

    }
    else if(right)
    {
        if(change%3==1)
            painter->drawPixmap(0,0,60,60,pacright1.scaled(60,60,Qt::KeepAspectRatio));
        else if(change%3==2)
        {
            painter->drawPixmap(0,0,60,60,pacright2.scaled(60,60,Qt::KeepAspectRatio));
        }
        else if(change%3==0)
        {
            painter->drawPixmap(0,0,60,60,pacright3.scaled(60,60,Qt::KeepAspectRatio));
        }
    }
    else if(up)
    {
        if(change%3==1)
            painter->drawPixmap(0,0,60,60,pacup1.scaled(60,60,Qt::KeepAspectRatio));
        else if(change%3==2)
        {
            painter->drawPixmap(0,0,60,60,pacup2.scaled(60,60,Qt::KeepAspectRatio));
        }
        else if(change%3==0)
        {
            painter->drawPixmap(0,0,60,60,pacup3.scaled(60,60,Qt::KeepAspectRatio));
        }
    }
    else if(down)
    {
        if(change%3==1)
            painter->drawPixmap(0,0,60,60,pacdown1.scaled(60,60,Qt::KeepAspectRatio));
        else if(change%3==2)
        {
            painter->drawPixmap(0,0,60,60,pacdown2.scaled(60,60,Qt::KeepAspectRatio));
        }
        else if(change%3==0)
        {
            painter->drawPixmap(0,0,60,60,pacdown3.scaled(60,60,Qt::KeepAspectRatio));
        }
    }
    else
    {
        if(change%3==1)
            painter->drawPixmap(0,0,60,60,pacright1.scaled(60,60,Qt::KeepAspectRatio));
        else if(change%3==2)
        {
            painter->drawPixmap(0,0,60,60,pacright2.scaled(60,60,Qt::KeepAspectRatio));
        }
        else if(change%3==0)
        {
            painter->drawPixmap(0,0,60,60,pacright3.scaled(60,60,Qt::KeepAspectRatio));
        }
    }
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    if(moveleft&&event->key() == Qt::Key_Left)
    {
        left = true;
        right = false;
        up = false;
        down = false;
        speedx = -5;
        speedy = 0;
    }
    else if(moveright&&event->key() == Qt::Key_Right)
    {
        left = false;
        right = true;
        up = false;
        down = false;
        speedx = 5;
        speedy = 0;
    }
    else if(moveup&&event->key() == Qt::Key_Up)
    {
        left = false;
        right = false;
        up = true;
        down = false;
        speedx = 0;
        speedy = -5;
    }
    else if(movedown&&event->key() == Qt::Key_Down)
    {
        left = false;
        right = false;
        up = false;
        down = true;
        speedx = 0;
        speedy = 5;
    }
}

void Pacman::keyReleaseEvent(QKeyEvent *event)
{
    if(moveleft&&event->key() == Qt::Key_Left)
    {
        left = true;
        right = false;
        up = false;
        down = false;
        speedx = -5;
        speedy = 0;
    }
    else if(moveright&&event->key() == Qt::Key_Right)
    {
        left = false;
        right = true;
        up = false;
        down = false;
        speedx = 5;
        speedy = 0;
    }
    else if(moveup&&event->key() == Qt::Key_Up)
    {
        left = false;
        right = false;
        up = true;
        down = false;
        speedx = 0;
        speedy = -5;
    }
    else if(movedown&&event->key() == Qt::Key_Down)
    {
        left = false;
        right = false;
        up = false;
        down = true;
        speedx = 0;
        speedy = 5;
    }
}
