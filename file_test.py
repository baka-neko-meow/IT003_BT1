import random 
import numpy as np

random.seed(1210)  

with open("input.txt", "w") as output:
    
    lst = [random.randint(-100000000, 100000000) / 100 for i in range(1000000)]
    lst = np.sort(lst)

    for number in lst: 
        output.write(str(number) + ' ')

    output.write('\n')

    lst = [random.randint(-100000000, 100000000) / 100 for i in range(1000000)]
    lst = np.sort(lst)
    lst = lst[::-1]

    for number in lst: 
        output.write(str(number) + ' ')

    output.write('\n')

    for i in range(8):
        for j in range(1_000_000):
            output.write(str(random.randint(-1000000000, 100000000) / 100) + ' ')
        output.write('\n')
#create file_test and input.txt
