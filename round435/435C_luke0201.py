import sys

n, x = (int(x) for x in input().split())

if x == 0 and n % 4 == 2:
    if n == 2:
        print('NO')
    else:
        print('YES')
        print(1, 2, 3, 4, 8, 12, *range(200000, 200000 + (n - 6)), sep=' ')
else:
    print('YES')
    offset = 0 if x >= 8 else 3
    res = (n - 1) % 4
    for i in range(offset, offset + res):
        x ^= 1 << i
        print(1 << i, end=' ')
    print(x, *range(200000, 200000 + (n - 1 - res)), sep=' ')
