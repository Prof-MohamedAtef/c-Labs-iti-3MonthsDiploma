#include <iostream>

using namespace std;

class Complex{

    private:
        int Real;
        int Img;

    public:

        Complex AddComplex(Complex c);

        Complex SubtractComplex(Complex c);

        void printComplex();

        void setReal(int real_){
            Real=real_;
        }

        void setImg(int img_){
            Img=img_;
        }

        int getReal(){
            return Real;
        }

        int getImg(){
            return Img;
        }

        Complex(){
            Real=0;
            Img=0;
            cout<<"\n This is the default Constructor ...\n";
        }

        Complex(int real_, int img_){
            Real=real_;
            Img=img_;
            cout<<"\n This is the parameterized Constructor ... \n";
        }

        Complex(int common){
            Real=common;
            Img=common;
            cout<<"\n This is the parameterized Constructor ... \n";
        }

        ~Complex()
        {
            cout<<"\n Your object is being Destroyed now ...\n";
        }
};


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

    Complex Complex::SubtractComplex(Complex C)
    {
       Complex CRes;
       CRes.Real = this->Real - C.Real ;
       CRes.Img = Img - C.Img;
       return CRes;
    }

class Calculator{
public:
    int Add(int x, int y){
        return x+y;
    }

    int Add(int x, int y, int z){
        return x+y+z;
    }

    float Add(float x, float y){
        return x + y;
    }

    float Add(int x, float y){
        return x+y;
    }

    float Add(float x, int y){
        return x+y;
    }

    void Add(char x, char y, char z){
        cout<<endl<< "\n Concatenated letters are : "<< endl;
        cout<<x;
        cout<<y;
        cout<<z;
    }
};


int main()
{
    Complex C1, C2;

    C1.setReal(8);
    C1.setImg(9);

    C2.setReal(12);
    C2.setImg(12);

    ///Complex C3 = AddComplex(C1, C2);
    Complex C3 = C1.AddComplex(C2);
    cout<<"\n Complex C3 = ";
    C3.printComplex();

    Complex C4 =C1.SubtractComplex(C2);
    cout<<"\n Complex C4 = ";
    C4.printComplex();


    /*

    Calculator Work
    */


    Calculator calculator;

    calculator.Add('m','o','h');
    cout<<"\n Add for float and int is : "<< endl;
    cout<<calculator.Add(4.5f, 5)<< endl;
    cout<<"\n Add for int and float is : "<< endl;
    cout<<calculator.Add(5, 3.5f)<< endl;
    cout<<"\n Add for float and float is : "<< endl;
    cout<<calculator.Add(2.5f, 5.5f)<< endl;
    cout<<"\n Add for int and int is : "<< endl;
    cout<<calculator.Add(3, 7)<< endl;
    cout<<"\n Add result for 3 integers is : "<< endl;
    cout<<calculator.Add(3,7,5)<<endl;
    return 0;
}



