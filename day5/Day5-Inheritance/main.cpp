#include <iostream>

using namespace std;

class Car{

    int CarNo, ManufactureYear;

public:
    Car()
    {
        CarNo=0;
        ManufactureYear = 0;
        cout<<"\n Parent Parameterless Constructor ... ";
    }

    Car(int carNo, int manuYear)
    {
        CarNo = carNo;
        ManufactureYear= manuYear;
        cout<<"\n Parent Two Parameter Constructor ... ";
    }

    void setCarNo(int car_no){
        CarNo=car_no;
    }

    int getCarNo(){
        return CarNo;
    }

    void setManufacturerYear(int manufacturer_year){
        ManufactureYear=manufacturer_year;
    }

    int getManfacturerYear(){
        return ManufactureYear;
    }

    void DisaplyDetails(){
        cout<<"\n Car Number is: "<< getCarNo()<<endl<<"Manufacture year is: "<< getManfacturerYear();
    }
};


class Truck: public Car{

    int BoxSize;

public:
    Truck() ///:Parent()
    {
        setCarNo(0);
        setManufacturerYear(0);

        BoxSize = 0;
        //X = Y = Z = 0;
        cout<<"\n Child Parameterless Constructor ... ";
    }

    Truck(int car_num, int maufacture_year, int box_size):Car(car_num, maufacture_year)  ///Constructor Chaining
    {
       BoxSize = box_size;
        cout<<"\n Child Three Parameters Constructor ... ";
    }

    void setBoxSize(int box_size){
        BoxSize=box_size;
    }

    int getBoxSize(){
        return BoxSize;
    }

    void DisplayDetails(){
        cout<<"\n This is Truck with the following info:"
        <<"\n Car Number is: "<< getCarNo()
        <<endl<<"Manufacture year is: "<< getManfacturerYear()
        <<endl<<"\n Box Size is:"<<this->getBoxSize();
    }

    /*void Total()
    {
        cout<<"\n This is Truck with the following info:"<<"\n Car Number is: "<< getCarNo()<<endl<<"Manufacture year is: "<< getManfacturerYear()<<endl<<"\n Box Size is:"<<this->getBoxSize();
    }*/
};




int main()
{
    Car car;

    car.setCarNo(1095);
    car.setManufacturerYear(2022);

    car.DisaplyDetails();
    cout<<" ............................. splitter .................. \n\n\n" ;

    Truck T(2000,2010,90);

    /*truck.setManufacturerYear(2020);
    truck.setCarNo(1025);
    truck.setBoxSize(80);*/
    T.DisplayDetails();



    return 0;
}
