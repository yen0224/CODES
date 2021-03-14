# coding=UTF-8
# solution to ex4-22
x,y=input("Enter a point with two coordinates:").split(" ")
x=eval(x)
y=eval(y)
print("Point (",x,",",y,")","is" if x**2+y**2<=100 else "is not","in the circle.")