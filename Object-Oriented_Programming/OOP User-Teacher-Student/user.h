#ifndef TEACHER_H
#define TEACHER_H
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
class User{
    private:
        std::string fname;
        std::string lname;
        std::string status = "Gold";
    public:
        User();
        User(std::string f, std::string l, std::string s = "Gold");
        void change_name(std::string cf, std::string cl);
        void change_status(std::string cf);
        friend std::ostream& operator<<(std::ostream& output, User& user);
        friend std::istream& operator>>(std::istream& input, User& user);
};

#endif