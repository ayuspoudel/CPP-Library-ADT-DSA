#include <iostream>
#include <string>

int main(){
    std:: string name;
    std::cin>>name>>name;
    std::cout<<name<<std::endl;
    std::cout<<name.length()<<std::endl;
}

// using namespace std;

// void example_f(int value, int& ref){
//     ref++;
//     value++;
// }

// int main(){
//     int x, y;
//     cin>>x >>y;
//     example_f(x,y);
//     cout<<x<<endl<<y;
// }

// enum mealType{VEG, NON_VEG, VEGAN, DAIRFREE, NUTFREE};
// struct Patient{
//     string disease;
//     int id;
//     mealType meal;
//     float due;
// };

// int main(){
//     struct Patient *p1;
//     p1 = new Patient;
//     p1->disease = "Cancer";
//     p1->id = 235;
//     p1->meal = VEGAN;
//     p1->due = 368.2;


//     cout<<"Disease: "<<p1->disease<<endl<<"Patient ID: "<<p1->id<<endl<<"Patient Meal type: "<<p1->meal<<endl<<"Amount due: $"<<p1->due<<endl;
// }

