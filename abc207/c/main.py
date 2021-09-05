N = int(input())
l,r = [],[]
for i in range(N):
	a,b,c = map(int, input().split())	
	if a in [2, 4]:
		c -= 0.1
	if a in [3, 4]:
		b += 0.1
	l.append(b)
	r.append(c)
print(sum([1 for i in range(N) for j in range(i+1, N)  if r[i] >= l[j] and r[j] >= l[i] ]))
