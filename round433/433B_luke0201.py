n, k = (int(x) for x in input().split())
min_safe = int(k > 0 and k < n)
max_safe = (2 * k) if (3 * k <= n) else (n - k)
print(min_safe, max_safe)
