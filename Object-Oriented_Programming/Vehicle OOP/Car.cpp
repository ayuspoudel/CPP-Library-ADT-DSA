#include"Car.h"
Car::Car(): Vehicle("", -1),make(""), miles(-1){};
Car::Car(std::string owner, int y_old,std::string mk, double n): Vehicle(owner, y_old), make(mk), miles(n){};
void Car::print(){Vehicle::print();std::cout<<"Make: "<<make<<std::endl<<"Miles: "<<miles<<" miles"<<std::endl;};
