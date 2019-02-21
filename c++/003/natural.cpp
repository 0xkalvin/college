#include <stdlib.h>
#include <iostream>
#include "natural.h"

using namespace std;

Natural::Natural(int v){
	this->value = v;
}

Natural::~Natural(){}

int Natural::getValue(){
    return value;
}

string Natural::print(){
    return to_string(value);
}

Natural Natural::suc(){
    Natural n(value + 1);
    return n;
}

Natural Natural::add(Natural n){
    Natural s(value + n.getValue());
    return s;
}

Natural Natural::mul(Natural n){
    Natural m(value * n.getValue());
    return m;
}


Natural Natural::operator+(Natural n){
    Natural sum(value + n.getValue());
    return sum;
}



Natural Natural::operator*(Natural n){
    Natural m(value * n.getValue());
    return m;
}
