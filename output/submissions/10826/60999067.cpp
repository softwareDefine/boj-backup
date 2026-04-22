n = int(input())
arr = [0] * (n + 2)
arr[1] = 0
arr[2] = 1
for i in range(3, n + 2):
    arr[i] = arr[i - 1] + arr[i - 2]
print(arr[n + 1])