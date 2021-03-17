inp = [float(x) for x in input("Enter v0, v1, and t:").split()]
print("The average acceleration is", round((inp[1]-inp[0])/inp[2], 4))
