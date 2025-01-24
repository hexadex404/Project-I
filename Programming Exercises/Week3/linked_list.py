class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def searchNode(self, data):
        currentNode = self.head
        while currentNode:
            if currentNode.data == data:
                return currentNode
            currentNode = currentNode.next
        return None

    def addFirst(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        else:
            newNode.next = self.head
            self.head = newNode

    def addLast(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        currentNode = self.head
        while currentNode.next:
            currentNode = currentNode.next
        currentNode.next = newNode

    def addAfter(self, prevData, data):
        newNode = Node(data)
        prevNode = self.searchNode(prevData)
        newNode.next = prevNode.next
        prevNode.next = newNode
    
    def addBefore(self, nextData, data):
        newNode = Node(data)
        nextNode = self.searchNode(nextData)
        currentNode = self.head
        while currentNode.next != nextNode:
            currentNode = currentNode.next
        currentNode.next = newNode
        newNode.next = nextNode

    
    def remove(self, data):
        currentNode = self.head
        prevNode = None
        while currentNode:
            if currentNode.data == data:
                if prevNode:
                    prevNode.next = currentNode.next
                else:
                    self.head = currentNode.next
                return
            prevNode = currentNode
            currentNode = currentNode.next
            
    
    def reverse(self):
        currentNode = self.head
        prevNode = None
        while currentNode:
            nextNode = currentNode.next
            currentNode.next = prevNode
            prevNode = currentNode
            currentNode = nextNode
        self.head = prevNode

    def print(self):
        currentNode = self.head
        while currentNode:
            print(currentNode.data, end = " ")
            currentNode = currentNode.next
    
n = int(input())
arr = list(map(int, input().split()))
ll = LinkedList()
for i in range(n):
    ll.addLast(arr[i])
while True:
    temp = ll.head
    v = []
    while temp:
        v.append(temp.data)
        temp = temp.next
    query = input().split()
    if query[0] == "addlast":
        if int(query[1]) in v:
            pass
        else:
            ll.addLast(int(query[1]))
    elif query[0] == "addfirst":
        if int(query[1]) in v:
            pass
        else:
            ll.addFirst(int(query[1]))
    elif query[0] == "addafter":
        if int(query[1]) in v:
            pass
        else:
            ll.addAfter(int(query[2]), int(query[1]))
    elif query[0] == "addbefore":
        if int(query[1]) in v:
            pass
        else:
            ll.addBefore(int(query[2]), int(query[1]))
    elif query[0] == "remove":
        if int(query[1]) not in v:
            pass
        ll.remove(int(query[1]))
    elif query[0] == "reverse":
        ll.reverse()
    elif query[0] == "#":
        ll.print()
        break

