n = int(input())
arr = [int(x) for x in input().split()]

print('First' if any(x % 2 == 1 for x in arr) else 'Second')
