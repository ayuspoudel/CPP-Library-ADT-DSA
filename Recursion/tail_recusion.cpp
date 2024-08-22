
#include <cstdlib>
#include <iostream>

void func1(int n){
    if(n>0){
        func1(n-1);    
        std::cout<<n<<" ";
    }
}

int main(){
    func1(3);
    return EXIT_SUCCESS;
}