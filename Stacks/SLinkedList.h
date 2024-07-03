#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include"SNode.h"
template<typename E> class SLinkedList{
    public:
        SLinkedList();
        SLinkedList(const SLinkedList& S);
        ~SLinkedList();
        const E& front() const;
        int getSize();
        void addFront(const E& elem);
        void removeFront(); 
        bool empty() const;
        void print() const;
    protected:
    private:
        int nElem = 0;
        SNode<E>* head;
        void copyList(const SLinkedList<E>& other);
        void clearList();
};
template<typename E>SLinkedList<E>::SLinkedList():
    head(nullptr), nElem(0){};
template<typename E>SLinkedList<E>::SLinkedList(const SLinkedList<E>& source){
    if(!this->empty()){
        this->clearList();
    }
    this->copyList(source);
    return;
}
template<typename E>SLinkedList<E>::~SLinkedList(){
    this->clearList();
}
template<typename E>const E& SLinkedList<E>::front() const{
    if(this->empty()){
        throw std::runtime_error("List is empty");;
    }
    return this->head->elem;
}
template<typename E>void SLinkedList<E>::addFront(const E& elem){
    SNode<E>* temp = new SNode<E>(elem);
    if(this->empty()){
        this->head = temp;
        return;
    }
    temp->next = head;
    head = temp;
    nElem++;
    return;
}
template<typename E>void SLinkedList<E>::removeFront(){
    if(this->empty()){
        return;
    }
    SNode<E>* pointer = head;
    head = head->next;
    delete pointer;
    nElem--;
    return;
}
template<typename E>int SLinkedList<E>::getSize(){
    return this->nElem;
}
template<typename E>bool SLinkedList<E>::empty() const{
    if(this->head == nullptr){
        return 1;
    }
    return 0;
}
template<typename E>void SLinkedList<E>::copyList(const SLinkedList<E>& other){
    if(other.head == nullptr){
        this->head = nullptr;
        this->nElem = 0;
        return;
    }
    this->head = new SNode<E>(other.head->elem);
    SNode<E>* thispointer = this->head;
    SNode<E>* curr = other.head->next;
    while(curr!=nullptr){
        thispointer->next = new SNode<E>(curr->elem);
        curr = curr->next;
        thispointer = thispointer->next;
    }
    this->nElem = other.nElem;
}
template<typename E>void SLinkedList<E>::clearList(){
    if(!this->empty()){
        SNode<E>* temp = this->head;
        while(temp!=nullptr){
            SNode<E>* pointer = temp;
            temp = temp->next;
            delete pointer;
        }
    }
    this->nElem = 0;
    return;
}
template<typename E>void SLinkedList<E>::print() const{
    SNode<E>* temp = this->head;
    while(temp!=nullptr){
        std::cout<<temp->elem<<" ";
        temp = temp->next;
    }
    std::cout<<"null"<<std::endl;
};
#endif