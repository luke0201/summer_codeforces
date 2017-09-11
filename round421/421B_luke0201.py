n, angle = (int(x) for x in input().split())

angle_per = 180 / n
approx = round(angle / angle_per)
if approx == 0:
    print(1, n, 2)
elif approx >= n - 2:
    print(1, 2, 3)
else:
    print(1, n, 1 + approx)
