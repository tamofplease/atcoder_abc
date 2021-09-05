S = int(input())

dp = [0] * 3300

dp[0] = 1

for i in range(1, S+1):
    if i < 3:
        dp[i] = 0
    else:
        dp[i] = dp[i-1] + dp[i-3]
        dp[i] %= 1000000007

print(dp[S])
