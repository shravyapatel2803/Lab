def solve():
    s = input()
    n = len(s)
    count = 0
    for i in range(n // 2):
        diff = abs(ord(s[i]) - ord(s[n - 1 - i]))
        count += diff
    print(count)

t = int(input())
for _ in range(t):
    solve()