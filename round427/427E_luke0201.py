import sys

n, x, y = (int(x) for x in input().split())
ys = [y, x ^ y]

def ask(*bits):
    arr = [x for x in range(1, n + 1) if all(x & i == i for i in bits)]
    if len(arr) == 0:
        return 0
    print('?', len(arr), *arr)
    sys.stdout.flush()
    return int(input())

diffs = []
i = 1
while i <= n:
    x = ask(i)
    if x in ys:
        diffs.append(i)
    i <<= 1

i = diffs[-1]
j = 1
ans2 = i
while j <= n:
    if j != i:
        x = ask(i, j)
        if x in ys:
            ans2 |= j
    j <<= 1

ans1 = sum(diffs) ^ ans2

print('!', ans1, ans2)
