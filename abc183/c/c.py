from itertools import permutations


T = []
N, K = map(int, input().split())
for _ in range(N):
    t = list(map(int, input().split()))
    T.append(t)

cities = [i + 1 for i in range(N - 1)]
ans = 0
for route in permutations(cities):
    time = T[0][route[0]] + T[route[-1]][0]
    for i in range(len(route) - 1):
        time += T[route[i]][route[i + 1]]
    if time == K:
        ans += 1
print(ans)
