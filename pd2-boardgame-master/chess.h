#ifndef CHESS_H
#define CHESS_H
#include <QLabel>
#include <cmath>



class Chess
{
public:
    Chess();
    QLabel *label;
    int column;
    int row;
    int type;

    bool redorblack;
    bool exist=false;

    int getcolumn(int x);
    int getrow(int y);
    friend bool canmove(QVector<Chess*> chesst,Chess *chess1,int type,int row,int column);
    friend bool canmove2(QVector<Chess*> chesst,Chess *chess,int type,QLabel *move[]);

};



#endif // CHESS_H
