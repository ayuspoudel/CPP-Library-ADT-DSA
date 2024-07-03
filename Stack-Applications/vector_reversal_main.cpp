#include "Stack-Library/Stack.h"
#include<vector>
#include<iostream>
#include<string>
#include<stdio.h>
template<typename E>
void print(const std::vector<E>& v){
    auto i = v.begin();
    while(i!=v.end()){
        std::cout<<(*i)<<" ";
        i++;
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<char>* nums = new std::vector<char>;
    char ch;
    while((ch = getchar())!='\n'){
        nums->push_back(ch);
        ch = getchar();
    }
    print(*nums);
    LinkedStack<char>* reversedNums = new LinkedStack<char>;
    for(auto i = nums->begin(); i!=nums->end(); i++)
        {
            reversedNums->push(*i);
        }
    int i = 0;

    while(!reversedNums->isEmpty()){
        (*nums)[i] = reversedNums->top();
        reversedNums->pop();
        i++;
    }
    print(*nums);
    return 0;
}