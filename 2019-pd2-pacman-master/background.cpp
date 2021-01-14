#include "background.h"

Background::Background()
{

}

QRectF Background::boundingRect() const
{
        return QRectF(0,0,1758,698);
}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    painter->fillRect(rec,Qt::black);
}
