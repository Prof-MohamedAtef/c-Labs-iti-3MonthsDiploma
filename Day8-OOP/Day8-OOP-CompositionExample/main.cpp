#include <iostream>
#include <graphics.h>

using namespace std;


class Shape
{
protected:
    int Color;

public:
    Shape()
    {
        Color = 15;  ///White
    }
    Shape(int c)
    {
        Color = c;
    }
    void setCOLOR(int c)
    {
        Color = c;
    }
    int getCOLOR(){
        return Color;
    }

    virtual void Draw() = 0;  ///Pure Virtual Function
};

class Point
{
    int X;
    int Y;

public:
    Point()
    {
        X = Y = 0;
    }
    Point(int L)
    {
        X = Y = L;
    }
    Point(int L, int M)
    {
        X = L;
        Y = M;
    }
    void setX(int L)
    {
        X = L;
    }
    int getX()
    {
        return X;
    }
    void setY(int M)
    {
        Y = M;
    }
    int getY()
    {
        return Y;
    }
};


class Line:public Shape
{
    Point Start; ///x,y
    Point End;  ///x,y

public:
    Line()///:Start(), End()
    {
        Start.setX(0);
        Start.setY(0);

        End.setX(0);
        End.setY(0);
    }

    Line(int x1, int y1, int x2, int y2, int c):Start(x1, y1), End(x2, y2)
    {
        setCOLOR(c);
        /*
        Start.setX(x1);
        Start.setY(y1);

        End.setX(x2);
        End.setY(y2);
        */
    }

    Line (Point P1, Point P2, int c)//:Start(P1.getX(), P1.getY()), End(P2.getX(), P2.getY())
    {
        Start.setX(P1.getX());
        Start.setY(P1.getY());

        End.setX(P2.getX());
        End.setY(P2.getY());

        setCOLOR(c);
    }

    void Draw()
    {
        setcolor(Color);
        line(Start.getX(), Start.getY() , End.getX(), End.getY() );
    }
};

class Rect:public Shape
{
    Point UL; ///x,y
    Point LR;  ///x,y

public:
    Rect():UL(), LR()
    {

    }

    Rect(int x1, int y1, int x2, int y2, int c):UL(x1, y1), LR(x2, y2)
    {
        setCOLOR(c);
        /*
        Start.setX(x1);
        Start.setY(y1);

        End.setX(x2);
        End.setY(y2);
        */
    }

    Rect (Point P1, Point P2, int c)//:Start(P1.getX(), P1.getY()), End(P2.getX(), P2.getY())
    {
        UL.setX(P1.getX());
        UL.setY(P1.getY());

        LR.setX(P2.getX());
        LR.setY(P2.getY());

        setCOLOR(c);
    }

    void Draw()
    {
        setCOLOR(Color);
        Rect rectangle(UL.getX(), UL.getY() , LR.getX(), LR.getY() , Color);
    }
};


class Circle:public Shape
{
    Point Center; ///x,y
    int Rad;

public:
    Circle():Center()
    {
        Rad = 10;
    }

    Circle(int x1, int y1, int r, int c):Center(x1, y1)
    {
        Rad = r;
        setCOLOR(c);
    }

    Circle (Point P1, int r, int c)//:Start(P1.getX(), P1.getY()), End(P2.getX(), P2.getY())
    {
        Center.setX(P1.getX());
        Center.setY(P1.getY());

        Rad = r;
        setCOLOR(c);
    }

    void Draw()
    {
        setCOLOR(Color);
        Circle circle(Center.getX(), Center.getY() , Rad , Color);
    }
};

class Picture
{
    Rect* pRect;
    Line* pLine;
    Circle* pCircle;

    int cNum;
    int rNum;
    int lNum;

public:

    Picture()
    {
        pRect = NULL;
        pLine = NULL;
        pCircle = NULL;
        cNum = rNum = lNum = 0;
    }

    Picture(Rect* rPtr, Circle* cPtr, Line* lPtr, int rN, int cN, int lN)
    {
        pRect = rPtr;
        pLine = lPtr;
        pCircle = cPtr;

        cNum = cN;
        rNum = rN;
        lNum = lN;
    }

    void setCircles(Circle* pCir, int cN)
    {
        pCircle = pCir;
        cNum = cN;
    }

    void setRects(Rect* pR, int rN)
    {
        pRect = pR;
        rNum = rN;
    }

    void setLines(Line* lR, int lN)
    {
        pLine = lR;
        lNum = lN;
    }

    void Paint()
    {
        for(int i=0; i<cNum; i++)
            pCircle[i].Draw();

        for(int i=0; i<rNum; i++)
            pRect[i].Draw();

        for(int i=0; i<lNum; i++)
            pLine[i].Draw();
    }
};

int main()
{
    initwindow(400, 400);  ///graphics window


    Rect* rePtr;
    Circle* ciPtr;

    /*
    picture 1
    */

    Picture myPic;   ///Picture Object

        ///Shapes
    Line lnArr[2] = { Line(10, 20, 50, 100, 2), Line (30,40, 100, 150, 3)};

    Rect recArr[2] = { Rect(50, 100, 200, 300, 4), Rect(80, 90, 100, 300, 5) };

    Circle cR (100, 200, 50, 6);

        ///Setting Shapes to Picture

    myPic.setCircles(&cR, 1);
    myPic.setLines(lnArr, 2);
    myPic.setRects(recArr, 2);

    ///Call Pic paint to draw shapes
    myPic.Paint();

    Line L(300, 80, 200, 400, 4);
    L.Draw();

    Rect R(50, 100, 200, 300, 6);
    R.Draw();

    Circle C(100, 200, 50, 2);
    C.Draw();

    ///then use the pointer of base class to call the draw( ) function of Circle, Rect, and Line.
    Shape* shPtr;
    shPtr= new Circle();
    shPtr->Draw();

    shPtr= new Rect();
    shPtr->Draw();

    shPtr= new Line();
    shPtr->Draw();

    getch();
    closegraph();

    return 0;
}
