# Description
# Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
# find-max: return the maximum element of the given sequence
# find-min: return the minimum element of the given sequence 
# sum: return the sum of the elements of the given sequence 
# find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

# Input
# The first block contains the information about the given sequence with the following format:
# Line 1: contains a positive integer n (1 <= n <= 10000)
# Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
# The first block is terminated by a character *
# The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

# Output
# Write the result of each query in a corresponding line
 
# Example
# Input
# 5
# 1 4 3 2 5
# *
# find-max
# find-min
# find-max-segment 1 3
# find-max-segment 2 5
# sum
# ***

while True:
        n = int(input())
        arr = list(map(int, input().split()))
        block_termi = input()
        while True:
            query = input().split()
            if query == ['***']:
                break
            while len(query) == 1:
                if query[0] == "find-max":
                    print(max(arr))
                    break
                elif query[0] == "find-min":
                    print(min(arr))
                    break
                elif query[0] == "sum":
                    print(sum(arr))
                    break
                else:
                    break
            while len(query) == 3:
                if query[0] == "find-max-segment":
                    print(max(arr[int(query[1])-1:int(query[2])]))
                    break
                if query[0] == "find-min-segment":
                    print(min(arr[int(query[1])-1:int(query[2])]))
                    break

        break
