#include<iostream>
#include<string>
#include<cstdlib>


class StringNode{
    public:
    protected:
    private:
        std::string elem;
        StringNode* next;
        friend class SLinkedList;
};
class SLinkedList{
    public:
        SLinkedList();
        ~SLinkedList();
        bool check_empty() const;
        const std::string& front() const;
        void addFront(const std::string& e);
        void removeFront();
    protected:
    private:
        StringNode* head;
};
SLinkedList::SLinkedList(): head(nullptr){};
SLinkedList::~SLinkedList(){
    while(!check_empty()){
        removeFront();
    }
}
bool SLinkedList::check_empty() const{
    
}