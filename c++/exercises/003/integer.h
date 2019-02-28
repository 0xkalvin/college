#include <stdlib.h>
#include <iostream>


class Integer{

    private:
        int value;
        int getValue();

    public:
        Integer(int v);
        ~Integer();
        std::string print();
        Integer suc();
        Integer add(Integer n);
        Integer mul(Integer n);
        Integer operator+(Integer n);
        Integer operator*(Integer n);


};