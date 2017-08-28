from string import ascii_lowercase

n, k = (int(x) for x in input().split())
s = input()

print('YES' if all(s.count(c) <= k for c in ascii_lowercase) else 'NO')
