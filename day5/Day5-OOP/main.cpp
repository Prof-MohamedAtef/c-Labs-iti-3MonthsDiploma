#include <iostream>

using namespace std;

class Stack{

    int* Stk;
    int Size;
    int Tos;

    static int StkCounter;

public:

    static int getCounter()
    {
        return StkCounter;
    }

    Stack()
    {
        Size = 5;
        Tos = 0;
        Stk = new int[Size];   ///Allocate StkArray Dynamically in heap

        StkCounter++;

        cout<<"\n Parameterless Constructor ... ";
    }

    Stack(int Num)
    {
        Size = Num;
        Tos = 0;
        Stk = new int[Size];   ///Allocate Stk Array Dynamically in heap

        StkCounter++;

        cout<<"\n Parameterized Constructor with Stack Size..";
    }

    Stack(Stack& St)  ///ViewContent(S1)
    {
        ///this here is S, object to be created
        this->Size = St.Size;
        this->Tos = St.Tos;
        ///this->Stk = St.Stk;
        this->Stk = new int[Size];   ///Allocate Stk Array Dynamically in heap

        for(int i=0; i<St.Tos; i++)
            this->Stk[i] = St.Stk[i];

        StkCounter++;

        cout<<"\n Copy Constructor..";
    }

    ~Stack()
    {
        StkCounter--;

        for(int i=0; i<Tos; i++)
            Stk[i] = -1;

        delete[] Stk;  ///Free Dynamically Allocated Stk Array from Memory --- return it back to OS
        cout<<"\n Stack Destructor..";
    }

    void Push(int X)
    {
        if(Tos < Size)
        {
            Stk[Tos] = X;
            Tos++;
        }
        else
        {
            cout<<"\n U Can't push More Values, Stack is Full!!";
        }
    }

    int Pop()
    {
        if(Tos > 0)
        {
            Tos--;
            return Stk[Tos];
        }
        else
        {
            cout<<"\n Empty!!!";
            return -1;
        }
    }

    friend void viewContent(Stack S);

    int operator[](int index)
    {
        if(index >=0 && index < Tos)
            return Stk[index];
    }




    Stack operator= (Stack& St)  ///ViewContent(S1)
    {
        ///this here is S, object to be created
        this->Size = St.Size;
        this->Tos = St.Tos;

        delete[] this->Stk;

        ///this->Stk = St.Stk;
        this->Stk = new int[Size];   ///Allocate Stk Array Dynamically in heap

        for(int i=0; i<St.Tos; i++)
            this->Stk[i] = St.Stk[i];

        cout<<"\n Assignment Operator Overloading...";

        return St;
    }


};


int Stack::StkCounter = 0;

void viewContent(Stack S)  /// Stack S = S1 (bitwise copy) //pass by value
{
    cout<<"\n Stack Content: ";
    for(int i=0; i<S.Tos; i++)
    {
        cout<<endl<<S.Stk[i];
    }
}

int main()
{
    Stack S1(7), S2, S3;

    cout<< "\n Stack Counter = "<< Stack::getCounter();

    S1.Push(3);
    S1.Push(5);
    S1.Push(7);

    S2 = S1;

    cout<< endl << S2.Pop();

    S2.Push(11);

    cout<< endl << S1.Pop();

    cout<< endl << S1[1];

    Stack S4;

    cout<< "\n Stack Counter = "<< Stack::getCounter();

    Stack S5;

    cout<< "\n Stack Counter = "<< Stack::getCounter();




   /* Stack S1(7);

    S1.Push(11);
    S1.Push(12);
    S1.Push(13);

    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();*/


/*
    Stack S1;

    S1.Push(11);
    S1.Push(12);
    S1.Push(13);
    S1.Push(14);
    S1.Push(15);
    S1.Push(16);

    viewContent(S1);

    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();

    viewContent(S1);

*/



    return 0;
}
