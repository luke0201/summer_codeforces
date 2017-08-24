goods = input()
query = input().split('*')
l = [len(s) for s in query]

def match(pat, s):
    if len(pat) != len(s):
        return False
    for x, y in zip(pat, s):
        if x == '?':
            if y not in goods:
                return False
        else:
            if x != y:
                return False
    return True

for tc in range(int(input())):
    s = input()
    
    if len(query) == 1:
        left = match(query[0], s)
        mid = True
        right = True
    else:
        left = match(query[0], s[:l[0]])
        mid = len(s) >= sum(l) and all(c not in goods for c in s[l[0]:len(s) - l[1]])
        right = match(query[1], s[len(s) - l[1]:])
    print('YES' if left and mid and right else 'NO')