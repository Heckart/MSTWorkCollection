# Programmer: Ethan Heckart
# File: 1200PaperHomework4.py
# Date: 4/13/22
# Purpose: program for paper homework 4

def altDiff(Nums):
    listLen = len(Nums)
    
    if listLen == 1: # function is done and the final element is the answer
        return Nums[0]

    else:
        difference = 0
        difference = Nums[listLen-2] - Nums[listLen-1] # difference equals second to last term minus the last term
        Nums.pop(listLen-1) # remove the two terms that were just used from the list
        Nums.pop(listLen-2)
        Nums.append(difference) # add the difference of the two terms to the end of the list
        return altDiff(Nums) # perform the function again recursively

myList = [17,5,8,10]

print(altDiff(myList))
        
