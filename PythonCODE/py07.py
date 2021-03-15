# coding=UTF-8
import math
def mean(x,size):
    sum=0.
    for i in x:
        sum+=i
    Me=sum/size
    return Me

def deviation(x,size):
    Me=mean(x,size)
    squareDev=0.
    for i in x:
        squareDev+=(i-Me)**2
    dev=math.sqrt(squareDev/(size-1))
    return dev

inp=[float(x) for x in input("Enter 10 numbers:").split(" ")]
print("The mean is","%.4f"%(mean(inp,10)))
print("The standard deviation is","%.4f"%(deviation(inp,10)))