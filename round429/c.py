n = int(input())
arr = [int(x) for x in input().split()]
idx = [int(x) for x in input().split()]

arr.sort(reverse=True)
idx = sorted(range(n), key=lambda x: idx[x])

perm = [0] * n
for i in range(n):
    perm[idx[i]] = arr[i]
print(*perm, sep=' ')
