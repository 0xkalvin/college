

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



lista = [9,1,54,2,2,5]
print(bubble_sort(lista))