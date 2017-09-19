n, k = (int(x) for x in input().split())
tmp = n

while k > 0 and tmp % 10 == 0:
    tmp /= 10
    k -= 1

while k > 0 and tmp % 2 == 0:
    tmp /= 2
    n *= 5
    k -= 1
while k > 0 and tmp % 5 == 0:
    tmp /= 5
    n *= 2
    k -= 1

print(n * pow(10, k))
