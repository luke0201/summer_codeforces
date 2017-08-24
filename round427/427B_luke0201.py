k = int(input())
s = [int(x) for x in input()]
s.sort()

diff = k - sum(s)
cnt = 0
for x in s:
    if diff <= 0: break
    diff -= (9 - x)
    cnt += 1
print(cnt)