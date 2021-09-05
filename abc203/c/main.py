N, K = map(int, input.split())

ma = {}
for i in range(N):
    a,b = map(int, input().split())
    if a in ma.keys():
        ma[a] += b
    else:
        ma[a] = b




