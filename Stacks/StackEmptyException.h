#ifndef STACKEMPTYEXCEPTION_H
#define STACKEMPTYEXCEPTION_H
#include"RunTimeException.h"
class StackEmptyException: public RunTimeException{
    public:
        StackEmptyException(const std::string& Err): RunTimeException(Err){};
};
#endif