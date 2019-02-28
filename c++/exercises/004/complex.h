#ifndef	COMPLEX_H
#define	COMPLEX_H

class Complex{

    private:
        double real;
        double imaginary;

    public:
        Complex(double real, double imaginary);
        ~Complex();
        double getReal();
        double getImaginary();
        Complex operator+(Complex n);
        Complex operator-(Complex n);
        Complex operator*(Complex n);
        Complex operator/(Complex n);
        friend std::ostream &operator<<(std::ostream &os, Complex &n);
};

#endif