# coding=UTF-8
# this is the solution to ex3-05
# written by chiayen hsu S0951037
# last edited 3/14
import math
side_N=eval(input("Enter the number of sides: "))
side=eval(input("Enter the side:"))
print("The area of the polygon is","%.4f" % (side_N*(side**2)/(4*math.tan(math.pi/side_N))))