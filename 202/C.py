N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
a = {}

for i in range(N):
    if A[i] in a.keys():
        a[A[i]] += 1
    else:
        a[A[i]] = 1
        
ans = 0
for j in C:
    cur_B = B[j-1]
    if  cur_B in a.keys():
        ans += a[cur_B]

print(ans)
