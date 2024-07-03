#include"queueArray.h"
template<typename E> queueArray<E>::queueArray():
    front(-1), rear(-1), size(DEF_CAP), qArr(new E[DEF_CAP]) {};
template<typename E> queueArray<E>::~queueArray(){
    while(!this->empty()){
        this->front++;
        this->size--;
    }
}
template<typename E> void queueArray<E>::enqueue(const E& elem){
    if(this->full()){
        std::cout<<"Queue is full."<<std::endl;
        return;
    }
    rear++;
    size++;
    this->qArr[rear] = elem;
    return;
}
template<typename E> void queueArray<E>::dequeue(){
    if(this->empty()){
        std::cout<<"Queue is empty"<<std::endl;
    }
    front++;
    size--;
    return;
}
template<typename E>void queueArray<E>::print(){
    int i = front;
    while(i<=this->rear){
        std::cout<<this->qArr[i]<<" ";
        i++;
    }
    std::cout<<std::endl;
    return;

}
template<typename E> int queueArray<E>::getSize() const{
    return this->size;
}
template<typename E> bool queueArray<E>::full()const{
    if(this->rear ==  this->size){
        return true;
    }
    return false;
}
template<typename E> bool queueArray<E>::empty()const{
    if(!this->full()){
        if(this->rear == -1 || this->front == this->rear){
            return true;
        }
    }
    return false;
}
