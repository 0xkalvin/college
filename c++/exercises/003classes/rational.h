#ifndef	RATIONAL_H
#define	RATIONAL_H

class Rational{

    private:
        double value;
        double getValue();

    public:
        Rational(double a, double b);
        ~Rational();
        std::string print();
        Rational add(Rational n);
        Rational sub(Rational n);
        Rational mul(Rational n);
        Rational div(Rational n);
        Rational operator+(Rational n);
        Rational operator-(Rational n);
        Rational operator*(Rational n);
        Rational operator/(Rational n);

};

#endif