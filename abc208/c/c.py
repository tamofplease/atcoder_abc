N, K = map(int, input().split())
a = list(map(int, input().split()))
base = K // N
sur = K % N
A = sorted(a)
base_number = A[sur-1]
for i in range(len(a)):
	if sur > 0 and a[i] <=  base_number:
			print(base+1)
	else:
		print(base)

