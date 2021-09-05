N = int(input())
n = []
for i in range(N):
	name = input()
	n.append(name)
if len(set(n)) != len(n):
	print('Yes')
else:
	print('No')



