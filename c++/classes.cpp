#include <iostream>
using namespace std;


class Animal{
    private:
        string name;
        double height;
        double weight;
        // static allows this attribute having the same value for all instancies of the animal class
        // if this number changes, it changes for all instancies
        static int numOfAnimals;
    
    public:
        string getName(){
            return name;
        };
        void setName(string name){
            this->name = name;
        }
        double getHeight(){
            return height;
        }
        void setHeight(double height){
            this->height = height;
        }
        void setAll(string, double, double);
        static int getNumOfAnimals(){
            return numOfAnimals;
        }
        // constructor
        Animal(string, double, double);
        Animal();
        ~Animal();

};

int Animal::numOfAnimals = 0;

void Animal::setAll(string name, double height, double weight){
    this->name = name;
    this->height = height;
    this->weight = weight;
    Animal::numOfAnimals++;
};

Animal::Animal(string name, double height, double weight){
    this->name = name;
    this->height = height;
    this->weight = weight;
    Animal::numOfAnimals++;
}
Animal::Animal(){
    this->name = "";
    this->height = "";
    this->weight = "";
    Animal::numOfAnimals++;
}




class Dog: public Animal{
    private:
        string sound = "Woof!";
    
    public:
        void makeSound(){
            cout << "Dog " << this->getName() << " says " << this->sound<<endl;
        }
        Dog(string, double, double, string);
        Dog(): Animal(){};


}


