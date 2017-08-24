n, k = (int(x) for x in input().split())
arr = [int(x) for x in input().split()]

have = 0
for day, candy in enumerate(arr, start=1):
    have += candy
    give = min(have, 8)
    k -= give
    have -= give
    if k <= 0:
        print(day)
        break
else:
    print(-1)