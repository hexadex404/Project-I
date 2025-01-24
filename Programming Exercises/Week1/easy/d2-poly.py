# Description
# Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
# Input
# Line 1 contains 3 positive integers a, b, c 
# Output
# Write NO SOLUTION if the given equation has no solution 
# Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
# Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 

# Example
# Input 
# 1 1 8
# Output 
# NO SOLUTION 


# Input 
# 1 -2 1
# Output
# 1.00

# Input 
# 1 -7 10
# Output 
# 2.00 5.00
import math
a, b, c = map(int, input().split())
check = b * b - 4 * a * c
if check > 0:
    x1 = (-b + math.sqrt(check)) / (2 * a)
    x2 = (-b - math.sqrt(check)) / (2 * a)
    if x1 < x2:
        print("{:.2f} {:.2f}".format(x1, x2))
    else:
        print("{:.2f} {:.2f}".format(x2, x1))
elif check == 0:
    x = -b / (2 * a)
    print("{:.2f}".format(x))
else:
    print("NO SOLUTION")