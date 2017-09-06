n = int(input())
arr = [int(x) for x in input().split()]
print('Yes' if n % 2 == 1 and arr[0] % 2 == 1 and arr[-1] % 2 == 1 else 'No')
