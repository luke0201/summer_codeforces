n, v0, v1, d, l = (int(x) for x in input().split())

days = 1
while True:
    v = v0 - (0 if days == 1 else l)
    if v >= n:
        print(days)
        break
    n -= v
    
    v0 = min(v0 + d, v1)
    days += 1
