#include<cstdlib>
#include<iostream>
#include<string>

struct Node{
    int data;
    Node* next;
    Node(): data(), next(nullptr){};
    Node(int n): data(n), next(nullptr){};
};

class LinkedList{
    private:
        Node* root;
        
    public:
    LinkedList(): root(nullptr){};
    LinkedList(int n): root(new Node(n)){};
    Node* search(int key){
        Node* pointer;
        pointer = this->root;
        while(pointer!=nullptr){
            if(pointer->data != key){
                pointer = pointer->next;
            } else{
                return pointer;
            }
        }
        std::cout<<"\n"<<key<<" key does not exist in the list"<<std::endl;
        return nullptr;
    }
    void sortedInsert(int key){
        Node* newNode = new Node(key);
        if(this->root == nullptr){
            this->root = newNode;
            return;
        }
        Node* dummy = new Node();
        dummy->next = this->root;
        Node* curr = this->root;
        Node* prev = dummy;
        while(curr!=nullptr && curr->data<key){
            prev = curr;
            curr = curr->next;
            }
        prev->next = newNode;
        newNode->next = curr;
        this->root = dummy->next;
        delete dummy;
        return;
    }
    void display(){
        Node* pointer = this->root;
        while(pointer!= nullptr){
            std::cout<<pointer->data<<" ";
            pointer = pointer->next;
        }
        return;
    }
};

int main(){
    LinkedList* llist = new LinkedList();
    llist->sortedInsert(5);
    llist->sortedInsert(2);
    llist->sortedInsert(-1);
    llist->sortedInsert(99);
    llist->sortedInsert(-20);
    llist->display();
    llist->search(19);
    return EXIT_SUCCESS;
}