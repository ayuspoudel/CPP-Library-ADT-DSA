#include"Vehicle.h"
#include"Car.h"
#include"Plane.h"

int main(){
    Plane jet4412("Ayush", 22, "Nepal Airlines", 2466.73);
    Car honda("Rakshya", 7, "Honda", 122460.23);
    jet4412.print();
    std::cout<<std::endl;
    honda.print();
    std::cout<<std::endl;
    honda.set_owner("Ayush");
    jet4412.set_owner("Rakshya");
    jet4412.print();
    std::cout<<std::endl;
    honda.print();
    std::cout<<std::endl;
    return 0;

}