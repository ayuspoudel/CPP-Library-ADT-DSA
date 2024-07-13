#include<string>
#include<cmath>
#include<iostream>
#define RENT_PER_SQ 0.68

class House{
    private:
        std::string house_id;
        std::string house_sty;
        std:: string h_status;
        int length;
        int breadth;
    public:
        
        int rent;
        House(std::string house_id = "0000", std::string house_sty = "APT", std::string h_status = "Bronze", int l = 0, int b = 0){
            this->house_id = house_id;
            this->house_sty =  house_sty;
            this->h_status = h_status;
            this->length = l;
            this->breadth = b;
            this->rent = this->length * this->breadth * RENT_PER_SQ;
        }
        friend std::ostream& operator<<(std::ostream& output, House& h);
        void set_house(std::string house_id, std::string house_sty ,std::string h_status){
            this->house_id = house_id;
            this->house_sty =  house_sty;
            this->h_status = h_status;
        }
        void set_house_par(int l, int b){
            this->length = l;
            this->breadth = b;
        }
        void calculate_rent(){
            this->rent =  this->length * this->breadth * RENT_PER_SQ;
        }
};

std::ostream& operator<<(std::ostream& output, House& h){
    output<<"House ID\t"<<h.house_id<<"\nHouse Style\t"<<h.house_sty<<"\nHouse status\t"<<h.h_status<<"\nHouse Rent\t$"<<h.rent<<std::endl;
    return output;
}

int main(){
    House dragon;
    // std::cout<<dragon;
    dragon.set_house("12736 UCD", "Student Housing", "2BHK");
    dragon.set_house_par(65, 35);
    dragon.calculate_rent();
    std::cout<<dragon;
    return 0;
}