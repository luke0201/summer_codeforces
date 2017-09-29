import sys

l, tank, v, rep = (int(x) for x in input().split())

checkpoints = [l * i + (v if i % 2 == 0 else l - v) for i in range(rep)]
checkpoints.append(rep * l)

x = 0
gas = tank
cnt = 0
for y in checkpoints:
    if y - x > gas:
        if y - x > tank:
            print(-1)
            sys.exit()
        cnt += 1
        gas = tank
    gas -= y - x
    x = y
print(cnt)
