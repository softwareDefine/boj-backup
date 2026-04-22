dp = [0] * 10001
n = 0

dp[2] = 1
for i in range(3, 10001):
    first = -1 if i % 2 == 1 else 1
    dp[i] = dp[i-1] * 2 + first

n = int(input())
print(dp[n])