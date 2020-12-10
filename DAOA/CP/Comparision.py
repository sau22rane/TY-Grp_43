import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
plt.rcParams["figure.figsize"] = (10,6)
fox_data = []
cannon_data = []
simple_matrix_data = []
order = []
i = 4
with open('fox_data.txt','r') as file:
    for line in file:
        j = 0
        sum = 0
        for word in line.split():
            j+=1
            sum+=float(word)
            if(j==4):
                fox_data.append(sum/j)
                order.append(i)
                i+=4
                j=0
                sum = 0
    file.close()

with open('cannon_data.txt','r') as file:
    for line in file:
        j = 0
        sum = 0
        for word in line.split():
            j+=1
            sum+=float(word)
            if(j==4):
                cannon_data.append(sum/j)
                j=0
                sum = 0
    file.close()

with open('simple_matrix_data.txt','r') as file:
    for line in file:
        for word in line.split():
            simple_matrix_data.append(float(word))
    file.close()

strassen_data = []
oreder = []
i = 4
with open('strassen_data.txt','r') as file:
    for line in file:
        for word in line.split():
            strassen_data.append(float(word))
            oreder.append(i)
            i+=4
    file.close()

plt.plot(order,fox_data,'r')
plt.plot(order,cannon_data,'b')
plt.plot(order,simple_matrix_data,'g')
plt.plot(oreder,strassen_data,'y')
plt.title("Execution Time for Fox and Cannon")
plt.ylabel("Time (in sec)")
plt.xlabel("Order of Matrix (n,n)")
red_patch = mpatches.Patch(color='red', label='Fox Algorithm')
blue_patch = mpatches.Patch(color='blue', label='Cannon Algorithm')
green_patch = mpatches.Patch(color='green', label='Normal Multiplication')
yellow_patch = mpatches.Patch(color='yellow', label='Stression Algorithm')
plt.legend(handles=[green_patch, yellow_patch, red_patch, blue_patch])

plt.show()
