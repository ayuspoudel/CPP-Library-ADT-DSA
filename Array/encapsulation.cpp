#include<iostream>
#include<string>

class User{
    //Encapsulation
    private:  
   std::string fname;
   std::string lname;
   int age;
   static int count;
   public:
   
   void set_name(std::string f, std::string l){
        this->fname = f;
        count++;
   }
   void set_age(int n){
    this->age = n;
    
   }
   void getname(){
        std::cout<<this->fname<<"\n"<<this->lname<<"\n";
   }
   int getcount(){
        return count;
   }
   int getage(){
        return this->age;
   }
   void print(){
        std::cout<<this->fname
        <<"\n"<<this->lname<<"\n"
        <<this->age;
   }
};
int User::count  = 0;
int main(){
    User ayush;
    // ayush.fname = "Ayush";
    // ayush.lname = "Poudel";
    // ayush.age = 14;
    ayush.set_name("Ayush", "Poudel");
    
    ayush.set_age(14);
    std::cout<<ayush.getage();
    ayush.set_name("Ashutosh", "Poudel");
    ayush.getname();
    std::cout<<ayush.getcount();
    // ayush.print();
}



