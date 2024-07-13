
#include"user.h"

User::User(){
        }
User::User(std::string f, std::string l, std::string s){
    this->fname = f;
    this->lname = l;
    this->status = s;
        }
void User::change_name(std::string cf, std::string cl){
    this->fname = cf;
    this->lname = cl;
        }
void User::change_status(std::string cf){
        this->status = cf;
        }

std::ostream& operator<<(std::ostream& output, User& user){
    output<<"Name: "<<user.fname<<" "<<user.lname<<"\n"<<"Status:"<<user.status<<std::endl;
    return output;
    }
std::istream& operator>>(std::istream& input, User& user){
    std::cout<<"Please Enter the first name and last name of the user:";
    input>>user.fname>>user.lname;
    return input;
}
