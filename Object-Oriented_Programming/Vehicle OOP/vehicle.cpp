#include"Vehicle.h"
Vehicle::Vehicle():owner(""),years_old(-1){};
Vehicle::Vehicle(std::string owner, int y_old):owner(owner), years_old(y_old){};
void Vehicle::print(){std::cout<<"Owner: "<<owner<<std::endl<<"Years Old: "<<years_old<<std::endl;}
std::string Vehicle::get_owner() const{return this->owner;}
void Vehicle::set_owner(std::string owner){this->owner = owner;}
int Vehicle::get_years_old() const{return this->years_old;}
void Vehicle::set_years(int n){this->years_old = n;}

