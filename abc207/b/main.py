a,b,c,d = map(int, input().split())
red = 0
blue = a
counter = 0
while True:
	counter += 1
	blue += b
	red += c
	if blue <= red * d:
		print(counter)
		break
	if counter == 100001:
		print(-1)
		break

