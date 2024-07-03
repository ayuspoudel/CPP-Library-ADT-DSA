#include"LinkedStack.h"

int main(){
    LinkedStack<char>* algo = new LinkedStack<char>;
    algo->push('U');
    algo->push('4');
    algo->push('3');
    algo->push('4');
    algo->push('4');
    if(algo->empty()){
        std::cout<<"It is empty";
    } else{
        std::cout<<"The stack is not empty"<<std::endl;
    }
    std::cout<<"The size of the stack is ";
    std::cout<<algo->size()<<std::endl;
    algo->print();
    algo->pop();
    algo->pop();
    std::cout<<"The size of the stack is ";
    std::cout<<algo->size()<<std::endl;
    algo->print();
    return 0;
}