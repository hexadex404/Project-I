# Description
# Given a date which is a string under the format YYYY-MM-DD (in which YYYY is the year, MM is the month (the month í from 1 to 12), and DD is the date (the date is from 1 to 31)). Extract the year, month and date.
# Input
# Line 1: contains a string s  
# Output
# if s is not under the format YYYY-MM-DD, then write INCORRECT. Otherwise, write year, month, and date separated by a SPACE character

# Example
# Input
# 2023-10-04
# Output
# 2023 10 4


# Input
# 2023-10-4
# Output
# INCORRECT 

# Input
# 2023-10 04
# Output
# INCORRECT

input = input().split('-')
while True:
    if len(input) != 3:
        print('INCORRECT')
        break
    elif len(input[0]) != 4 or len(input[1]) != 2 or len(input[2]) != 2:
        print('INCORRECT')
        break
    elif input[1] > '12' or input[1] < '01':
        print('INCORRECT')
        break
    elif input[2] > '31' or input[2] < '01':
        print('INCORRECT')
        break
    if input[1][0] == '0':
        input[1] = input[1][1]
    if input[2][0] == '0':
        input[2] = input[2][1]

    print(*input)
    break

