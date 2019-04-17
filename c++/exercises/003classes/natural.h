#ifndef	NATURAL_H
#define	NATURAL_H

class Natural{

    private:
        int value;
        int getValue();

    public:
        Natural(int v);
        ~Natural();
        std::string print();
        Natural suc();
        Natural add(Natural n);
        Natural mul(Natural n);
        Natural operator+(Natural n);
        Natural operator*(Natural n);
        friend std::ostream &operator<<(std::ostream &os, Natural &n);

};

#endif