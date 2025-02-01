def sum(n):
    if n<=9:
        return n
    else :
        total=0
        while n>0:
            total+=n%10
            n//=10
        return sum(total)
n=int(input("Enter the number:-"))
print(sum(n))
