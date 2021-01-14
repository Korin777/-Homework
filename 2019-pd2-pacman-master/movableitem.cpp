#include "movableitem.h"
#include <QtDebug>
#include "mainwindow.h"


movableitem::movableitem()
{

}

QRectF movableitem::boundingRect() const
{
    return QRectF(0,0,60,60);
}

void movableitem::restrict()
{

}

void movableitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void movableitem::move()
{
}


