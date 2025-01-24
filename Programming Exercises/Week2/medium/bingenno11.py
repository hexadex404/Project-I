# Description
# Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
# Input
# Line 1: contains an integer n (1 <= n <= 20)
# Output
# Write binary sequences in a lexicographic order, each sequence in a line
# Example
# Input
# 3
# Output
# 000
# 001
# 010
# 100
# 101

def biniterate(n, arr, i):
    check = True
    while i < n and i > 0:
        if arr[i] == 1 and arr[i-1] == 1:
            check = False
            break
        else:
            break
    if i == n and check:
        for i in range(0,n):
            print(arr[i], end="")
        print()
        return    
    if i > n:
        return
    arr[i] = 0
    biniterate(n, arr, i+1)
    arr[i] = 1
    biniterate(n, arr, i+1)

n = int(input())
arr = []
for i in range(0,n):
    arr.append(0)
biniterate(n, arr, 0)

