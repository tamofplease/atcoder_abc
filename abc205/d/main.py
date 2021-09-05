N, Q = map(int, input().split())
A = list(map(int, input().split()))
K = [int(input()) for _ in range(Q)]

C = [0 for i in range(N)]
C[0] = A[0] - 1
for i in range(1, N):
	C[i] = C[i-1] + A[i] - A[i-1] - 1
for n in K:
	if n <= C[0]: print(n)
	elif n > C[N-1]: print(A[N-1] + n - C[N-1])
	else:
		low = 0
		heigh = N
		while heigh - low > 1:
			mid = (heigh + low) // 2
			if C[mid] >= n: heigh = mid
			else: low = mid
		print(A[heigh] - 1 - C[heigh] + n)
	# print(A[heigh] - C[heigh] + n)
