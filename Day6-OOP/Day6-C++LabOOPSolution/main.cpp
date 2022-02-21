#include <iostream>

using namespace std;

class Father{

    int X;
protected:
    int Y;

public:
    Father(){
        X=Y=0;
        cout<<"\n Parameterless Father Ctor";
    }

    Father(int _x,int _y){
        X = _x;
        Y = _y;
        cout<<"\n Parameterized Father Ctor";
    }


    ~Father()
    {
        cout<<"\n Father Destructor";
    }


    int getX() { return X; }
    void setX(int _x){ X = _x; }

    int getY() { return Y; }
    void setY(int _y){ Y = _y; }

    int Sum()
    {
        return X + Y;
    }

};

class Son : public Father{

    int Z;

public:
    Son() /// :Parent()
    {
        Z = 0;
        cout<<"\n Parameterless Son Ctor";
    }

    Son(int _x,int _y, int _z) : Father(_x, _y)
    {
        Z = _z;
        cout<<"\n Parameterized Son Ctor";
    }

    int getZ() { return Z; }
    void setZ(int _z){ Z = _z; }

    ~Son()
    {
        cout<<"\n Son Destructor";
    }

    int Sum()
    {
        return getX() + getY() + Z;
    }

};

int main()
{
    Father f(5,4);
    cout<<"\n Sum of X + Y : "  << f.Sum();

    Son s(5,4,3);
    cout<<"\n Sum of X + Y + Z: "  << s.Sum();
    return 0;
}
