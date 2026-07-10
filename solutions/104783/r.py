raw = input()

index = 0
cost = [len(raw) for _ in range(len(raw))]
last_begin = 0
while(index < len(raw)):
    if(raw[index] == '1'):
        last_begin = index

    cost[index] = min(cost[index], index - last_begin)
    index += 1
index = len(raw) - 1
last_begin = len(raw) - 1
while(index >= 0 ):
    if(raw[index] == '1'):
        last_begin = index
    cost[index] = min(cost[index], last_begin - index)
    index -= 1
best = 0
for big in cost:
    best = max(big, best)
print(best)
