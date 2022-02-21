#include <iostream>

using namespace std;

class Complex
{
    int Real;
    int Img;

public:
    Complex()
    {
        Real = Img = 0;
        cout<<"\nCtor_1"<<endl;;
    }
    Complex(int N)
    {
        Real = Img = N;
        cout<<"\nCtor_2"<<endl;;
    }
    Complex(int r, int i)
    {
        Real = r;
        Img = i;
        cout<<"\nCtor_3"<<endl;;
    }

    Complex(Complex& C)
    {
        Real = C.Real;
        Img = C.Img;
        cout<<"\nCopy Ctor"<<endl;;
    }

    int getReal(){ return Real; }
    int getImg(){ return Img; }
    void setReal(int r){ Real = r ; }
    void setImg(int i){ Img = i ; }

    ~Complex()
    {
       cout<<"\nDestructor!!"<<endl;;
    }

    void Print()
    {
        cout<<Real<<"+"<<Img<<"i"<<endl;
    }
};



template<class T>
class Stack
{
    T* stkPtr;
    int tos;  //First empty place to have value
    int stkSize;

    public:

    Stack()
    {
        tos = 0;
        stkSize = 5;
        stkPtr = new T[stkSize];

        cout<<"\n Am Default Constrctor...."<<endl;
    }

    ///Stack S;  //5
    ///Stack S2(3);  //3

    //Stack(int s=5)
    Stack(int s)
    {
        //(*this).tos = 0;
        this->tos = 0;
        this->stkSize = s;
        stkPtr = new T[stkSize];

        cout<<"\n Am Parametized Constrctor...."<<endl;
    }

    ///Copy Constructor
    Stack( Stack& St) ///Stack &St = S;
    {
        tos = St.tos;
        stkSize = St.stkSize;
        ///stkPtr = St.stkPtr;
        stkPtr = new T[stkSize];

        for(int i=0; i<tos; i++)    ///deep copying
            stkPtr[i] = St.stkPtr[i];

        cout<<"\n Am Copy Constrctor :)))))";
    }


    void push(T val)
    {
        if(tos < stkSize)
        {
            stkPtr[tos] = val;
            tos++;
        }
    }

    /*
    T pop()
    {
        if(tos > 0)
        {
            tos--;
            return stkPtr[tos];
        }
        return -1;
    }
*/

    T pop();

    ///Assignment Operator Overloading


    ~Stack()
    {
        for(int i=0; i<tos; i++)
            stkPtr[i] = -1;

        delete[] stkPtr;
        cout<<"\n Am Destructor...."<<endl;
    }
};



template<typename T>
void SWAP(T& X, T& Y)
{
    T temp = X;
    X = Y;
    Y = temp;
}

template<class T>
 T Stack<T>::pop()
    {
        if(tos > 0)
        {
            tos--;
            return stkPtr[tos];
        }
        return -1;
    }



int main()
{

    int x =4;
    int y=6;
    cout<<"\n values before swap for X = "<< x <<" and y = "<< y;
    SWAP<int>(x,y);
    cout<<"\n values after swap for X = "<< x <<" and y = "<< y;

    cout<<"\n.............\n............";

    Complex C1(3,8);
    Complex C2(4,9);

    cout<<"\n Before Swap , C1 = ";
    C1.Print();
    cout<<", C2 = ";
    C2.Print();
    SWAP<Complex>(C1, C2);

    cout<<"\n After Swap , C1 = ";
    C1.Print();
    cout<<", C2 = ";
    C2.Print();

    cout<<"\n.............\n............";

    Stack<int> S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);


    cout<<"\n Value = "<<S1.pop();
    cout<<"\n Value = "<<S1.pop();
    cout<<"\n Value = "<<S1.pop();
    cout<<"\n Value = "<<S1.pop();
    cout<<"\n Value = "<<S1.pop();


    Stack<char> S2(3);

    S2.push('A');
    S2.push('B');
    S2.push('C');

    cout<<"\n Char = "<<S2.pop();
    cout<<"\n Char = "<<S2.pop();
    cout<<"\n Char = "<<S2.pop();
    cout<<"\n Char = "<<S2.pop();

    return 0;
}


