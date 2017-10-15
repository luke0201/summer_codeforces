from copy import copy
import heapq

n, k = (int(x) for x in input().split())
arr = [int(x) for x in input().split()]

if k == 1:
    print(min(arr))
elif k >= 3:
    print(max(arr))
else:
    lefts = [arr[0]]
    for x in arr[1:-1]:
        lefts.append(min(lefts[-1], x))
    rights = [arr[-1]]
    for x in reversed(arr[1:-1]):
        rights.append(min(rights[-1], x))
    rights.reverse()

    print(max(max(l, r) for l, r in zip(lefts, rights)))
