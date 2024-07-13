#include"queueArray.cpp"

int main(){
    queueArray<int>* nums = new queueArray<int>;
    nums->enqueue(-3);
    nums->enqueue(17);
    nums->enqueue(9);
    nums->enqueue(2);
    nums->enqueue(13);
    nums->enqueue(-8);
    nums->print();
    nums->dequeue();
    nums->dequeue();
    nums->dequeue();
    nums->print();
    return 0;
}