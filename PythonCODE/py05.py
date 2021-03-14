# coding=UTF-8
import math
inp=[float(x) for x in input().split(" ")]
sum=0.
devsum=0.
for i in inp:
    sum=sum+i
avg=sum/10
for j in inp:
    devsum=devsum+(j-avg)**2
print("The mean is",avg)
print("The standard deviation is","%.4f"%(math.sqrt(devsum/9)))