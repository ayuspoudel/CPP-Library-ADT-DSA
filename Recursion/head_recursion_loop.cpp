#include<iostream>
void func1(int n){
    while(n>0){
        std::cout<<n<<" ";
        n--;
    }
}

int main(){
    func1(3);
    return 0;
}