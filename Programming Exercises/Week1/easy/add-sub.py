# Description
# Given 2 integers a and b. Compute a+b, a-b, a*b, a/b.
# Input
# Line 1 contains 2 integers a and b (1 <= a,b <= 1000)
# Output
# Write a+b, a-b, a*b, a/b  (4 integers are separated by a SPACE characters)

# Example
# Input
# 9 4
import math
a,b = map(int, input().split())
add = a + b
sub = a - b
mul = a * b
div = a / b
print(add, sub, mul, math.floor(div))