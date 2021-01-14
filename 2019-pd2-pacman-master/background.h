#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QGraphicsItem>
#include <QPainter>

class Background : public QGraphicsItem
{
public:
    Background();
 QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

};

#endif // BACKGROUND_H
