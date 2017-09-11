def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

n = int(input())

for i in range(n // 2, -1, -1):
    j = n - i
    if gcd(i, j) == 1:
        print(i, j)
        break
