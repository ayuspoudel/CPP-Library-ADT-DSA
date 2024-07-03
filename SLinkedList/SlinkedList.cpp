#include<cstdlib>
#include<iostream>
#include<string>

class StringNode{
    public:
        StringNode(const std::string& e = "");
        ~StringNode();
        friend class SinglyLinkedList;
    private:
        std::string elem;
        StringNode* next;
        friend class SinglyLinkedList;
};
class SinglyLinkedList{
    public:
        //insert
        //remove
        //check if empty
        SinglyLinkedList();
        ~SinglyLinkedList();
        bool empty() const;
        void addFront(const std::string& elem);
        const std::string& front() const;
        void removeFront(); 
    protected:
    private:
        StringNode* head;
};
SinglyLinkedList::SinglyLinkedList():head(nullptr){};
SinglyLinkedList::~SinglyLinkedList(){
    while(!(this->empty())){
        this->removeFront();
    }
}
bool SinglyLinkedList::empty() const {
    return this->head==nullptr;
}
void SinglyLinkedList::addFront(const std::string& elem){
    StringNode* v = new StringNode(elem);
    v->next = this->head;
    this->head = v;
}
const std::string& SinglyLinkedList::front() const{
    return this->head->elem;
}
void SinglyLinkedList::removeFront(){
    StringNode* temp = this->head;
    this->head = this->head->next;
    delete temp;
}



int main(){
    return 0;
}