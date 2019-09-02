
SIZE=97

class HashTable:
    def __init__(self):
        self.array = [ None for i in range(SIZE)]

    def hash(self, key):
        return len(key) % (SIZE//2)

    def insert(self, key, value):
        index = self.hash(key)
        self.array[index] = value

    def search(self, key):
        index = self.hash(key)
        return self.array[index] if self.array[index] is not None else  "Chave `{}` nao existe".format(key)


    def delete(self, key):
        index = self.hash(key)
        self.array[index] = None
        return


if __name__ == "__main__":
    my_table = HashTable()

    my_table.insert("Roger", "Verdinho")

    print(my_table.search("Roger"))
    
    print(my_table.search("Kaique"))
    
    my_table.delete("Roger")
    
    print(my_table.search("Roger"))