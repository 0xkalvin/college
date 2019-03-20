#include "triangle.h"


Triangle::Triangle(double x, double y, double z){
    this->a = x;
    this->b = y;
    this->c = z;
}

Triangle::~Triangle(){}

bool Triangle::isValid(){
    if(this->a + this->b > this->c && this->b + this->c > this->a && this->c + this->a > this->b) return true;
    else return false;
}

double Triangle::operator+(Triangle n){
    
}