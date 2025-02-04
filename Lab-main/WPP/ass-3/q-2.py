import math
def is_perfect_square(n1,n2):
    sqrt_n1 = math.sqrt(n1)
    sqrt_n2 = math.sqrt(n2)
    return sqrt_n1 == int(sqrt_n1) or sqrt_n2 == int(sqrt_n2)
t = int(input("Enter no of case:-"))
for i in range(t):
    n = int(input(f"Enter your {i} no"))
    n1 = (5*(n*n)+4)
    n2 = 5*(n*n)-4
    if is_perfect_square(n1,n2):
        print(f"{n} is fibo")
    else:
        print(f"{n} is not fibo")