#include "powerball.h"

PowerBall::PowerBall()
{
    powerballpix.load(":/img/PowerBall.png");
}

void PowerBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,40,40,powerballpix.scaled(60,60,Qt::KeepAspectRatio));
}

QRectF PowerBall::boundingRect() const
{
    return QRectF(0,0,40,40);
}

