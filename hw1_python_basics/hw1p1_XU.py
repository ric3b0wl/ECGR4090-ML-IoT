#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt

# pip install numpy matplotlib
# conda install numpy matplotlib

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

# print(people)


# numpy as np
ary_age = np.array(list_of_ages)
ary_height_cm = np.array(list_of_heights_cm)

age_avg = np.mean(list_of_ages)  # ().mean -> average function(Python statistics)
height_avg = np.mean(ary_height_cm)

print (f"the average age is: {age_avg}")
print (f"the average height is: {height_avg}")


# matplotlib as plt
plt.scatter(ary_age, ary_height_cm)
plt.grid(True)

plt.xlabel('age')
plt.ylabel('hgith in cm')
plt.title("age vs height(cm)")

plt.savefig("./age-vs-height_plot.jpg")
plt.show()