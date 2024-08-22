#include<iostream>


void func1(int n){
    if(n>0){
        printf("%d ", n);
        func1(n-1);
        func1(n-1);
        
    }
}
int main(){
    func1(3);
    return EXIT_SUCCESS;
}