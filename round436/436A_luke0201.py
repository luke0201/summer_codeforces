n = int(input())
arr = sorted(int(input()) for _ in range(n))

print('YES\n{} {}'.format(arr[0], arr[-1]) if arr[0] == arr[n // 2 - 1] and arr[n // 2] == arr[n - 1] and arr[0] < arr[-1] else 'NO')
