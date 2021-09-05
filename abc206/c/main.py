N = int(input())
A = list(map(int, input().split()))

ma = max(A)


# 7 8   9 9 6 8  4  9 6 
# {1: 4, 2: 1, 3: 1, 4: 3, 5: 3, 6: 2, 7: 1, 8: 2, 9: 3}
# => 4 * (20-4) + 1 * (16-1) + 
ma = {}
for i in A:
	if i in ma.keys():
		ma[i] += 1
	else:
		ma[i] = 1
ans = 0
for key, val in ma.items():
	ans += val * (N-val)
	N -= val
print(ans)
