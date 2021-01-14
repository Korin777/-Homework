#ifndef POWERBALL_H
#define POWERBALL_H
#include <QPixmap>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>


class PowerBall : public QGraphicsItem
{
public:
    PowerBall();
    QPixmap powerballpix;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    QRectF boundingRect() const;
};

#endif // POWERBALL_H
