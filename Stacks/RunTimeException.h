#ifndef RUNTIMEEXCEPTION_H
#define RUNTIMEEXCEPTION_H
#include<string>
class RunTimeException{
    std::string ErrMsg;
    public:
        RunTimeException(const std::string &err): ErrMsg(err){};
        std::string getMessage() const{
            return ErrMsg;
        }

};
#endif