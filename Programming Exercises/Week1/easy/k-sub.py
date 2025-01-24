
# Description
# Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
# Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is even.
# Input
# Line 1: contains 2 positive integers n, k (1 <= n <= 100000, 1 <= k <= n/2)
# Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
# Output
# Write the value Q
# Example
# Input
# 6  3
# 2 4 5 1 1 2 
# Output
# 2

n,k = input().split()
total = 0

arr = list(map(int, input().split()))
sum = 0
for i in range(int(k)):
    sum += arr[i]
if sum % 2 == 0:
    total += 1
for i in range(1, int(n)-int(k)+1):
    sum = sum - arr[i-1] + arr[i+int(k)-1]
    if sum % 2 == 0:
        total += 1
print(total)