#include <string>
#include<iostream>
#ifndef VEHILCE_H
#define VEHICLE_H
#include<string>

class Vehicle{
    protected:
        std::string owner;
        int years_old;
    public:
        //Constructors
        Vehicle();
        Vehicle(std::string owner, int y_old);
        //getters and setters
        std::string get_owner() const;
        void set_owner(std::string owner);
        int get_years_old() const;
        void set_years(int n);
        //other functions
        virtual void print();
};
#endif