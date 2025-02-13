def fun(s):
    a = [char for char in s]
    b = False
    c = set(a)
    if len(c)!=1:
        for i in range(len(a)):
            if(a[-i-1]>a[-i-2]):
                temp = a[-i-1]
                a[-i-1] = a[-i-2]
                a[-i-2] = temp
                b = True
                break
    if b:
        for i in a:
            print(i,end="")
        print()
    else:
        print("no answer")
s = input()
fun(s)