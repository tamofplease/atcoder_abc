import sys

def find_two(n: int) -> int:
	res = 0
	while n >= 1:
		n //= 2
		res += n
	return res

def main(argv):
	n, m = map(int, argv)
	print(n, m)
	print(find_two(n))

if __name__ == '__main__':
	main(sys.argv[1:])
