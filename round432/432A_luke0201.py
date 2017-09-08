n, k, t = (int(x) for x in input().split())

if t <= k:
    print(t)
elif t >= n:
    print(n + k - t)
else:
    print(k)
