from bisect import bisect_left as lower_bound

n, x = (int(x) for x in input().split())
arr = sorted(int(x) for x in input().split())

p = lower_bound(arr, x)
print(x - p + (p < len(arr) and arr[p] == x))
