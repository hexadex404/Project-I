i = input()
arr = input().split()
odd = 0
even = 0
for j in range(int(i)):
    if int(arr[j]) % 2 == 0:
        even += 1
    else:
        odd += 1

print(f"{odd} {even}")