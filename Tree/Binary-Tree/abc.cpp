#include<iostream>
#include<cstdlib>
static int count = 0;
void TOH(int n, char a, char b, char c){
    if(n == 1){
        std::cout<<"Move: "<<a<<" to "<<c;
        count++;
        std::cout<<count<<std::endl;
        return;
    }
    TOH(n-1, a, c, b);
    TOH(1, a, b, c);
    TOH(n-1, b, a, c);
}


int main(){
    std::cout<<"Enter a number: ";
    int n;
    std::cin>>n;
    TOH(n, 'B', 'C', 'A');
    std::cout<<count<<std::endl;
    return EXIT_SUCCESS;
}