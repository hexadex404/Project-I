# Description
# Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
# Input
# Line 1: two positive integers k and n (1 <= k,n <= 999)
# Output
# Write te value C(k,n) modulo 10^(9)+7
# Example
# Input
# 3  5
# Output
# 10

mod = 10**9 + 7

from functools import reduce
from operator import mul
from fractions import Fraction  


def nCk(n, k):
    return int(
        reduce(
            mul,
            (Fraction(n - i, i + 1) for i in range(k)),
            1,
        )
    )
n,k = input().split()
k = int(k)
n = int(n)
print(nCk(k,n) % mod)