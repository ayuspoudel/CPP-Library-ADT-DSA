#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include<exception>
#include"SLinkedList.h"
#include"StackEmptyException.h"

template<typename E> class LinkedStack{
    public:
        LinkedStack();
        LinkedStack(const LinkedStack<E>& other);
        int size() const;
        bool empty() const;
        const E& top()const noexcept(false);
        void pop() noexcept(false);
        void push(const E& elem);
        
        void print() ;
        void clearStack();
    private:
        SLinkedList<E> S;
        int numElem;
};
template<typename E>LinkedStack<E>::LinkedStack():
    numElem(0), S(){};
template<typename E>LinkedStack<E>::LinkedStack(const LinkedStack<E>& other):
    numElem(other.numElem), S(other.S){};
template<typename E>bool LinkedStack<E>::empty() const{
    return S.empty();
}
template<typename E>int LinkedStack<E>::size() const{
    return numElem;
}
template<typename E>const E& LinkedStack<E>::top() const noexcept(false){
    if(!empty()){
        return S.front();
    }
    throw StackEmptyException("Stack is empty");
}
template<typename E>void LinkedStack<E>::push(const E& elem){
    S.addFront(elem);
    numElem++;
    return;
}
template<typename E>void LinkedStack<E>::pop() noexcept(false){
    if(empty()){
        throw StackEmptyException("Stack is Empty");
    }
    S.removeFront();
    numElem--;
    return;
}
template<typename E>void LinkedStack<E>::print() {
    LinkedStack<E> pointer;
    while(!this->empty()){
        pointer.push(this->top());
        std::cout<<this->top()<<" ";
        this->pop();
    };
    std::cout<<std::endl;
    while(!pointer.empty()){
        this->push(pointer.top());
        pointer.pop();
    }
    return;
}
template<typename E>
void LinkedStack<E>::clearStack() {
    S.clearList();
    numElem = 0;
}

#endif