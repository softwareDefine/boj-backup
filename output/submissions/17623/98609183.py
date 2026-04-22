import sys
input = sys.stdin.readline


dp = []

for i in range(1,2000):
    dp.append('99999999999999999999999')

dp[1] = "12"
dp[2] = "34"
dp[3] = "56"

for i in range(4,1001):
    if((i%2) == 0):
        dp[i] = str(min(int(dp[i]),int('1'+dp[i//2]+'2')));
    if((i%3) == 0):
        dp[i] = str(min(int(dp[i]),int('3'+dp[i//3]+'4')));
    if((i%5) == 0):
        dp[i] = str(min(int(dp[i]),int('5'+dp[i//5]+'6')));
    for j in range(1,i):
        dp[i] = str(min(int(dp[i]),int(dp[j]+dp[i-j])));
        dp[i] = str(min(int(dp[i]),int(dp[i-j]+dp[j])));
        
t = int(input())
for l in range(t):
    n = int(input())
    for k in range(0,len(dp[n])):
        if(dp[n][k] == '1'):
            print('(',end="")
        if(dp[n][k] == '2'):
            print(')',end="")
        if(dp[n][k] == '3'):
            print('{',end="")
        if(dp[n][k] == '4'):
            print('}',end="")
        if(dp[n][k] == '5'):
            print('[',end="")
        if(dp[n][k] == '6'):
            print(']',end="")
    print()
