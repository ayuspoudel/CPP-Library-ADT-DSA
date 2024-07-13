/*
    This program is created to store the first and last name of the users of a particular app. It uses class method to create a class User,
    then creates a vector that can store multiple such classess called vector. It comes with an additional function which prevents from same 
    user to be addedd to the vector twice, which saves the uniqueness of the vector. Finally, we call the class in the main function, and then we add some 
    users to the vector that we create, we try to add additional users to the vector, using our unique maker function. The results can be calculated as
        -->>>    g++ vectors.cpp --std=c11 -o a.out
        -->>>    ./a.out
*/

#include<iostream>
#include<vector>

class User{
    std:: string status = "Gold";
    public:
        std::string first_name;
        std::string last_name;
        std::string get_status(){
            return status;
        }
        void print(){
            std::cout<<first_name<<" "<<last_name<<std::endl;
        }
        User(){
            std::cout<<"User Created"<<"\t";
        }
        User(std::string f, std::string l){
            this->first_name = f;
            this->last_name = l;
        };
    };


int main(){

    User user1("Ayush", "Poudel"); 
    user1.print(); //OP: Ayush Poudel
    User user2; //OP : User Created

    return 0;
    // std::vector<User> users;
    // User user1, user2, user3;
    
    // user1.first_name = "Ayush";
    // user1.last_name = "Poudel";
    // user2.first_name = "Ashutosh";
    // user2.last_name = "Poudel";
    // user3.first_name = "Asmita";
    // user3.last_name = "Poudel";

    // users.push_back(user1);
    // users.push_back(user2);
    // users.push_back(user3);

    // User user4, user5;

    // user4.first_name = "Ayush";
    // user4.last_name = "Poudel";
    // user5.first_name = "Ankeeta";
    // user5.last_name = "Acharya";

    // add_user_if_not_exist(users, user4);
    // add_user_if_not_exist(users, user5);

    // print(users);



}
