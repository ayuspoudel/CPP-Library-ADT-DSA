

#include<iostream>
#include<cmath>


void func1(int n);
void func2(int n);


int main(){
    func1(20);
    return EXIT_SUCCESS;
}

void func1(int n){
    if(n>0){
        printf("%d ", n);
        func2(n-1);
    }
}

void func2(int n){
    if(n>1){
        printf("%d ", n);
        func1(std::floor(n/2));
    }
}