#!/usr/bin/env python

import person

#=====================================================================================

list_of_names = ['Roger', 'Mary', 'Luisa', 'Elvis']
list_of_ages  = [23, 24, 19, 86]
list_of_heights_cm = [175, 162, 178, 182]


for name in list_of_names:
	print("The name {:} is {:} letters long".format(name, len(name)))

#=====================================================================================

nameLenght_list = [len(name) for name in list_of_names]
	
for i in range(len(list_of_names)):
	print (f"The name {list_of_names[i]} have {nameLenght_list[i]} leters.")



people = {}
for i in range(len(list_of_names)):
	people[list_of_names[i]] = person.person(name = list_of_names[i], age = list_of_ages[i], height = list_of_heights_cm[i])

print(people)