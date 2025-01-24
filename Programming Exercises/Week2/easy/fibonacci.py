# Take an int n as input and print the nth fibonacci number.

n = int(input())
a = 0
b = 1
for i in range(n-1):
    buf = b
    b = a + b
    a = buf
print(a)