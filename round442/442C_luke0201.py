n = int(input())

print(n + n // 2)
print(*range(2, n + 1, 2), *range(1, n + 1, 2), *range(2, n + 1, 2))
