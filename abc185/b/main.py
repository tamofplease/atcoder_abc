N, M, T = map(int, input().split())
A, B = [0], [0]
ans = N
for _ in range(M):
	a,b = list(map(int, input().split()))
	B.append(b)
	A.append(a)
flag = True
for i in range(1, M+1):
	ans -= (A[i] - B[i-1])
	if ans <= 0:
		flag = False

	ans += B[i] - A[i]
	ans = min(ans, N)	

ans -= (T - B[M])
 
print('Yes') if flag and ans > 0 else print('No')
