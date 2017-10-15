n1, n2 = (int(x) for x in input().split())
arr1 = set(int(x) for x in input().split())
arr2 = set(int(x) for x in input().split())

cap = arr1 & arr2
if cap:
    print(min(cap))
else:
    print(*sorted([min(arr1), min(arr2)]), sep='')
