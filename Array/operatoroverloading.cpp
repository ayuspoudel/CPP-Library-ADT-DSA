#include<iostream>
#include<string>

class Complex{
    int real;
    int imaginary;

    public:
        Complex(int real=0, int imaginary=0){
            this->real = real;
            this->imaginary = imaginary;
        }
        Complex operator+(Complex const &c){
            Complex res;
            res.real = real+c.real;
            res.imaginary = imaginary + c.imaginary;
            return res;
        }
        Complex operator-(Complex const &c){
            Complex res;
            res.real = real-c.real;
            res.imaginary = imaginary - c.imaginary;
            return res;
        }
        Complex operator*(Complex const &c){
            Complex res;
            res.real = (real * c.real) - (imaginary * c.imaginary);
            res.imaginary = (real * c.imaginary) + (imaginary * c.real);
            return res;
        }

        static void print(Complex const c){
            std::cout<<c.real<<" + "<<c.imaginary<<"i"<<std::endl;
        }
};

int main(){
    Complex c3;
    Complex c1(5, 9);
    Complex c2(1, 1);
    std::cout<<"C1 = ";
    Complex::print(c1);
    std::cout<<"C2 = ";
    Complex::print(c2);
    std::cout<<"C1 + C2 = ";
    c3 = c1+c2;
    Complex::print(c3);
    std::cout<<"C1 - C2 = ";
    c3 = c1-c2;
    Complex::print(c3);
    std::cout<<"C1 * C2 = ";
    c3 = c1*c2;
    Complex::print(c3);
    return 0;
}