N = int(input())
A = list(map(int, input().split()))


ans = 0

for i in range(len(A)):
    ans += A[i] - 10 if A[i] >= 10 else 0
    
print(ans)
