# Description
# Given a time moment which is a string under the format hh:mm:ss (in which hh (0 <= hh <= 23) is the hour, mm (0 <= mm <= 59) is the minute, and ss (0 <= ss <= 59) is the second). Convert this time moment in seconds (result = hh*3600 + mm*60 + ss).
# Input
# Line 1: contains a string s representing the time moment.  
# Output
# if s is not under the format hh:mm:ss, then write INCORRECT. Otherwise, write value converted.

# Example
# Input
# 13:05:26

# Output
# 47126


# Input
# 13:05:6

# Output
# INCORRECT 

# Input
# 13:05 26

# Output
# INCORRECT

input = input().split(':')
while True:
    if len(input) != 3:
        print('INCORRECT')
        break
    elif len(input[0]) != 2 or len(input[1]) != 2 or len(input[2]) != 2:
        print('INCORRECT')
        break
    elif input[0] > '23' or input[0] < '00' or input[1] > '59' or input[1] < '00' or input[2] > '59' or input[2] < '00':
        print('INCORRECT')
        break
    answer = int(input[0]) * 3600 + int(input[1]) * 60 + int(input[2])
    print(answer)
    break