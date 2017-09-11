s = [int(x) for x in input().split()]
a, b, c = s[:2], s[2:4], s[4:]

def sqdist(a, b):
    return (b[0] - a[0])**2 + (b[1] - a[1])**2
def same_line(a, b, c):
    return (b[1] - a[1]) * (c[0] - a[0]) == (c[1] - a[1]) * (b[0] - a[0])
print('Yes' if sqdist(a, b) == sqdist(b, c) and not same_line(a, b, c) else 'No')
