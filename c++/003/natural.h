#include <stdlib.h>
#include <iostream>


class Natural{

    private:
        int value;
        int getValue();

    public:
        Natural(int v);
        ~Natural();
        Natural suc();
        Natural add(Natural n);
        std::string print();
        Natural multiply(Natural n);

};