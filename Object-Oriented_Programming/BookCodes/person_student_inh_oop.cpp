#include<string>
#include<iostream>

class Person{
    protected:
        std::string name;
        std::string idnum;
    public:
        Person();
        Person(const std::string& name, const std::string& idnum);
        virtual void print();
        std::string getName();
};
class Student:public Person{ //public inheritance -- types of inheritance
    private:
        std::string major;
        int gradYear;
    public:
        Student();
        Student(const Person& p1, const std::string& major, int gy);
        virtual void print();
        std::string getname();
        void changeMajor(const std::string& newMajor);
};

Person::Person():name(""), idnum("") {};
Person::Person(const std::string& name,const std::string& idnum): name(name), idnum(idnum) {};
void Person::print(){
    std::cout<<"Person 1"<<std::endl<<"Name: "<<name<<std::endl<<"IDnum: "<<idnum<<std::endl;
}
std::string Person::getName() {return this->name;};
Student::Student():major(""), gradYear(-1) {};
Student::Student(const Person& p1, const std::string& major, int gy):Person(p1), major(major), gradYear(gy){};
void Student::print(){
    Person::print();
    std::cout<<"Major: "<<major<<std::endl<<"Graduation Year : "<<gradYear<<std::endl;
}
void Student::changeMajor(const std::string& newMajor){
    this->major = newMajor;
}

int main(){
    Person person1("Ayush", "U43442445");
    Student student(person1, "Computer Science", 2026);
    // person1.print();
    std::cout<<std::endl;
    // student.print();

    Person* pp[100];
    pp[0] = new Person("Rakhsya", "29");
    pp[1] = new Student(*pp[0], "Psychology", 2019);
    pp[1]->print();
    Student* sp = dynamic_cast<Student*>(pp[1]);
    sp->changeMajor("Computer Science");
    pp[1]->print();
    // std::cout<<pp[1]->getName()<<std::endl;
    return EXIT_SUCCESS;
}