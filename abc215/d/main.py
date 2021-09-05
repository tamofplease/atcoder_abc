def make_divisors(n):
	lower_divisors , upper_divisors = [], []
	i = 1
	while i*i <= n:
		if n % i == 0:
			lower_divisors.append(i)
			if i != n // i:
				upper_divisors.append(n//i)
		i += 1
	return lower_divisors + upper_divisors[::-1]

def main():
	N, M = map(int, input().split())
	A = list(map(int, input().split()))
	checker = [False for _ in range(0, M+1)]
	for a in set(A):
		if a != 1:
			divi = make_divisors(a)
			for div in divi:
					if div != 1 and div <= M and not checker[div]:
						checker[div] = True
						num = div
						while num + div <= M:
							num += div
							if not checker[num]:
								checker[num] = True
	ans = [i+1 for i, v in enumerate(checker[1:]) if v is False]
	print(len(ans))
	for i in ans:
		print(i)
if __name__ == '__main__':
	main()
	

