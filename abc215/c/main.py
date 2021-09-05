import itertools

S, k = input().split()

k = int(k)


res = list(set(itertools.permutations(S)))
res.sort()
print(''.join(res[k-1]))
