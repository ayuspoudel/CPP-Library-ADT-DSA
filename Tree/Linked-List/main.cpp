#include"SLinkedList.cpp"

int main(){
    SLinkedList<int>* nums = new SLinkedList<int>;
    nums->addfront(1);
    nums->addfront(2);
    nums->addfront(5);

    SLinkedList<std::string>* names  = new SLinkedList<std::string>;
    names->addfront("Ayush");
    names->addfront("Rakshya");
    names->addfront("Ashutosh");
    names->addfront("Asmita");
    names->addfront("Ankeeta");

    std::cout<<"Size of the Linked List names: "<<names->getsize()<<std::endl;
    names->print();

    std::cout<<"Size of the Linked List nums: "<<nums->getsize()<<std::endl;
    nums->print();

    names->removeFront();
    std::cout<<"Size of the Linked List names: "<<names->getsize()<<std::endl;
    names->print();


    return 0;
}