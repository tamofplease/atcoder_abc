N = int(input())

p = list(map(int, input().split()))

ans = [0 for _ in range(N)]

for i, v in enumerate(p):
    ans[v-1] = str(i+1)

print(' '.join(ans))


