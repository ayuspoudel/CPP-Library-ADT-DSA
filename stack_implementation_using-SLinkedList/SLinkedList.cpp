#include"SLinkedList.h"
template<typename E> SLinkedList<E>::SLinkedList():
    size(0),head(nullptr){};
template<typename E> SLinkedList<E>::~SLinkedList(){
    if(head == nullptr){
        return;
    }
    SNode<E>* temp = this->head;
    while(temp!=nullptr){
        SNode<E>* pointer = temp;
        temp = temp->next;
        delete pointer;
    }
    return;
}
template<typename E> void SLinkedList<E>::addFront(const E& elem){
    SNode<E>* newNode = new SNode<E>;
    newNode->elem = elem;
    newNode->next = this->head;
    this->head = newNode;
    size++;
}
template<typename E> void SLinkedList<E>::pushback(const E& elem){
    SNode<E>* newNode = new SNode<E>;
    newNode->elem = elem;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        return;
    }
    SNode<E>* temp;
    for(temp = head; temp->next!=nullptr; temp = temp->next);
    temp->next = newNode;
    size++;
}
template<typename E>void  SLinkedList<E>::removeFront(){
    if(head == nullptr){
        return;
    }
    SNode<E>* temp = head;
    head = head->next;
    delete temp;
    size--;
    return;
}
template<typename E> const E& SLinkedList<E>::find(const int& pos) const{
    if (this->head == nullptr) {
        throw std::out_of_range("Position out of range");
    }
    SNode<E>* temp = head;
    int count = 0;
    while(count<pos && temp!=nullptr){
        temp = temp->next;
        count++;
    }
    return temp->elem;
}
template<typename E> const E& SLinkedList<E>::front()const {
    return this->head->elem;
}
template<typename E> bool SLinkedList<E>::isEmpty()const{
    return (head==nullptr);
}
template<typename E> int SLinkedList<E>::getSize()const{
    return (this->size);
}
template<typename E> void SLinkedList<E>::print(){
    SNode<E>* temp = head;
    while(temp!=nullptr){
        std::cout<<temp->elem<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
    return;
}