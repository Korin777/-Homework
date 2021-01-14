#include "ghost.h"
Ghost::Ghost()
{
    speedx = 5;
    speedy = 0;

}

void Ghost::restrict()
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
        moveleft = false;
    }
    //G字形
    if(y()==100&&x()>300&&x()<620)
    {
        speedy = 0;
        movedown =false;
    }
    //if(x()==620&&((y()>100&&y()<205)||(y()>205&&y()<430)))
    if(x()==620&&y()>100&&y()<430)
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
        moveright = false;
    }
}

void Ghost::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(beeaten)
    {

    }
    else if(Ghostafraid)
    {
        painter->drawPixmap(0,0,80,80,ghostafraid.scaled(80,80,Qt::KeepAspectRatio));
    }
    else
    {
    if(left)
    {
        painter->drawPixmap(0,0,80,80,ghostleft.scaled(80,80,Qt::KeepAspectRatio));
    }
    else if(right)
    {
        painter->drawPixmap(0,0,80,80,ghostright.scaled(80,80,Qt::KeepAspectRatio));
    }
    else if(up)
    {
        painter->drawPixmap(0,0,80,80,ghostup.scaled(80,80,Qt::KeepAspectRatio));
    }
    else if(down)
    {
        painter->drawPixmap(0,0,80,80,ghostdown.scaled(80,80,Qt::KeepAspectRatio));
    }
    }
}

QRectF Ghost::boundingRect() const
{
    return QRectF(-10,-10,80,80);
}

void Ghost::move()
{
    setPos(this->x()+speedx,this->y()+speedy);
}

bool Ghost::decide()
{
    if((x()==140&&y()==100)||(x()==140&&y()==210)||(x()==300&&y()==100)||(x()==300&&y()==210)||(x()==300&&y()==430)||(x()==140&&y()==430)||(x()==140&&y()==540)||(x()==300&&y()==540)||(x()==620&&y()==100)||(x()==620&&y()==210)||(x()==620&&y()==430)||(x()==600&&y()==430)||(x()==600&&y()==540)||(x()==855&&y()==210)||(x()==1200&&y()==210)||(x()==1200&&y()==100)||(x()==710&&y()==430)||(x()==710&&y()==540)||(x()==1010&&y()==430)||(x()==1010&&y()==540)||(x()==1200&&y()==430)||(x()==1120&&y()==430)||(x()==1120&&y()==540)||(x()==1420&&y()==430)||(x()==1420&&y()==540)||(x()==1460&&y()==100)||(x()==1460&&y()==210)||(x()==1560&&y()==100)||(x()==1560&&y()==210)||(x()==1560&&y()==430)||(x()==1560&&y()==540)||(x()==855&&y()==430)||(x()==1460&&y()==430))
        return true;
    else
    {
        return  false;
    }
}
