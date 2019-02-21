#include <stdlib.h>
#include <iostream>


class Integer{

    private:
        int value;
        int getValue();

    public:
        Integer(int v);
        ~Integer();
        Integer suc();
        Integer add(Integer n);
        std::string print();
        Integer multiply(Integer n);
        Integer operator+(Integer n);

};