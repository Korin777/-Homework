#ifndef PACMAN_H
#define PACMAN_H
#include "movableitem.h"


class Pacman : public movableitem
{
public:
    Pacman();
    QPixmap pacleft1,pacleft2,pacleft3,pacright1,pacright2,pacright3,pacup1,pacup2,pacup3,pacdown1,pacdown2,pacdown3;

    virtual void move();
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

    int change = 0;

    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool eatghost = false;
    bool moveleft,moveright,moveup,movedown;

    virtual void restrict();
//
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

};

#endif // PACMAN_H
