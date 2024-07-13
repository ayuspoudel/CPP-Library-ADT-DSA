#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

int main(){
    std::vector<int> v1 = {1,2,3,4,5};
    auto i = v1.begin();
    while(i!=v1.end()){
        if(*i == 3){
            i++;
            continue;
        }
        std::cout<<*i<<"\t";
        i++;
    }
}