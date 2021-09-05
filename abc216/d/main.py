N, M = map(int, input().split())
A = []
ma = {i: [] for i in range(N)}
l = []
for i in range(M):
	kk = int(input())
	a = list(map(lambda x: int(x)-1, input().split()))
	a.reverse()
	A.append(a)
	ma[a[0]].append(i)

for i in range(N):
	if len(ma[i]) == 2:
		l.append(i)

while len(l) != 0:
	now = l.pop(0)
	for j in ma[now]:
		A[j].pop()
		if len(A[j]) != 0:
			ma[A[j][0]].append(j)
			if(len(ma[A[j][0]]) == 2):
				l.append(ma[A[j][0]])

	
res = 'Yes'
for i in A:
    if len(i) != 0:
        res = 'No'
print(res)




