# Description
# Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

# Input
# The Text

# Output
# Write the number Q of words

# Example
# Input
# Hanoi University Of Science and Technology
# School of Information and Communication Technology


# Output
# 12
words = 0
while True:
    try:
        string = input().split()
        words += len(string)
    except EOFError:
        break
print(words)