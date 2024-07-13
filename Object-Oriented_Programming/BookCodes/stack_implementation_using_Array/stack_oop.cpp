#include"stack_oop.h"
template<typename E>StackArray<E>::StackArray():
    size(DEF_CAP), top(-1), sArray(new E[DEF_CAP]){};
template<typename E>StackArray<E>::~StackArray(){
    while(top> -1){
        this->top--;
    }
}
template<typename E>void StackArray<E>:: push(const E& elem){
    this->top++;
    this->sArray[top] = elem;
}
template<typename E>const E&  StackArray<E>::pop(){
    const E& temp = this->sArray[this->top];
    this->top--;
    return temp;
}
template<typename E>const E&  StackArray<E>::peek(const int& pos) const{
    int index = this->top - pos +1;
    return this->sArray[index];
}
template<typename E>const E&  StackArray<E>::stackTop() const{
    return this->sArray[top];
}
template<typename E>bool StackArray<E>:: isFull() const{
    if(this->top == size -1){
        return true;
    }
    return false;
}
template<typename E>bool StackArray<E>:: isEmpty() const{
    if(this->top == -1){
        return true;
    }
    return false;
}
template<typename E> int StackArray<E>:: getSize() const{
    int n = this->top;
    return n+1;
}
template<typename E>void StackArray<E>:: print() const{
    int temp = top;
    while(temp>=0){
        std::cout<<this->sArray[temp]<<" ";
        temp--;
    }
    std::cout<<std::endl;

    return;
}
