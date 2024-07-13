#include <cstdlib>
#include <iostream>

struct ListNode{
    public:
    int val;
    struct ListNode* next;

    ListNode(){
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode* next): val(x), next(next){};

    void pushback(struct ListNode* &head, int val){
        struct ListNode* newNode = new ListNode(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
    ListNode* midpoint(ListNode* head){
        if(head == nullptr){
            return nullptr;
        }
        ListNode* slow  = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void print(struct ListNode* head){
        struct ListNode* temp = head;
        while(temp!=nullptr){
            std::cout<<temp->val<<"-->";
            temp = temp->next;
        }
        std::cout<<"nullptr"<<std::endl;
    }
    ListNode* reverse(ListNode* &head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reverselist(ListNode*& head){
        if(head == nullptr){
            return;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            curr->next = prev;
            prev->next = curr->next;
            prev = prev->next;
            curr = curr->next;
        };
        return;
    }
};

int main(){
    struct ListNode* head = nullptr;
    head->pushback(head, 0);
    head->pushback(head, 1);
    head->pushback(head, 2);
    head->pushback(head, 3);
    head->pushback(head, 4);
    head->print(head);
    // ListNode* mid = head->midpoint(head);
    // std::cout<<"The mid point value is: "<<mid->val<<std::endl;
    // head = head->reverse(head);
    // head->print(head);
    head->reverselist(head);
    head->print(head);
}