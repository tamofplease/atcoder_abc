N = int(input())
A = map(int, input().split())
A = [a % 200 for a in A]
M = {}
for a in A:
    if a in M.keys():
        M[a] += 1
    else:
        M[a] = 1
ans = 0
for val in M.values():
    ans += (val * (val-1)) // 2

print(ans)
