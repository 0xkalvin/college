import random

# hello world lambda expression
my_anon_func = lambda name: "hello, " + name

# concat two strings to make a formatted name 
format_name = lambda fn, ln: fn.strip().title() + " " + ln.strip().title()

#  sort list of strings by last name 
names = ["Jack BLACK", "robert New", "JOHN brown"]
names.sort(key=lambda name:name.split(" ")[-1].lower())

# function to generate functions
def build_quadratic_function(a,b,c):
    return lambda x: a*x**2 + b*x + c

# USAGE:
# func1 = build_quadratic_function(1,2,3)
# func1(0)

# how to use if statement in it
parity = lambda x: "Par" if x % 2 == 0 else "Impar"

# how to use with a bunch of shit
isPrime = lambda x: "Not Prime" if len([i for i in range(1,x//2 + 1) if x % i == 0] ) > 1 else "Prime"

# trying to be recursive
fatorial = lambda n: 1 if n < 2 else n*fatorial(n-1)

fib = lambda n: n if n < 2 else fib(n-2) + fib(n-1)


create_matrix = lambda l, c: [[random.randint(0,100) for i in range(c)] for j in range(l)]
