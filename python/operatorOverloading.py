#OPERATOR OVERLOADING IN PYTHON:

class Real:
    def __init__(self, n):
        self.value = n
    
    def getValue(self):
        return self.value

    # HOW TO USE PYTHON PRINT FUNCTION TO PRINT A  NATURAL INSTANCE 
    def __str__(self):
        return "{0}".format(self.value)

   # SETTING OPERATORS  
    def __add__(self, n):
        return self.value + n.getValue()

    def __sub__(self, n):
        return self.value - n.getValue() 
    
    def __mul__(self, n):
        return self.value * n.getValue() 
    
    def __truediv__(self, n):
        return self.value / n.getValue() 

   

n1 = Real(10)
n2 = Real(20)
sum = n1 + n2
sub = n1 - n2
mul = n1 * n2
div = n1 / n2

print(n1)
print(n2)
print(sum)
print(sub)
print(mul)
print(div)



