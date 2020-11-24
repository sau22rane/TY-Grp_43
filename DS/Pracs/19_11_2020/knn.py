def euclidean(a,b):
	sum=0
	for i in range(0,len(a)):
		check = type(b[i]) == str
		if(check): continue
		sum+=(a[i]-b[i])**2
	return (sum)**0.5
def getResult(k,l):
	d=dict()
	m=-1
	r=""
	for i in range(k):
		if l[i][1] in d:
			d[l[i][1]]+=1
		else:
			d[l[i][1]]=1
		if(m<d[l[i][1]]):
			m=d[l[i][1]]
			r=l[i][1]
	return r

def KNN(data,test,k):
	for i in test.values:
		print(i)
		l=[]
		for j in data.values:
			d=euclidean(i,j)
			t=(d,j[-1])
			l.append(t)
		l.sort()
		result=getResult(k,l)
		print(i[0]+"-----> "+result)	


import pandas as pd
import math

data=pd.read_csv("Data1.csv")
print(data)
test=pd.read_csv("Data2.csv")
print(test)

k=int(input("Enter value for k : "))
KNN(data,test,k)


