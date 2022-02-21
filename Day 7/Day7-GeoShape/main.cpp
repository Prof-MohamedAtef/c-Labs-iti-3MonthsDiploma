#include <iostream>

using namespace std;

class GeoShape
{
protected:
    int Dim1;
    int Dim2;

public:
    GeoShape()
    {
        Dim1 = Dim2 = 0;
        cout<<"\n Parameterless GeoShape Constructor ... ";
    }

    GeoShape(int L)
    {
        Dim1 = Dim2 = L;
        cout<<"\n One Parameter GeoShape Constructor ... ";
    }

    GeoShape(int L, int M)
    {
        Dim1 = L;
        Dim2 = M;
        cout<<"\n Two Parameter GeoShape Constructor ... ";
    }

    int getDim1() { return Dim1; }
    void setDim1(int L) { Dim1 = L; }

    int getDim2() { return Dim2; }
    void setDim2(int M) { Dim2 = M; }

    virtual float CalcArea() = 0;  ///Pure Virtual Function: "Abstract Function", function with NO body

};

class Rect: public GeoShape
{
   public:
    Rect():GeoShape()
    {    }

    Rect(int a, int b) : GeoShape(a, b)
    {   }

    float CalcArea()  ///Overriding
    {
        cout<<"\n Rect Area = ";
        return Dim1 * Dim2;
    }

    void MyMethod(){
        cout<<"MyMethod from Drived Calss..."<<endl;
    }
};



class Square: public GeoShape
///class Square: protected GeoShape
{
public:
    Square():GeoShape()
    {    }

    Square(int a) : GeoShape(a)
    {    }

    setDim(int a)
    {
        Dim1 = Dim2 = a;
    }

    float CalcArea()
    {
        cout<<"\n Square Area = ";
        return Dim1 * Dim2;
    }
};



class Circle: public GeoShape
{
public:
    Circle():GeoShape()
    {    }

    Circle(int a) : GeoShape(a)
    {    }

    ///Circle(int a, int b) : GeoShape(a, b)

    float CalcArea()
    {
        cout<<"\n Circle Area = ";
        return 3.14f * Dim1 * Dim2;
    }
};



float sumOfAllShapesArea(GeoShape* ShArr[], int Num)
{
    float Total = 0;
    for(int i=0; i<Num; i++)
    {
        Total += ShArr[i]->CalcArea();
    }
    return Total;
}


class SuperClass{

public:
    int X;

    SuperClass(){X=0;}

    SuperClass(int x_){X=x_;}


    virtual void MyMethod()
    {
        cout<<"MyMethod from Base Class..."<<endl;
    }
};

class SubClass:public SuperClass{
public:
    int Y;
    SubClass()///:Base()
    {
        Y=0;
    }

    SubClass(int L):SuperClass(L)
    {
        Y=L;
    }

    SubClass(int L, int M):SuperClass(L)
    {
        Y=M;
    }

    void MyMethod()
    {
        cout<<"MyMethod from Sub Class ..."<<endl;
    }
};

int main()
{
    GeoShape* ParnetPtr = new Rect(3,5);
    cout<<"\n GeoShape Area = "<<ParnetPtr ->CalcArea();


    Rect R(4,4);
    cout<<"\n Rectangle Area = "<< R.CalcArea();



   // Triangle T(6,9);
    //cout<<"\n Triangle Area = "<< T.CalcArea();


    Square S(9);
    cout<<"\n Square Area = "<< S.CalcArea();


    Circle C(15);
    cout<<"\n Circle Area = "<< C.CalcArea();

     GeoShape* ShpArray[3];
    ShpArray[0] = &R;
    ShpArray[1] = &S;
    ShpArray[2] = &C;

    cout<<".............";
    cout<< "\n SUM of All Areas using \n Pointers of Objects = "<< sumOfAllShapesArea( ShpArray, 3);



    cout<<"................\n.............\n";

    SuperClass super(3);
    super.MyMethod();

    SubClass sub(5);
    sub.MyMethod();

    cout<<"................\n.............\n";
    SuperClass* SuPtr=&super;
    SuPtr->MyMethod();

    SubClass* SubPtr=&sub;
    SubPtr->MyMethod();


    cout<<"................\n.............\n";

    SuPtr=&sub; /// Pointer from Base , points to Derived Object "Because inheritance, so each Child is-a Parent"

    SuPtr ->X=33;

    SuPtr->MyMethod();

    return 0;
}
