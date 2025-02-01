def print_digit(n):
    x=[]
    y=n
    while y>0:
        x.append(y%10)
        y=y//10
    x = set(x)
    for i in x:
        if i!=0:
            if n%i==0:
                print(i,end=",")
        
    print()
t = int(input("Enter the no of cases:- "))
for i in range(t):
    n=int(input("Enter the no:-"))
    print_digit(n)
# x=[1,2,3,4,5,6,7,8,9,0]
# for i in x:
#     print(i)