#include <iostream>

using namespace std;


class Complex{
private:
    int Real;
    int Img;
public:
    Complex()
    {
        Real = 0;
        Img = 0;
        cout<<"\n This is the parameter less Constructor";
    }

    Complex(int num);

    Complex(int R, int I)
    {
        Real = R;
        Img = I;
        cout<<"\n 2 Parameters Constructor";
    }
    ~Complex()
    {
        cout<<"\n Now object is Destroying.......";
    }

    void setReal(int R)
    {
            this->Real = R;
    }
    int getReal()
    {
        return this->Real;
    }
    void setImg(int I)
    {
        Img = I;
    }
    int getImg()
    {
        return Img;
    }


    void printComplex();

    Complex AddComplex(Complex C);

    /// operators
    ///Complex AddComplex (Complex C)
    ///C3 = C1 + C2
    Complex operator+(Complex C)
    {
       Complex CRes;
       CRes.Real = this->Real + C.Real ;
       CRes.Img = Img + C.Img;
       return CRes;
    }

    ///C3 = C1 - C2
    Complex operator-(Complex C)
    {
       Complex CRes;
       CRes.Real = this->Real - C.Real ;
       CRes.Img = Img - C.Img;
       return CRes;
    }

    ///C3 = ++C1;
    Complex operator++()  ///prefix
    {
        this->Real++;
        return *this;
    }

    ///C3 = C1++;
    Complex operator++(int)  ///postfix
    {
        Complex temp = *this;
        this->Real++;
        return temp;
    }

    Complex operator+= (Complex C)
    {
        this->Real += C.Real;
        this->Img += C.Img;
        return *this;
    }

    int operator==(Complex C)
    {
       return (this->Real == C.Real && this->Img== C.Img);
    }


    ///C3 = C1 + 7;
   Complex operator+ (int Num)
   {
       int ResReal = this->Real + Num;
       int ResImg = this->Img;

       Complex Result(ResReal, ResImg);
       return Result;

       ///Complex Result(this->Real + Num, this->Img);
       ///return Result;
   }

    operator int()   ///Casting Operator has No return type
    {
        return this->Real + this->Img;
    }


};

    ///C3 = 7 + C1;
    Complex operator+(int num, Complex C)
    {
        Complex Result(C.getReal() + num, C.getImg());
        return Result;
    }

    Complex::Complex(int num)
    {
            Real = Img = num;
            cout<<"\n One Parameter Ctor";
    }

    void Complex::printComplex()
    {
        if(this->getImg() > 0)
            cout<<endl<< this->getReal() << "+" << this->getImg() << "i";   ///this pointer: is a pointer to the current object
        else
            cout<<endl<< this->getReal() << this->getImg() << "i";
    }

    Complex Complex::AddComplex(Complex C)
    {
       Complex CRes;
       CRes.Real = this->Real + C.Real ;
       CRes.Img = Img + C.Img;
       return CRes;
    }

    Complex SubtractComplex(Complex C1, Complex C2)
    {
        Complex CRes;
        CRes.setReal( C1.getReal() - C2.getReal() );
        CRes.setImg( C1.getImg() - C2.getImg() );
        return CRes;
    }

    /// default arguments task

    /// valid pattern
    /*int Sum(int A=2, int B=5, int C=3, int D=9)
    {
        return A + B + C + D;
    }*/


/*int Sum(int A, int B, int C=3, int D=9)
{
    return A + B + C + D;
}*/
    /// invalid pattern

    ///Not Valid Default Values:
/*
int Sum(int A=2, int B, int C=3, int D=9)
{
    return A + B + C + D;
}
*/

int Sum(int A, int B, int C, int D=9)
{
    return A + B + C + D;
}




int main()
{
    Complex C1(9), C2(2,7);

    //Complex C3 = C1.AddComplex(C2);

    //Complex C3 = C1.operator+(C2);


    ///add
    //Complex C3 = C1 + C2;
   // cout<<"\n Complex C3 = ";
   // C3.printComplex();

    ///subtract
    //Complex C3 = C1 - C2;
    //cout<<"\n Complex C3 = ";
    //C3.printComplex();

    /// plus plus - prefix
    //Complex C3 = ++C1;
    //cout<<"\n Complex C3 = ";
    //C3.printComplex();
   // C1.printComplex();

   /// plus plus postfix
 //   Complex C3 = C1++;
  //  cout<<"\n Complex C3 = ";
  //  C3.printComplex();
  //  C1.printComplex();


  /// equal operator
    /*if( C1 == C2)
        cout<<"\n They Are Equal...";
    else
        cout<<"\n They Are NOT Equal!!";*/

        /// plus equal
   /* C1 += C2;
    cout<<"\n Complex C1 = ";
    C1.printComplex();*/

    /// c1 + value
   /* Complex C3 = C1 + 7;
    cout<<"\n Complex C3 = ";
    C3.printComplex();*/


    /// value + c1
    /*Complex C3 = 7 + C1;
    cout<<"\n Complex C3 = ";
    C3.printComplex();*/

    /// cast operator [ value to Type ]
   /* int X = (int) C2;
    cout<< "\n X = "<< X;*/


    /// default arguments
    /*cout<< endl << Sum(11, 4, 20);
    cout<< endl << Sum(11, 4, 20, 10);*/
//    cout<< endl << Sum();
    cout<< endl << Sum(3,3,3);

    return 0;
}
