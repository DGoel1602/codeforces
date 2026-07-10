amnts = {}

inp = input()

for char in inp:
    if char in amnts:
        amnts[char] += 1
    else:
        amnts[char] = 0

allEven = True
allOdd = True
for c in amnts:
    if amnts[c] % 2 == 0:
        allOdd = False
    else:
        allEven = False

if not allEven and not allOdd:
    print("0/1")
elif allEven:
    print("1")
else:
    print("0")
