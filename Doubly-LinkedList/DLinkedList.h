#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include"DNode.h"
#include<exception>
template<typename E>
class DLinkedList{
    public:
        DLinkedList();
        ~DLinkedList();
        void emptyList();
        int getSize() const;
        const E& front() const;
        const E& back() const;
        void push(const E& elem);
        void push_back(const E& elem);
        void print() const;
        void insertAt(const E& elem, int pos);
        void deleteAt(int pos);
        void removeFront();
        void removeBack();
        void reverse();
    protected:
    private:
        DNode<E>* head;
        int nElem;
        bool isEmpty() const {
            return (this->nElem==0);
        }
};
template<typename E>DLinkedList<E>::DLinkedList():head(nullptr), nElem(0){};
template<typename E>DLinkedList<E>::~DLinkedList(){
    this->emptyList();
}
template<typename E> void DLinkedList<E>::emptyList(){
    if(this->isEmpty()){
        return;
    }
    DNode<E>* temp = this->head;
    while(temp!=nullptr){
        DNode<E>* pointer = temp;
        temp = temp->next;
        delete pointer;
    }
    this->nElem = 0;
    this->head = nullptr;
    return;
}
template<typename E> int DLinkedList<E>::getSize() const{
    return this->nElem;
}
template<typename E> const E& DLinkedList<E>::front()const {
    if(this->isEmpty){
        throw std::runtime_error("List is Empty.");
    }
    return this->head->elem;
}
template<typename E> const E& DLinkedList<E>::back()const {
    if(this->isEmpty()){
        throw std::runtime_error("List is Empty.");
    }
    DNode<E>* temp = this->head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    return this->temp->elem;
}

template<typename E> void DLinkedList<E>::push(const E& elem){
    DNode<E>* newNode = new DNode<E>(elem);
    if(this->isEmpty()){
        this->head = newNode;
        nElem++;
        return;
    }
    DNode<E>* pointer = this->head;
    newNode->next = pointer;
    newNode->prev = nullptr;
    pointer->prev = newNode;
    this->head = newNode;
    nElem++;
    return;
}
template<typename E>void DLinkedList<E>::print() const{
    if(this->isEmpty()){
        std::cout<<"The list is empty. "<<std::endl;
        return;
    }
    DNode<E>* temp = this->head;
    while(temp!=nullptr){
        std::cout<<temp->elem<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
    return;
}
template<typename E>void DLinkedList<E>::push_back(const E& elem){
    DNode<E>* newNode = new DNode<E>(elem);
    if(this->isEmpty()){
        this->head = newNode;
        nElem++;
        return;
    }
    DNode<E>* pointer = this->head;
    while(pointer->next!=nullptr){
        pointer = pointer->next;
    }
    pointer->next = newNode;
    newNode->next = nullptr;
    newNode->prev = pointer;
    nElem++;


}
template<typename E>void DLinkedList<E>::insertAt(const E& elem, int pos){
    if(this->getSize()==0){
        std::cout<<"The List is empty."<<std::endl;
        return;
    }
    if(pos>this->getSize()+1){
        throw std::runtime_error("Index out of bounds error. ");
    }
    if(pos == 1){
        this->push(elem);
        nElem++;
        return;
    }
    if(pos == this->getSize()+1){
        this->push_back(elem);
        nElem++;
        return;
    }
    DNode<E>* newNode = new DNode<E>(elem);
    int k = 1;
    DNode<E>* temp = this->head;
    while(k<pos-1){
        temp = temp->next;
        k++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    nElem++;
    return;

}
template<typename E>void DLinkedList<E>::removeFront(){
    if(this->head == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    DNode<E>* pointer = this->head;
    pointer->next->prev = nullptr;
    this->head = pointer->next;
    delete pointer;
    nElem--;
    return;
}
template<typename E> void DLinkedList<E>::deleteAt(int pos){
    if(this->head == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    if(pos>this->getSize()){
        throw std::runtime_error("Index out of bounds error.");
    }
    if(pos<1){
        throw std::runtime_error("Invalid Position.");
    }
    if(pos == 1){
        this->removeFront();
        return;
    }
    if(pos == this->getSize()){
        this->removeBack();
        return;
    }
    DNode<E>* pointer = this->head;
    int k =1;
    while(k<pos){
        pointer = pointer->next;
        k++;
    }
    pointer->prev->next = pointer->next;
    pointer->next->prev = pointer->prev;
    delete pointer;
    nElem--;
    return;
}
template<typename E>void DLinkedList<E>::removeBack(){
    if(this->head == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    DNode<E>* pointer = this->head;
    while(pointer->next!=nullptr){
        pointer = pointer->next;
    }
    pointer->prev->next = nullptr;
    delete pointer;
    nElem--;
    return;
}

template<typename E>void DLinkedList<E>::reverse(){
    if(this->isEmpty()){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    if(this->getSize() ==1){
        return;
    }
    DNode<E>* curr = this->head;
    DNode<E>* prev = nullptr;
    DNode<E>* nextptr = nullptr;
    while(curr!=nullptr){
        nextptr = curr->next;
        curr->next = prev;
        curr->prev = nextptr;
        prev = curr;
        curr = nextptr;
        
    };
    this->head = prev;
    return;
}



#endif