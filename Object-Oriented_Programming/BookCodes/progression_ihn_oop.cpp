/*
To make concepts of inheritance and polymorphism more concrete, lets consider a simple example in cpp. We consider an example of several classess that
print numeric progressions.
 A numeric progression is a sequence of numbers, where the value of each number depends on one or more of the previous values. 
For ex, value of each number depends on one or more of the previous values. For example, an arithmetic progression determines a next number by addition of 
a fixed increment.
A geometric progression determines a next number by multiplication by a fixed base value. 
In any case, a progression determines a next number by multiplication by a fixed base value. In any case, a progression requires a way of defining 
its first value, and it needs a way of identifying the current value as well.
*/ 
#include<iostream>
#include<string>
class Progression{
    public:
        Progression(long f = 0);
        virtual void print(int n);
        // virtual ~Progression();
    protected:
        virtual long firstValue();
        virtual long nextValue();
        long first;
        long cur;
    private:

};
Progression::Progression(long f): first(f), cur(f){};
long Progression::firstValue(){
    this->cur = this->first;
    return this->cur;
};
long Progression::nextValue(){
    return ++(this->cur);
}
void Progression::print(int n){   //We are making this reusable by calling nextValue and firstValue in it, so we dont have to redeclare it for child class
    std::cout<<firstValue();
    for(int i = 1; i<n; i++){
        std::cout<<", "<<nextValue();
    }
    std::cout<<std::endl;
}

class ArithProgression: public Progression{
    public:
        ArithProgression(int i = 1);
        ArithProgression(const Progression& p1, int i);
        //virtual ~ArithProgression();
    protected:
        virtual long nextValue();
    private:
        long increment;
};

ArithProgression::ArithProgression(int i): Progression(), increment(i){};
ArithProgression::ArithProgression(const Progression& p1, int i):Progression(p1),increment(i) {};
long ArithProgression::nextValue(){
    this->cur+=increment;
    return this->cur;
};

class GeoProgression: public Progression{
    public:
        GeoProgression(int b = 2);
        GeoProgression(const Progression& p2, int b);
        //virtual ~GeoProgression();
    protected:
        virtual long nextValue();
    private:
        long base;
};

GeoProgression::GeoProgression(int i): Progression(), base(i){};
GeoProgression::GeoProgression(const Progression& p2, int b):Progression(p2), base(b) {};
long GeoProgression::nextValue(){
    this->cur*=base;
    return this->cur;
}

class FiboProgression: public Progression{
    public:
        FiboProgression(int i = 0, int l = 1);
    protected:
        virtual long firstValue();
        virtual long nextValue();
        long second;
        long prev;
    private:
};
//we need a magical prev number for fibonacci, which essentially does not exist but is mandatory
FiboProgression::FiboProgression(int i, int l):Progression(i), second(l), prev(second-first){};
long FiboProgression::firstValue(){
    cur = first;
    prev = second-first;
    return cur;
}
long FiboProgression::nextValue(){
    long temp = prev;
    prev = cur;
    cur+=temp;
    return cur;
}

int main(){
    Progression* p1 = new Progression(10);
    ArithProgression* a2 = new ArithProgression(*p1, 10);
    GeoProgression* g2 = new GeoProgression(*p1, 3);
    FiboProgression* f2 = new FiboProgression(4, 6);
    p1->print(10);
    a2->print(10);
    g2->print(10);
    f2->print(10);
    return 0;
}