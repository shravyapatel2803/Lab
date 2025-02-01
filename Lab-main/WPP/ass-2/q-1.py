input = input("Enter yoour word: ")
# print(input[9])
x=[]
for i in range(len(input)):
    if (i%2!=0):
        char=input[i]
        x.append(char.upper())
    else:
        x.append(input[i])
for i in x:
    print(i,end="")