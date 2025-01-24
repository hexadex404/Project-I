# Description
# Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
# descendants <name>: return number of descendants of the given <name>
# generation <name>: return the number of generations of the descendants of the given <name>

# Note that: the total number of people in the family is less than or equal to 10
# 4
# Input
# Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
# Output
# Each line is the result of a corresponding query.
# Example
# Input
# Peter Newman
# Michael Thomas
# John David
# Paul Mark
# Stephan Mark
# Pierre Thomas
# Mark Newman
# Bill David
# David Newman
# Thomas Mark
# ***
# descendants Newman
# descendants Mark
# descendants David
# generation Mark
# ***
# Output
# 10
# 5
# 2
# 2

class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

def makeRoot(u):
    global root
    root = Node(u)

def insert(u, v):
    global root
    if search(root, u) != None or search(root, v) == None:
        return
    else:
        search(root, v).children.append(Node(u))

def search(root, u):
    if root == None:
        return None
    if root.data == u:
        return root
    for i in range(len(root.children)):
        temp = search(root.children[i], u)
        if temp != None:
            return temp
    return None

def decendants(root, u):
    if root == None:
        return 0
    if root.data == u:
        return len(root.children)
    for i in range(len(root.children)):
        temp = decendants(root.children[i], u)
        if temp != 0:
            return temp
    return 0

def generation(root, u):
    if root == None:
        return 0
    if root.data == u:
        return 1
    for i in range(len(root.children)):
        temp = generation(root.children[i], u)
        if temp != 0:
            return temp + 1
    return 0

root = None
while True:
    query = input().split()
    if query[0] == "***":
        break
    else:
        if root == None:
            makeRoot(query[1])
        insert(query[0], query[1])

while True:
    query = input().split()
    if query[0] == "***":
        break
    else:
        if query[0] == "descendants":
            print(decendants(root, query[1]))
        elif query[0] == "generation":
            print(generation(root, query[1]))


