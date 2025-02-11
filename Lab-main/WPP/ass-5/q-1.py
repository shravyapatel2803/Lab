def max_xor(l,r):
    a = []
    for i in range(l,r+1):
        for j in range(l,r+1):
            a.append(i^j)
    set1 = set(a)
    b = list(set1)
    return b
l = int(input())
r = int(input())
b = max_xor(l,r)
print(b[-1])