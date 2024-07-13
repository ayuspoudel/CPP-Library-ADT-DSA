#include"Plane.h"
Plane::Plane(): Vehicle("", -1),airlines(""), flighttime(-1){};
Plane::Plane(std::string owner, int y_old,std::string mk, double n): Vehicle(owner, y_old), airlines(mk), flighttime(n){};
void Plane::print(){Vehicle::print();std::cout<<"Airlines: "<<airlines<<std::endl<<"Flight Time: "<<flighttime<<" hrs"<<std::endl;};

