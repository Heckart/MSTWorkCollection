# Programmer: Ethan Heckart
# Date: 2/8/22
# File: 1200PaperHomework3.py
# Purpose: 

def EuclideanAlgorithm(num1, num2):
    temp = num2
    num2 = num1%num2
    num1 = temp
    while num1%num2 != 0:
        temp = num2
        num2 = num1%num2
        num1 = temp
    return num2

print(EuclideanAlgorithm(506563200, 1758120))