s = input()

def is_consonant(c):
    return c not in ['a', 'e', 'i', 'o', 'u']
cs = []
for c in s:
    if is_consonant(c):
        if len(cs) >= 2 and (cs[0] != cs[1] or cs[1] != c):
            print(*cs, sep='', end=' ')
            cs = []
        cs.append(c)
    else:
        print(*cs, c, sep='', end='')
        cs = []
print(*cs, sep='', end='')
