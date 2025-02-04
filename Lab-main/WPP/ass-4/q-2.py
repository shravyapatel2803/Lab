import math
def is_perfect_square(n):
    root = math.sqrt(n)
    bool = (root == int(root))
    return bool
t = int(input("Enter the number no cases:- "))
j = 0
while j<t:
    a=int(input("Enter first number:- "))
    b=int(input("Enter second number:- "))
    count = 0
    for i in range(a,b+1):
        bool=is_perfect_square(i)
        if bool:
            count+=1
    print(count)
    j+=1
    