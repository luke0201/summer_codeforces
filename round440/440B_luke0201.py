from itertools import accumulate

n, k = (int(x) for x in input().split())
arr = [int(x) for x in input().split()]

if k == 1:
    print(min(arr))
elif k >= 3:
    print(max(arr))
else:
    lefts = list(accumulate(arr[:-1], func=min))
    rights = reversed(list(accumulate(reversed(arr[1:]), func=min)))
    splits = (max(l, r) for l, r in zip(lefts, rights))
    print(max(splits))
