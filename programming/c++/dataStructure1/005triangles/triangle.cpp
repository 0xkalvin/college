#include "triangle.h"
#include <math.h>


Triangle::Triangle(double x, double y, double z){
    this->a = x;
    this->b = y;
    this->c = z;
    Triangle::numOfTriangles++;
}

Triangle::Triangle(){}

Triangle::~Triangle(){}

bool Triangle::isValid(){
    if(this->a + this->b > this->c && this->b + this->c > this->a && this->c + this->a > this->b) return true;
    else return false;
}

double Triangle::getPerimeter(){
    return this->a + this->b + this->c;
}

double Triangle::getArea(){
    double p1_half = this->getPerimeter()/2;
    return pow(p1_half*(p1_half - double(this->a))*(p1_half - double(this->b))*(p1_half - double(this->c)),0.5);
}

double Triangle::operator+(Triangle n){
        double area1 = this->getArea();
        double area2 = n.getArea();
        return area1 + area2;

}

bool Triangle::operator==(Triangle n){

        double area1 = this->getArea();
        double area2 = n.getArea();
        return area1 == area2;
    
}

bool Triangle::operator>(Triangle n){

        double area1 = this->getArea();
        double area2 = n.getArea();
        return area1 > area2; 
}


int Triangle::numOfTriangles = 0;


int Triangle::getNumOfTriangles(){
    return Triangle::numOfTriangles;
}
