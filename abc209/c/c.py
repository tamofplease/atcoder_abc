n = int(input())
c = list(map(int, input().split()))

md = 1000000007

c.sort()

ans = 1

for index, item in enumerate(c):
	i = index + 1
	ans *= (item  - index)
	ans %= md
print(ans)
