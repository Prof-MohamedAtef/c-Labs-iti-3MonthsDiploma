#include <iostream>

using namespace std;
class Stack{
    int Stk[5];
    int Tos;

public:
    Stack()
    {
        Tos = 0;
    }

    ~Stack()
    {
        cout<<"\n Stack Destructor..";
    }

    void Push(int X)
    {
        if(Tos < 5)
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

};




int main()
{
    Stack S1;

    /// behavior is last in first out
    S1.Push(11);
    S1.Push(12);
    S1.Push(13);
    S1.Push(14);
    S1.Push(15);
    S1.Push(16);

    /// first out
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();
    cout<< endl << S1.Pop();

    return 0;
}
