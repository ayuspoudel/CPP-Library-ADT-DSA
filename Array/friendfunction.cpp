#include<iostream>
#include<string>
#include<cmath>

class User{
    private:
        std::string status = "Gold";
        std::string fname;
        std::string lname;
        static int count;
    public:
        User(){
            count++;
        }
        User(std::string f, std::string l, std::string s = "Gold"){
            this->fname = f;
            this->lname = l;
            this->status = s;
        }
        void get_details(){
            std::cout<<"Name: "<<fname<<" "<<lname<<"\t";
        }
        void set_name(std::string f, std::string l){
            this->fname = f;
            this->lname = l;
        }
        void set_status(std::string s){
            this->status = s;
        }
        ~User(){
            std::cout<<"Destructor initialized"<<std::endl;
            count--;
        }
        friend void set_name_status(std::string f, std::string l, std::string s);
};
int User::count = 0;

int main(){
    User user1("Ayush", "Poudel", "Platinum");
    user1.get_details();
    return 0;
};