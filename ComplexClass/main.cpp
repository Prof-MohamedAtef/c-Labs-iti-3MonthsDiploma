#include <iostream>

using namespace std;

class Complex{

private:
    int real;
    int img;
public:
    void setReal(int r){
        real=r;
    }

    void setImg(int img_){
        img=img_;
    }

    int getReal(){
        return real;
    }
    int getImg(){
        return img;
    }


    void printAsMemeberFunction(){
        cout << "Result of Complex addition is: " << getImg() << " For img , and " << getReal()<< " For Real ...\n"<< endl;
    }
};

void printComplexs(Complex resultComplex){


    cout << "Result of Complex addition is: " << resultComplex.getImg() << " For img , and " << resultComplex.getReal()<< " For Real ...\n"<< endl;
}

Complex Add(Complex C1, Complex C2){
    Complex C_collector;
    C_collector.setImg(C1.getImg()+C2.getImg());
    C_collector.setReal(C1.getReal()+C2.getReal());
    return C_collector;
}

Complex subtract(Complex C1, Complex C2){
    Complex C_collector;
    C_collector.setImg(C1.getImg()-C2.getImg());
    C_collector.setReal(C1.getReal()-C2.getReal());
    return C_collector;
}

int main()
{
    Complex aComplex, bComplex, resultComplex;
    aComplex.setImg(8);
    aComplex.setReal(9);

    bComplex.setImg(12);
    bComplex.setReal(24);

    /*
    swap add & subtract
    */
    //printComplexs(Add(aComplex, bComplex));

    //printComplexs(subtract(aComplex, bComplex));

    resultComplex=Add(aComplex,aComplex);

    resultComplex.printAsMemeberFunction();
    return 0;
}
