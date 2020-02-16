
CONST_PRIME = 2049

class Node:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None


class HashTable:
    def __init__(self):
        self.array = [ None for i in range(CONST_PRIME)]

    def hash(self, key):
        ''' Takes text passed and build an index, 
        by adding each character ASCII value multiplied by its position in the string '''

        sum_ascii_characters = 0
        for i in range(len(key)):
            sum_ascii_characters += ord(key[i]) * (i + 1)
        return (sum_ascii_characters % CONST_PRIME)

    def insert(self, key, value):
        ''' Insert a new node at index. Each index is a linked list'''

        index = self.hash(key)
        new_node = Node(key, value)
        if self.array[index] is None:    
            self.array[index] = new_node
            return
        else:
            temp = self.array[index] 
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node
            return
            

    def search(self, key):
        ''' Goes to an index and searches for the specified key in the linked list'''
        
        index = self.hash(key)
        if self.array[index] is None:
            return "Chave `{}` nao existe".format(key)
        else:
            temp = self.array[index]
            while temp is not None:
                if temp.key == key:
                    return temp.value
                temp = temp.next
            return "Chave `{}` nao existe".format(key)


    # def delete(self, key):
    #     index = self.hash(key)
    #     self.array[index] = None
    #     return


if __name__ == "__main__":
   
    my_table = HashTable()

    my_table.insert("Roger", "Verdinho")

    print(my_table.search("Roger"))
    print(my_table.search("Kaique"))
    
    