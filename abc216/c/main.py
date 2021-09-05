N = int(input())
ans = ""
while N != 0:
	if N % 2 == 0:
		N //= 2
		ans = ans + 'B'
	else:
		N -= 1
		ans = ans + 'A'
print(ans[::-1])
