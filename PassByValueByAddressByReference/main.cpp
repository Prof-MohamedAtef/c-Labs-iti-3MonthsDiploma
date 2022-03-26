#include <iostream>

using namespace std;


class Swaps{

public:
// by value
    void swapByValue(int x, int y) {
    int temp;
        temp = x; /* save the value of x */
        x = y;    /* put y into x */
        y = temp; /* put x into y */

     //   cout << "After swap, value of a :" << x << endl;
       // cout << "After swap, value of b :" << y <<" \n \n \n ................................... \n"<< endl;
    }

//by Address
    void swapByAddress(int* a, int* b) {
    int temp;
        temp= *a; /* save the value of x */
        *a=*b;    /* put y into x */
        *b=temp; /* put x into y */
    }



};\


class SwapByRef{
    public:
        void swapByReference(int &a, int &b) {
            int temp;
                temp= a; /* save the value of x */
                a=b;    /* put y into x */
                b=temp; /* put x into y */
        }
};

int main()
{
    // local variable declaration:
   int a = 100;
   int b = 200;

   Swaps s;
   SwapByRef sr;

    cout << "Before swap, value of a :" << a << endl;
    cout << "Before swap, value of b :" << b << endl;

    // calling a function to swap the values.

    //s.swapByValue(a, b);

    //s.swapByAddress(&a, &b);

    sr.swapByReference(a, b);

    cout << "After swap, value of a :" << a << endl;
    cout << "After swap, value of b :" << b <<" \n"<< endl;


   return 0;
}



