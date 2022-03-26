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
        cout<<"\n Parameterless GeoShape Constructor ...";
    }

    GeoShape(int dim){
        Dim1=Dim2=dim;
    }

    GeoShape(int L, int M)
    {
        Dim1 = L;
        Dim2 = M;
        cout<<"\n Two Parameter GeoShape Constructor ... ";
    }

    ~GeoShape()
    {
        cout<<"\n GeoShape Destructor ...";
    }

    int getDim1() { return Dim1; }
    void setDim1(int L) { Dim1 = L; }

    int getDim2() { return Dim2; }
    void setDim2(int M) { Dim2 = M; }


    float CalcArea()
    {
        return 0;
    }
};


class Rectangle: private GeoShape
{
   public:
    Rectangle():GeoShape()
    {
    }

    Rectangle(int a, int b) : GeoShape(a, b)
    {
       //Dim1=a;
        //Dim2=b;
        //setDim1(a);
        //setDim2(b);
    }

    float CalcArea()  ///Overriding
    {
        return getDim1() * getDim2();
    }
};


class Triangle: public GeoShape
{
public:
    Triangle():GeoShape()
    {    }

    Triangle(int a, int b) : GeoShape(a, b)
    {
        setDim1(a);
        setDim2(b);
    }

    float CalcArea()
    {
        return 0.5f * getDim1() * getDim2();
    }
};

class Square: protected GeoShape
{
public:
    Square():GeoShape()
    {    }

    Square(int a) : GeoShape(a)
    {    }

    setDim(int a)
    {
        Dim1=Dim2=a;
        //setDim1(a);
        //setDim2(a);
    }

    float CalcArea()
    {
        return getDim1() * getDim2();
    }
};

class Circle: public GeoShape
{
public:
    Circle():GeoShape()
    {    }

    Circle(int a) : GeoShape(a)
    {
        setDim1(a);
        setDim2(a);
    }

    ///Circle(int a, int b) : GeoShape(a, b)

    float CalcArea()
    {
        return 3.14f * getDim1() * getDim2();
    }
};

int main()
{
    Rectangle R(4,4);
    cout<<"\n Rectangle Area = "<< R.CalcArea();



    Triangle T(6,9);
    cout<<"\n Triangle Area = "<< T.CalcArea();


    Square S;
    S.setDim(5);
    cout<<"\n Square Area = "<< S.CalcArea();

/
    Circle C(15);
    cout<<"\n Circle Area = "<< C.CalcArea();

    return 0;
}
