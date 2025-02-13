t = int(input())
s = input()
num = [int(i) for i in s.split()]
if(len(num) == t):
    for i in num:
        x = i//2
        y = i-x
        print(x*y)  
else:
    print("invaild input")  
