N = int(input())

T = list(map(int, input().split()))


A = [False] * 110001
for i in range(N):
    A[T[i]] = True
    for j in reversed(range(110000)):
        if A[j]:
            A[j+T[i]] = True

all = sum(T)
half = all//2
while not A[half]:
    half += 1
    
print(max(all-half, half))
