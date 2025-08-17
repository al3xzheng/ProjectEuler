import math

def PandigitalProd (N):
    sum = 0;
    n = 1;
    nums = {0}
    while(sum < 100000000):
        product = n*N
        i = product
        while(i !=0):
            if(i%10 in nums):
                return 0
            nums.add(i%10)
            i = i//10
        sum = sum*(math.pow(10, int(math.log(product,10) + 1))) + product
        n+=1
    if(sum >= 1000000000):
        return 0
    return sum

ans = 0;

MSV = 9;
while(MSV>1):
    for i in range(4,0,-1):
        for j in range((10**(i-1))*(MSV+1)-1, (10**(i-1))*(MSV)-1,-1):
            if(PandigitalProd(j) > 0 and PandigitalProd(j) > ans):
                ans = PandigitalProd(j)
        if(i==1):
            MSV -=1

print(ans)