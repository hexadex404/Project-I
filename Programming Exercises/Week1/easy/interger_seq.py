# Description
# Given a positive integer n, find all integer having 3 digits which is divisible by n.
# Input
# Line 1: contains a positive integer n (1 <= n <= 999)
# Output
# Write the sequence of numbers found (elements are separated by a SPACE character)

# Example
# Input 
# 200

# Output 
# 200 400 600 800

i = int(input())
arr = []
for j in range(100, 1000):
    if j % i == 0:
        arr.append(j)
print(*arr)