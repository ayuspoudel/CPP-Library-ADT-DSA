#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
template<typename E>
class queueArray{
    enum {DEF_CAP = 100};
    public:
        queueArray();
        ~queueArray();
        void enqueue(const E& elme);
        void dequeue();
        int getSize() const;
        bool empty() const;
        bool full() const;
        void print();
    private:
        int front;
        int rear;
        int size;
        E* qArr;
    protected:
};
#endif
