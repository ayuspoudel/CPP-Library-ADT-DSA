#include"Vehicle.h"
#ifndef CAR_H
#define CAR_H
class Car:public Vehicle{
    private:
        std::string make;
        double miles;
    public:
        Car();
        Car(std::string owner, int y_old,std::string mk, double n);
        void print();
        
};
#endif