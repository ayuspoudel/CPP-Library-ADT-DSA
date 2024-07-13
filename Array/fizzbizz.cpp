#include <vector>
#include <iostream>

template<typename T>
void print(std::vector<T> v){
    for(auto it = v.begin(); it != v.end(); it++){
        if(*it == -3){
            std::cout << "Fizz" << "\t";
            continue; 
        }
        else if(*it == -5){
            std::cout << "Bizz" << "\t";
            continue;
        }
        else if(*it == -15){
            std::cout << "FizzBizz" << "\t";
            continue;
        };
        std::cout << (*it) << "\t";
    }
}

int main(){
    std::vector<int> v1(1, 0);
    auto it = v1.begin();
    for(int i= (*it)+1; i<=100;i++){
        if(i%3 == 0){
            v1.push_back(-3);
        }
        else if(i%5 == 0){
            v1.push_back(-5);
        }
        else if(i%5 == 0 && i%3 == 0){
            v1.push_back(-15);
        }
        else{
            v1.push_back(i);
        }
    };
    print(v1);

    return 0;
}
