state = {'^': 1, '>': 2, 'v': 3, '<': 4}

a, b = (state[x] for x in input().split())
n = int(input()) % 4

if (b - a) % 2 == 1 and n % 2 == 1:
    if (b - a) % 4 == 1:
        print('cw' if n == 1 else 'ccw')
        pass
    elif (b - a) % 4 == 3:
        print('cw' if n == 3 else 'ccw')
        pass
    else:
        print('undefined')
else:
    print('undefined')