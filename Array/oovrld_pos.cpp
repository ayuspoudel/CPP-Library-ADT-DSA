#include<iostream>
#include<string>
#include<cmath>

class Position{
    private:
        int x=0;
        int y = 0;

    public:
    //constructor
        Position(){

        }
        Position(int a, int b){
            this->x = a;
            this->y = b;
        }
        Position operator+(Position const &pos){
            Position res(0,0);
            res.x = x+ pos.x;
            res.y = y+pos.y;
            return res;
        }
        Position operator-(Position const &pos){
            Position res(0,0);
            res.x = x- pos.x;
            res.y = y- pos.y;
            return res;
        }
        bool operator==(Position const &pos){
            return x == pos.x && y == pos.y;
        }

        friend std::ostream& operator<<(std::ostream& output, Position& pos);
        friend std::istream& operator>>(std::istream& input, Position& pos);
};
std::ostream& operator<<(std::ostream& output, Position& pos){
    output<<"("<<pos.x<<","<<pos.y<<")\n";
    return output;
}
std::istream& operator>>(std::istream& input, Position&pos){
    input>>pos.x>>pos.y;
    return input;
}

int main(){
    Position pos1, pos2;
    std::cin>>pos1;
    std::cin>>pos2;
    Position pos3 = pos1+pos2;
    std::cout<<pos1<<std::endl;
    std::cout<<pos3<<std::endl ;
    if(pos1==pos3){
        std::cout<<"The two positions are equal.\n";
    }
    else{
        std::cout<<"Pizza\n";
    }
    return 0;
}