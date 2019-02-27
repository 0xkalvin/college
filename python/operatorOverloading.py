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
    
    def __pow__(self, n):
        half = 0.5
        if n.getValue() == half:
            if self.value  < 0:
                return "That`s not a real number"
        
        return self.value ** n.getValue()

   

n1 = Real(10)
n2 = Real(20)
n3 = Real(-10000)
n4 = Real(0.5)

sum = n1 + n2
sub = n1 - n2
mul = n1 * n2
div = n1 / n2
power1 = n1 ** n4
power2 = n3 ** n4


print(n1)
print(n2)
print(sum)
print(sub)
print(mul)
print(div)
print(power1)
print(power2)



