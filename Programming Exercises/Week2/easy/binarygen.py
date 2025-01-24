# Description
# Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
# Input
# Line 1: contains an integer n (1 <= n <= 20)
# Output
# Write binary sequences in a lexicographic ordder, eac sequence in a line

# Example
# Input
# 3
# Output
# 000
# 001
# 010
# 011
# 100
# 101
# 110
# 111
def sequence(n, arr, i):
    if i == n:
        for i in range(0,n):
            print(arr[i], end="")
        print()
        return
    arr[i] = 0
    sequence(n, arr, i+1)
    arr[i] = 1
    sequence(n, arr, i+1)


length = int(input())
arr = [None] * length
sequence(length, arr , 0)
