# Programmer: Ethan Heckart
# Date: 2/22/22
# File: 1200PaperHomework2.py

people = ["Bob", "Dave", "John"]
jobs = ["1", "2", "3"]

jobs_dont_know = [("1", "3")]

people_dont_know = [("John", "Bob")]

dictionary = {}

for i in people:                                # This loop assigns people and possible jobs to a dictionary for use later
    if i in people_dont_know:
        dictionary[i]=list(jobs_dont_know)
    else:
        temp_list=[]
        for a in jobs:
            if a not in jobs_dont_know:
                temp_list.append(a)
            dictionary[i]=temp_list

salary = [("1", 1), ("3", 0)]

upper_index = 0
for i in salary:                                
    if i[1]>0:
        upper_index = salary.index(i)
    else:
        a=1

dictionary["John"]=list(salary[upper_index][0])
dictionary["Dave"]=list(salary[a][0])

for i,j in dictionary.items():                 # This loop assigns the job based on the possible option associated with each name in the dictionary
    if '1' in j and '2' not in j and '3' not in j:
        print(i, "is the carpenter")
    elif '2' in j:
        print(i, "is the painter")
    elif '3' in j:
        print(i, "is the plumber")