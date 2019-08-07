#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle{

    private:
        double a,b,c;
    
    public:
        Triangle(double a, double b, double c);
        Triangle();
        ~Triangle();
        bool isValid();
        double operator+(Triangle n);
        bool operator==(Triangle n);
        bool operator>(Triangle n);
        double getPerimeter();
        double getArea();
        static int numOfTriangles;
        int getNumOfTriangles();
};



#endif