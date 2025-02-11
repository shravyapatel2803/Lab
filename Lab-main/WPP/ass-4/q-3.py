s = input()
a = []

for char in s:
    char.lower()
    if char.isalpha():
        a.append(char.lower())
a.sort()
set1 = set(a)
# b = list(set1)
# b.sort()
# print (a)
# print(b)
# print(len(set1))
if len(set1)==25:
    print("pangarms")
else :
    print("not pangrams")