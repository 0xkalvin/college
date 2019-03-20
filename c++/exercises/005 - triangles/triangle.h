#ifndef TRIANGLE_H
#define TRIAGLE_H

class Triangle{

    private:
        double a,b,c;
    
    public:
        Triangle(double a, double b, double c);
        ~Triangle();
        bool isValid();
        double operator+(Triangle n);
        bool operator==(Triangle n);
        bool operator>(Triangle n);

};



#endif