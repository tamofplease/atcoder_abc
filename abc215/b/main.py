def main():
	n = int(input())
	tmp = 1

	for i in range(61):
		if tmp > n:
			print(i-1)
			return None
		tmp *= 2


if __name__ == '__main__':
	main()

