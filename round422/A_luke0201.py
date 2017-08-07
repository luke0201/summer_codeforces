from math import factorial

a, b = (int(x) for x in input().split())
print(factorial(min(a, b)))
