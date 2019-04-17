clear

cd exercises/006array

file="main.cpp"

g++ ${file} array.cpp ../004inheritance/real.cpp ../004inheritance/complex.cpp ../003classes/natural.cpp ../003classes/integer.cpp ../003classes/rational.cpp

./a.out
