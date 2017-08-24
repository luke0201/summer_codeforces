l, v1, v2, t1, t2 = (int(x) for x in input().split())
total_t1 = t1 + l * v1 + t1
total_t2 = t2 + l * v2 + t2
if total_t1 < total_t2:
    print('First')
elif total_t1 > total_t2:
    print('Second')
else:
    print('Friendship')