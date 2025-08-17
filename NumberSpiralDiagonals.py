sum = 1
add1 = add2 = 1
for i in range(1000):
    add1 = add1 + 2*(i+1)
    add2 =  add2 + 4*(i//2 + 1)
    sum = sum + add1 + add2

print(sum)

sum = 1
# must do to 1002 since exclusive
for i in range(3, 1002,2):
    sum = sum + 4*i**2 - 6*i + 6

print(sum)
print("hello")
