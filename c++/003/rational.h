#ifndef	RATIONAL_H
#define	RATIONAL_H

class Rational{

    private:
        double value;
        double getValue();

    public:
        Rational(double a, double b);
        ~Rational();
        Rational add(Rational n);
        std::string print();
        Rational multiply(Rational n);
        Rational operator+(Rational n);
        Rational operator*(Rational n);

};

#endif