#ifndef	COMPLEX_H
#define	COMPLEX_H

class Complex{

    private:
        double real;
        double imaginary;
        double getValue();

    public:
        Complex(double real, double imaginary);
        ~Complex();
        double getReal();
        double getImaginary();
        Complex add(Complex n);
        Complex sub(Complex n);
        Complex mul(Complex n);
        Complex operator+(Complex n);
        Complex operator-(Complex n);
        Complex operator*(Complex n);
};

#endif