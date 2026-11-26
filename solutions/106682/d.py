s = str(int(input())*9)
sl = []
for i in s: sl.append(int(i))
s = sl[::-1]
n = len(s)

a = sum(s)
for i in range(1, 10**18):
    j = 0
    s[j] += 1
    a += 1
    while s[j] > 9:
        s[j] -= 10
        a -= 10
        j += 1
        if j >= len(s):
            s.append(0)
        s[j] += 1
        a += 1
    if a <= i:
        print(i)
        break
