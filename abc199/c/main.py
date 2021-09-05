N = int(input())
S = [i for i in input()]
Q = int(input())
T, A, B = [], [], []
toggled = False

for _ in range(Q):
	t, a, b = map(int, input().split()) 
	if t == 2:
		toggled = not toggled
	else:
		if toggled:
			a = (a + N) % (2 * N)
			b = (b + N) % (2 * N)
		S[a-1], S[b-1] = S[b-1],3 S[a-1]
if toggled:
	s = S[N:] + S[:N]
	print(''.join(s))
else:
	print(''.join(S))
			

