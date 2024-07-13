#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include "user.h"


int main(){
    User user1;
    std::cin>>user1;
    std::cout<<user1;
    std::cout<<"Enter 5 if you want to change the status, and type the status below: \n";
    int c;
    std::cin>>c;
    if(c !=5){
        return 0;
    }
    std::cin.ignore();
    std::string st;
    std::getline(std::cin, st);
    user1.User::change_status(st);
    std::cout<<user1;
    return 0;
}