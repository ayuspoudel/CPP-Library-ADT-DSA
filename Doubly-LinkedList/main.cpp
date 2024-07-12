#include"DNode.h"
#include"DLinkedList.h"

int main(){
    DLinkedList<int>* nums = new DLinkedList<int>;
    nums->push(1);
    nums->push(3);
    nums->push(4);
    nums->push(5);
    nums->insertAt(2, 4);
    nums->print();
    DLinkedList<char>* names = new DLinkedList<char>;
    names->push_back('A');
    names->push_back('C');
    names->push_back('D');
    names->push_back('E');
    names->insertAt('B', 2);
    names->print();
    nums->removeBack();
    nums->removeFront();
    nums->print();
    names->deleteAt(3);
    names->deleteAt(4);
    names->print();
    DLinkedList<std::string>* person  = new DLinkedList<std::string>;
    person->push_back("Ayush");
    person->push_back("Rakshya");
    person->push_back("Ashutosh");
    person->push_back("Ankeeta");
    person->print();
    person->reverse();
    person->print();
    return 0;
}