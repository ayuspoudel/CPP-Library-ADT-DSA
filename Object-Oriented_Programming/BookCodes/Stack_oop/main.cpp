#include"stack_oop.cpp"

int main(){
    StackArray<int>* nums = new StackArray<int>;
    nums->push(33);
    nums->push(22);
    nums->push(11);
    nums->push(0);
    for(int i = 1; i<5; i++){
    std::cout<<nums->peek(i)<<std::endl;
    }
    const int& n = nums->pop();
    nums->print();

    std::cout<<nums->stackTop()<<std::endl;
     ;
    std::cout<<nums->getSize()<<std::endl;
    delete nums;
    return 0;
}