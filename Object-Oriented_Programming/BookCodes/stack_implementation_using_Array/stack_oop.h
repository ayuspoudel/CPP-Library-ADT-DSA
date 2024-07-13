#ifndef STACK_OOP_H
#define STACK_OOP_H
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
template<typename E>
class StackArray{
        enum {DEF_CAP= 100};
    public:
        StackArray();
        ~StackArray();
        void push(const E& elem);
        const E& pop();
        const E& peek(const int& pos) const;
        const E& stackTop() const;
        bool isEmpty() const;
        bool isFull() const;
        int getSize() const;
        void print() const;
    private:
        int size;
        int top;
        E* sArray;
    protected:
};

#endif