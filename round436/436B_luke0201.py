n = int(input())
s = input()

def ans(s):
    letters = set()
    for c in s:
        if c.isupper():
            letters.clear()
        else:
            letters.add(c)
        yield len(letters)
print(max(ans(s)))
