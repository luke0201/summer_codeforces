n, k = (int(x) for x in input().split())
n += 1

scores = [0, ]
for diff in input().split():
    scores.append(scores[-1] + int(diff))
idxs = sorted(range(n), key=lambda x: scores[x])

rems = sorted(int(x) for x in input().split())

ans = set()
for base in range(n):
    if idxs[base] == 0: continue

    i = 1
    for idx in idxs[base + 1:]:
        if i == k: break

        if idx != 0 and scores[idx] - scores[idxs[base]] == rems[i] - rems[0]:
            i += 1
    if i == k:
        ans.add(rems[0] - scores[idxs[base]])

print(len(ans))
