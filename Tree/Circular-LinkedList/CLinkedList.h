#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H
#include"CNode.h"
template<typename E>
class CLinkedList{
    public:
        CLinkedList();
        CLinkedList(const CLinkedList<E>& source);
        ~CLinkedList();
        void insertAt(const E& elem, const int& pos);
        void deleteAt(const int& pos);
        void print() const;
        void addFront(const E& elem);
        void addEnd(const E& elem);
        void removeFront();
        void removeEnd();
        int getSize() const;
        void reverse();
    protected:
    private:
        int nElem;
        CNode<E>* head;
        bool empty(){
            return nElem == 0;
        }

};

template<typename E>CLinkedList<E>::CLinkedList():
    nElem(0), head(nullptr){};
template<typename E>CLinkedList<E>::CLinkedList(const CLinkedList<E>& source){
    if(source->empty()){
        this->head = nullptr;
        this->nElem = 0;
        return;
    }
    this->head = new CNode<E>(source.head); //we have a copy constructor in CNode too
    CNode<E>* temp  = source.head->next;
    CNode<E>* pointer = this->head;
    while(temp!=source.head){
        CNode<E>* newNode = new CNode<E>(temp);
        pointer->next = newNode;
        newNode->next = this->head;
        temp = temp->next;
        pointer = newNode;
    };
        this->nElem = source.nElem;
}
template<typename E>CLinkedList<E>::~CLinkedList(){};
template<typename E>int CLinkedList<E>::getSize() const{
    return nElem;
}
template<typename E> void CLinkedList<E>::print() const{
    if(this->head == nullptr){
        throw std::runtime_error("List is empty");
    }
    CNode<E>* temp = this->head;
    do{
        std::cout<<temp->elem<<" ";
        temp = temp->next;
    }while (temp!=head);
    std::cout<<std::endl; 
    return;
}
template<typename E>void CLinkedList<E>::addFront(const E& elem){
    CNode<E>* newNode = new CNode<E>(elem);
    if(this->empty()){
        this->head = newNode;
        nElem++;
        return;
    }
    CNode<E>* temp;
    for(temp = this->head; temp->next!=this->head; temp = temp->next);
    newNode->next = this->head;
    temp->next = newNode;
    head = newNode;
    nElem++;
    return;
}
template<typename E> void CLinkedList<E>::addEnd(const E& elem){
    CNode<E>* newNode = new CNode<E>(elem);
    if(this->empty()){
        this->head = newNode;
        nElem++;
        return;
    }
    CNode<E>* temp = head;
    do{
        temp = temp->next;
    }while(temp->next!=head);
    newNode->next = head;
    temp->next = newNode;
    nElem++;
    return;
}
template<typename E> void CLinkedList<E>::removeFront(){
    CNode<E>*temp = this->head;
    if(nElem == 1){
        this->head = nullptr;
        delete temp;
        nElem--;
        return;
    }
    do{
        temp = temp->next;
    }while(temp ->next!=head);
    CNode<E>*curr = this->head;
    temp->next = curr->next;
    head = temp->next;
    delete curr;
    nElem--;
    return;
}
template<typename E> void CLinkedList<E>::insertAt(const E& elem, const int& pos){
    CNode<E>* newNode = new CNode<E>(elem);
    if(nElem == 0){
        this->head =  newNode;
        nElem++;
        return;
    }
    if(pos == 1){
        this->addFront(elem);
        nElem++;
        return;
    }
    if(pos == this->nElem + 1){
        this->addEnd(elem);
        nElem++;
        return;
    }
    if(pos>this->nElem+1){
        throw std::runtime_error("Index Out of Bounds Error");
        return;
    }
    CNode<E>* temp = this->head;
    int i = 1;
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    nElem++;
    return;

}
template<typename E>void CLinkedList<E>::reverse(){
    if(this->empty()){
        return;
    }
    if(this->getSize() == 1){
        return;
    }
    CNode<E>* prev = this->head;
    do{
        prev = prev->next;
    }while(prev->next!=head);
    CNode<E>* curr = head;
    CNode<E>* Next = curr->next;
    do{
        curr->next = prev;
        prev = curr;
        curr = Next;
        Next = curr->next;
    }while(curr!=head);
    this->head = curr->next;
    return;
}
#endif