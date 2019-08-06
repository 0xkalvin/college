
# TREE TRAVERSAL 

class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


def print_post_order(root):
    # left -> right -> root
    if root:
        print_post_order(root.left)
        print_post_order(root.right)
        print(root.data)


def print_pre_order(root):
    # Root -> Left -> Right
    if root:
        print(root.data)
        print_pre_order(root.left)
        print_pre_order(root.right)

def print_in_order(root):
    # left -> root -> right
    if root:
        print_in_order(root.left)
        print(root.data, end=" ")
        print_in_order(root.right)

def main():
    root = Node(10)
    root.left = Node(5)
    root.right = Node(4)
    root.left.left = Node(1)
    root.left.right = Node(0)
    print("POST ORDER")
    print_post_order(root)
    print("PRE ORDER")
    print_pre_order(root)
    print("IN ORDER")
    print_in_order(root)

def expression():
        root = Node("*")
        root.left = Node("/")
        root.right = Node("+")
        root.right.left = Node("e")
        root.right.right = Node("f")
        root.left.left = Node("+")
        root.left.right = Node("-")
        root.left.left.left = Node("a")
        root.left.left.right = Node("b")
        root.left.right.left = Node("c")
        root.left.right.right = Node("d")

        print("IN ORDER")
        print_in_order(root)

expression()