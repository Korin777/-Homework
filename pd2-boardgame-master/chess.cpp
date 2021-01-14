#include "chess.h"
//#include "mainwindow.h"
Chess::Chess()
{

}

int Chess::getcolumn(int x)
{
    return (x-170)/80;
}

int Chess::getrow(int y)
{
    return (y+30)/80;
}


bool isplaced(QVector<Chess*> chess,int row,int column)
{
    for(short i=0;i<32;++i)
    {
        if(chess[i]->row==row&&chess[i]->column==column)
        {
            return true;
        }
    }
    return false;
}

int haschess(QVector<Chess*> chess,int row1,int column1,int row2,int column2)
{
    int sum=-1;
    if(row1>row2)
    {
        int tmp=row1;
        row1=row2;
        row2=tmp;
    }
    if(column1>column2)
    {
        int tmp=column1;
        column1=column2;
        column2=tmp;
    }
    for(int row=row1;row<=row2;++row)
    {
        for(int column=column1;column<=column2;++column)
        {
            for(short i=0;i<32;++i)
            {
                if(chess[i]->row==row&&chess[i]->column==column)
                {
                    ++sum;
                }
            }
        }
    }
    return sum;
}

bool canmove(QVector<Chess*> chesst,Chess *chess,int type,int row,int column)
{
    int drow =abs(chess->row-row);
    int dcolumn=abs(chess->column-column);
    if(type==1)//兵走法
    {
        if(chess->row>5)
        {
            if(chess->row-row==1&&column-chess->column==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if((abs(chess->row-row)+abs(chess->column-column))==1&&(chess->row-row)!=-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(type==2)//卒走法
    {
        if(chess->row<6)
        {
            if(row-chess->row==1&&column-chess->column==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if((abs(chess->row-row)+abs(chess->column-column))==1&&(chess->row-row)!=1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(type==3)//包&炮走法
    {
        if(((drow==0&&dcolumn!=0)||(drow!=0&&dcolumn==0))&&((haschess(chesst,chess->row,chess->column,row,column)==0)||(haschess(chesst,chess->row,chess->column,row
                                                                                                                                  ,column)==2&&isplaced(chesst,row,column))))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type==4)//車走法
    {
        if(((drow==0&&dcolumn!=0)||(drow!=0&&dcolumn==0))&&(haschess(chesst,chess->row,chess->column,row,column)==0||(haschess(chesst,chess->row,chess->column,row,column)==1&&isplaced(chesst,row,column))))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type==5)//馬走法
    {
        int trow = chess->row - row;
        int tcolumn = chess->column - column;
        if(trow==2||trow==-2)
        {
            trow = trow/2;
        }
        else
        {
            tcolumn = tcolumn/2;
        }
        if((drow+dcolumn==3)&&drow<3&&dcolumn<3&&!isplaced(chesst,row+trow,column+tcolumn))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type==6)//相走法
    {
        int trow=(chess->row-row)/2;
        int tcolumn=(chess->column-column)/2;
        if((drow==2&&dcolumn==2)&&!isplaced(chesst,row+trow,column+tcolumn)&&row>5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type==7)//象走法
    {
        int trow=(chess->row-row)/2;
        int tcolumn=(chess->column-column)/2;
        if((drow==2&&dcolumn==2)&&!isplaced(chesst,row+trow,column+tcolumn)&&row<6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type==8)//仕走法
    {
        if(drow==1&&dcolumn==1&&row>7&&column<7&&column>3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type==9)//士走法
    {
        if(drow==1&&dcolumn==1&&row<4&&column<7&&column>3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type==10)//帥走法
    {
        if((drow+dcolumn==1)&&row>7&&column<7&&column>3&&!(haschess(chesst,chess->row,column,chesst[0]->row,column)==0&&chesst[0]->column==column))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(type==11)//將走法
    {
        if((drow+dcolumn==1)&&row<4&&column<7&&column>3&&!(haschess(chesst,chess->row,column,chesst[16]->row,column)==0&&chesst[16]->column==column))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool canmove2(QVector<Chess*> chesst,Chess *chess,int type,QLabel *move[])
{
    for(int i=0;i<90;++i)
    {
        int row=i/9+1;
        int column=i%9+1;
        int drow =abs(chess->row-row);
        int dcolumn=abs(chess->column-column);
        bool check = true;
    if(type==1)//兵走法
    {
        if(chess->row>5)
        {
            if(chess->row-row==1&&column-chess->column==0)
            {
                for(short i=0;i<32;++i)
                {
                    //如果是同色棋則重選
                    if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
                }
            }
        }
        else
        {
            if((abs(chess->row-row)+abs(chess->column-column))==1&&(chess->row-row)!=-1)
            {
                for(short i=0;i<32;++i)
                {
                    //如果是同色棋則重選
                    if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
                }
            }
        }
    }
    else if(type==2)//卒走法
    {
        if(chess->row<6)
        {
            if(row-chess->row==1&&column-chess->column==0)
            {
                for(short i=0;i<32;++i)
                {
                    //如果是同色棋則重選
                    if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
                }
            }
        }
        else
        {
            if((abs(chess->row-row)+abs(chess->column-column))==1&&(chess->row-row)!=1)
            {
                for(short i=0;i<32;++i)
                {
                    //如果是同色棋則重選
                    if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
                }
            }
        }
    }
    else if(type==3)//包&炮走法
    {
        if(((drow==0&&dcolumn!=0)||(drow!=0&&dcolumn==0))&&((haschess(chesst,chess->row,chess->column,row,column)==0)||(haschess(chesst,chess->row,chess->column,row
                                                                                                                                  ,column)==2&&isplaced(chesst,row,column))))
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    else if(type==4)//車走法
    {
        if(((drow==0&&dcolumn!=0)||(drow!=0&&dcolumn==0))&&(haschess(chesst,chess->row,chess->column,row,column)==0||(haschess(chesst,chess->row,chess->column,row,column)==1&&isplaced(chesst,row,column))))
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    else if(type==5)//馬走法
    {
        int trow = chess->row - row;
        int tcolumn = chess->column - column;
        if(trow==2||trow==-2)
        {
            trow = trow/2;
        }
        else
        {
            tcolumn = tcolumn/2;
        }
        if((drow+dcolumn==3)&&drow<3&&dcolumn<3&&!isplaced(chesst,row+trow,column+tcolumn))
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    else if(type==6)//相走法
    {
        int trow=(chess->row-row)/2;
        int tcolumn=(chess->column-column)/2;
        if((drow==2&&dcolumn==2)&&!isplaced(chesst,row+trow,column+tcolumn)&&row>5)
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    else if(type==7)//象走法
    {
        int trow=(chess->row-row)/2;
        int tcolumn=(chess->column-column)/2;
        if((drow==2&&dcolumn==2)&&!isplaced(chesst,row+trow,column+tcolumn)&&row<6)
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    else if(type==8)//仕走法
    {
        if(drow==1&&dcolumn==1&&row>7&&column<7&&column>3)
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    else if(type==9)//士走法
    {
        if(drow==1&&dcolumn==1&&row<4&&column<7&&column>3)
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    else if(type==10)//帥走法
    {
        if((drow+dcolumn==1)&&row>7&&column<7&&column>3&&!(haschess(chesst,chess->row,column,chesst[0]->row,column)==0&&chesst[0]->column==column))
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    else if(type==11)//將走法
    {
        if((drow+dcolumn==1)&&row<4&&column<7&&column>3&&!(haschess(chesst,chess->row,column,chesst[16]->row,column)==0&&chesst[16]->column==column))
        {
            for(short i=0;i<32;++i)
            {
                //如果是同色棋則重選
                if(chesst[i]->row==row&&chesst[i]->column==column&&chesst[i]->redorblack==chess->redorblack)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                move[(row-1)*9+column]->setGeometry(170+column*80,-30+row*80,60,60);
            }
        }
    }
    }
    return true;
}

