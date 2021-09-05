N, K = map(int, input().split())

for _ in range(K):
    if N % 200 == 0:
        N //= 200
    else:
        str_N = str(N)
        str_N += '200'
        N = int(str_N)
print(N)
