class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def insert(node, value):
    if node is None:
        return Node(value)
    if value < node.value:
        node.left = insert(node.left, value)
    elif value > node.value:
        node.right = insert(node.right, value)
    return node

def search(node, value):
    if node is None or node.value == value:
        return node
    if value < node.value:
        return search(node.left, value)
    return search(node.right, value)

def preorder(node):
    if node is not None:
        print(node.value, end=" ")
        preorder(node.left)
        preorder(node.right)
node = None
while True:
    cmd = input().split()
    if cmd[0] == "insert" and node is None:
        node = insert(node, int(cmd[1]))
    elif cmd[0] == "insert":
        insert(node, int(cmd[1]))
    elif cmd[0] == "#":
        preorder(node)
        break


    