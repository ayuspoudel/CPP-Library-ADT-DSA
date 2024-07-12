#include"CLinkedList.h"
#include"CNode.h"

int main(){
    CLinkedList<int>* nums = new CLinkedList<int>;
    nums->addFront(1);
    nums->addFront(2);
    nums->addFront(3);
    nums->addFront(4);
    nums->addFront(5);
    nums->addEnd(0);
    nums->addEnd(-1);
    nums->addEnd(-2);
    nums->insertAt(90, 3);
    nums->insertAt(11, nums->getSize()+1);
    nums->print();
    nums->reverse();
    nums->print();

    return 0;
}