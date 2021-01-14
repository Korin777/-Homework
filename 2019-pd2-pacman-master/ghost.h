#ifndef GHOST_H
#define GHOST_H
#include "movableitem.h"

class Ghost : public movableitem
{
public:
    Ghost();
    QPixmap ghostleft,ghostright,ghostup,ghostdown,ghostafraid;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    QRectF boundingRect() const;
    virtual void move();

    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool beeaten = false;
    bool Ghostafraid = false;
    bool moveleft,moveright,moveup,movedown;
    void restrict();
    bool decide();
};

#endif // GHOST_H
