import numpy as np
N = int(input("Enter your no of elements:- "))
x = np.random.randint(-N,N,N)
y = np.random.randint(-N,N,N)
# print(x)
# print(y)
car = np.column_stack((x,y))
r = np.sqrt(((x**2)+(y**2)))
theta = np.arctan2(y,x)
polar = np.column_stack((r,theta))
print(f"Cartensian points:- \n{car}")
print(f"polar points:- \n{polar}")


    