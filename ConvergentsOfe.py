# Had to convert to python since using Very Large Values in C and C++ was just too hindering. I learned that in C, you must explicitly
# track the size of the array that you point to. Its size is not obtainable by itself since C is low level. It's just an array of memory
# which you have to track and determine which is yours

# Couldn't be bothered to (waste) time revising methods by tracking size along the way. Dividing and multiplying whilst tracking size is
# trivial, especially multiplication, but I didn't want to do it since I almost, practically finished my C learnings and using my time 
# thinking, alhtough fun, would've been stressful. I wanted to get this over with and just be more like water? Implementing in Python.

# here learned that i in range (a , b, k) doesn't reach to b, so if want to reach b must go b +- 1.
# Learned that python is pass by assignment. Mutable objects are passed by reference since the objects inside are inside the outside 
# container object. Ints, Strings,... CAN NOT pass by reference. Mutables like lists can, leading to me use lists, very smooth and nice.


def gcd(a, b):
    while(b !=0):
        t = a
        a = b
        b = t%b
    return a

def addFractions (a, nums):
    nums[0] = nums[0] + a * nums[1]
    gcf = gcd(nums[0], nums[1])
    nums[0] = nums[0]//gcf
    nums[1] = nums[1]//gcf


def solution():


    max = 99
    nums = [1]

    if(max % 3 == 2):
    
        nums.append(2*(max//3 + 1))

    else:
    
        nums.append(1)
    

    for i in range (max-1, -1, -1):
        if(i == 0):
            addFractions(2, nums)
        elif(i%3 == 2):
            addFractions(2* (i//3 + 1), nums)
        else:
            addFractions(1, nums)
        if(i != 0):
            temp = nums[0]
            nums[0] = nums[1]
            nums[1] = temp
            # // num = num ^den;
            # // den = num ^den;
            # // num = den ^ num;
        


        # // num = num + den;
        # // den = num - den;
        # // num = num - den;

        # // invert; swap a,b using addition or xor trick.
    

    print(str(nums[0]) + "\n")

    sum = 0;

    while (nums[0] != 0):
        sum = sum + nums[0] % 10
        nums[0] = nums[0]//10

    print(sum)

solution()