import operator
from functools import reduce

a, b = (int(x) for x in input().split())

if a == b:
    print(1)
elif a + 5 < b:
    print(0)
else:
    print(reduce(lambda x, y: (x * y) % 10, range(a + 1, b + 1)) % 10)
