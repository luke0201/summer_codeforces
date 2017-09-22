import math

n, m = (int(x) for x in input().split())
queries = {}
for _ in range(m):
    ki, fi = (int(x) for x in input().split())
    queries[ki] = fi

ans = set()
for i in range(1, 101):
    def on_floor(k, f):
        return k >= i * (f - 1) + 1 and k <= i * f
    if all(on_floor(k, f) for k, f in queries.items()):
        ans.add(math.ceil(n / i))

print(list(ans)[0] if len(ans) == 1 else -1)
