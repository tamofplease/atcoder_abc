A, B, c = map(int, input().split())

if c % 2 == 0:
	c = 2
else:
	c = 1

x, y = pow(A, c), pow(B, c)
if x == y:
	print('=')
elif x > y:
	print('>')
else:
	print('<')
