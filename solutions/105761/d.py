count = int(input())

buildings = []

for i in range(count):
    buildings.append(list(map(int, input().split())))

buildings = sorted(buildings, key = lambda x: x[0])

total = 0
for i, b in enumerate(buildings):
    if i == 0 or b[0] != buildings[i-1][0] + buildings[i-1][1]:
        total += b[2]
    else:
        total += abs(b[2] - buildings[i-1][2])

    if i == len(buildings) - 1 or b[0] + b[1] != buildings[i+1][0]:
        total += b[2]

print(total + 100)
