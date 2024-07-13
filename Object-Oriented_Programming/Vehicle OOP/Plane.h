#include<string>
#include<iostream>
#include"Vehicle.h"
#ifndef PLANE_H
#define PLANE_H

class Plane:public Vehicle{
    private:
        std::string airlines;
        double flighttime;
    public:
        Plane();
        Plane(std::string owner, int y_old,std::string airlines, double flight_d);
        void print();
        
};
#endif