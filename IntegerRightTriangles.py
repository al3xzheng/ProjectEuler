import math


maxSolutions = 0;
ans = -1

for i in range (4, 1001): #perimeter
    sol = 0
    for j in range (i//2, i//4,-1): #hypotenuse
        for k in range(j-1, j//2-1, -1):
            if((j**2- k**2) % math.sqrt(j**2- k**2) == 0 and (j+k + math.sqrt(j**2- k**2)) == i):
                sol+=1
                # print(str(i) + " " + str(j) + " " + str(k) + " " + str(math.sqrt(j**2-k**2)) + " ")
                break
    if(sol > maxSolutions):
        maxSolutions = sol
        ans = i;

# print(20 % 5.3)
print(ans)
    