t = int(input("Enter the number of test cases:- "))
# i = 0
cases = []
for i in range(t):
    cases.append(int(input("Enter your data:-")))
# print(cases)
final_height =[1] 
height = 1
cases.sort()
for j in range(cases[-1]+1):
    if j%2==0 and j!=0:
        height+=1
        final_height.append(height)
    elif(j%2!=0):
        height = height*2
        final_height.append(height)
for j in range(len(cases)):
    for i in range(len(final_height)):
        if cases[j]==i:
            print(final_height[i])
print(final_height)
