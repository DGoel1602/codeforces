inps = list(map(int, input().split()))

for i, a in enumerate(inps):
    for j, b in enumerate(inps):
        if i == j:
            continue
        for k, c in enumerate(inps):
            if i == k or j == k:
                continue

            s = [a, b, c]

            if sum(s) in inps:
                index = -1
                for ix in range(len(inps)):
                    if ix not in [i, j, k] and inps[ix] == sum(s):
                        index = ix

                ind2 = -1
                for ix in range(len(inps)):
                    if ix not in [i, j, k, index] and inps[ix] == s[0] * 3 + s[1]:
                        ind2 = ix

                if -1 not in [index, ind2]:
                    print(sum(s), s[0], s[1], s[2], s[0] * 3 + s[1])
                    exit()
