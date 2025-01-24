# Problem: Tree manipulation & Traversal
# Description
# Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
# Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
# · MakeRoot u: Tạo ra nút gốc u của cây
# · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
# · PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
# · InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
# · PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
# Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
# Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
# Ví dụ
# Dữ liệu
# MakeRoot 10
# Insert 11 10
# Insert 1 10
# Insert 3 10
# InOrder
# Insert 5 11
# Insert 4 11
# Insert 8 3
# PreOrder
# Insert 2 3
# Insert 7 3
# Insert 6 4
# Insert 9 4
# InOrder
# PostOrder
# *
# Kết quả
# 11 10 1 3
# 10 11 5 4 1 3 8
# 5 11 6 4 9 10 1 8 3 2 7
# 5 6 9 4 11 1 8 2 7 3 10

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

def preOrder(root):
    if root == None:
        return
    print(root.data, end = " ")
    for i in range(len(root.children)):
        preOrder(root.children[i])

def inOrder(root):
    if root == None:
        return
    if len(root.children) == 0:
        print(root.data, end = " ")
    else:
        inOrder(root.children[0])
        print(root.data, end = " ")
        for i in range(1, len(root.children)):
            inOrder(root.children[i])

def postOrder(root):
    if root == None:
        return
    for i in range(len(root.children)):
        postOrder(root.children[i])
    print(root.data, end = " ")

root = None
while True:
    query = input().split()
    if query[0] == "MakeRoot":
        makeRoot(int(query[1]))
    elif query[0] == "Insert":
        insert(int(query[1]), int(query[2]))
    elif query[0] == "PreOrder":
        preOrder(root)
        print()
    elif query[0] == "InOrder":
        inOrder(root)
        print()
    elif query[0] == "PostOrder":
        postOrder(root)
        print()
    elif query[0] == "*":
        break
