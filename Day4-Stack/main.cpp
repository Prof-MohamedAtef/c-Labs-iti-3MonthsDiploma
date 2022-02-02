#include <iostream>

using namespace std;

class Stack{

    int* myStack;
    int Size;
    int Tos;

public:
    Stack()
    {
        Size = 5;
        Tos = 0;
        myStack = new int[Size];   ///USed to Allocate Stack Array  dynamically in heap.
        cout<<"\n Parameterless Constructor..";
    }

    Stack(int value)
    {
        Size = value;
        Tos = 0;
        myStack = new int[Size];   ///Allocate MyStack Array Dynamically in heap
        cout<<"\n Parameterized Constructor with Stack Size..";
    }

    Stack(Stack& St)  ///ViewContent(S1)
    {
        ///this here is S, object to be created
        this->Size = St.Size;
        this->Tos = St.Tos;
        ///this->myStack = St.myStack;
        this->myStack = new int[Size];   ///Allocate myStackArray Dynamically in heap

        for(int i=0; i<St.Tos; i++)
            this->myStack[i] = St.myStack[i];

        cout<<"\n Copy Constructor..";
    }

    ~Stack()
    {
        for(int i=0; i<Tos; i++)
            myStack[i] = -1;

        delete[] myStack;  /// return allocated space in of the heap in memory to the OS control.
        cout<<"\n Stack Destructor..";
    }

    void Push(int X)
    {
        if(Tos < Size)
        {
            myStack[Tos] = X;
            Tos++;
        }
        else
        {
            cout<<"\n Your Stack is Full!! You cannot push more data ...";
        }
    }

    int Pop()
    {
        if(Tos > 0)
        {
            Tos--;
            return myStack[Tos];
        }
        else
        {
            cout<<"\n Empty!!!";
            return -1;
        }
    }

    friend void getPrivateMembers(Stack S);
};


/// This friendly function acts like a viewer of the private member of the class.

void getPrivateMembers(Stack S)  /// Stack S = S1 (bitwise copy) //pass by value
{
    cout<<"\n Stack Content: ";
    for(int i=0; i<S.Tos; i++)
    {
        cout<<endl<<S.myStack[i];
    }
}


int main()
{
   /* Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);

    getPrivateMembers(S1);
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();*/

/*

    Stack S1(5);

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);

    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();*/




    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);
    S1.Push(50);
    S1.Push(60);

    getPrivateMembers(S1);

    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();

    getPrivateMembers(S1);
    return 0;
}
