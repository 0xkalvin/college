#include <stdlib.h>
#include <iostream>
#include "integer.h"

using namespace std;

Integer::Integer(int v){
	this->value = v;
}

Integer::~Integer(){}

int Integer::getValue(){
    return value;
}

Integer Integer::suc(){
    Integer n(value + 1);
    return n;
}

Integer Integer::add(Integer n){
    Integer sum(value + n.getValue());
    return sum;
}

string Integer::print(){
    return to_string(value);
}

Integer Integer::multiply(Integer n){
    Integer m(value * n.getValue());
    return m;
}