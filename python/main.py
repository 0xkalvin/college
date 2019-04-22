import random

# SORT ALGORITHM
def selection_sort(l):
    for i in range(len(l)):
        min = i
        for j in range(i+1, len(l)):
            if l[min] > l[j]:
                min = j
        temp = l[min]
        l[min] = l[i]
        l[i] = temp
    return l

def merge_sort(l):
    if len(l) < 2:
        return l
    mid = len(l) // 2
    left = merge_sort(l[:mid])
    right = merge_sort(l[mid:])
    return merge(left,right)

def merge(left, right):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result += left[i:]
    result += right[j:]
    return result 

def bubble_sort(list):
    for i in range(len(list)):
        for j in range(len(list)-1):
            if list[j] > list[j+1]:
                temp = list[j]
                list[j] = list[j+1]
                list[j+1] = temp
    return list
# =====================================================

def sum_digits(string):
    return sum([int(n) for n in string])

def fib1(n):
    a = 0
    b = 1
    current = 0
    arr = [a,b]
    for i in range(n-2):
        current = a + b
        a = b
        b = current
        arr.append(current)
    return current, arr

def fib2(n):
    return n if n <= 1 else fib2(n-1) + fib2(n-2)

def fat(n):
    return 1 if n<=1 else n*fat(n-1)

def palindrome(string):
    return string == string[::-1]

def create_list(n):
    return [random.randint(0,100) for i in range(n)]

def create_matrix(line,column):
    return [[random.randint(0,100) for i in range(column)] for j in range(line)]
