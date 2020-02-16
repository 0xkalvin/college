#include "hashtable.h"



int main(void){

    HashTable table(100);

    for(int i = 0; i < 101; i++){
        table.insert(i, i*i);
    }

    std::cout << std::boolalpha << table.search(0) <<std::endl;
    std::cout << std::boolalpha << table.search(10) <<std::endl;
    std::cout << std::boolalpha << table.search(100) <<std::endl;
    std::cout << std::boolalpha << table.search(1000) <<std::endl;


    return 0;
}