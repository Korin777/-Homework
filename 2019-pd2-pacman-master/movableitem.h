#ifndef MOVABLEITEM_H
#define MOVABLEITEM_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QtDebug>



class movableitem : public QGraphicsItem
{
public:
    movableitem();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    int speedx,speedy;

    virtual void restrict();
    virtual void move();




};

#endif // MOVABLEITEM_H
