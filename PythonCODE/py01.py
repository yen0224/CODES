current_amount = 312032486
yearSecound = 31536000
print("Current population is",current_amount)
for i in range(1,6):
    print("After",i,"year, the population will be",current_amount+i*yearSecound//7-i*yearSecound//13+i*yearSecound//45 )