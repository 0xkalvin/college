


# cartesian product
a = [2,4,6,8]
b = [1,3,5,7]
cartesian_product = [(i,j) for i in a for j in b]
print(cartesian_product)


primes = [i for i in range(2,101) if all(i % j != 0 for j in range(2,i))]
print(primes)


matrix = [[j for j in range(3)] for i in range(5)]
print(matrix)
