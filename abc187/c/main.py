from collections import Counter

def main():
	N = int(input())
	S = set([input() for _ in range(N)])
	M = {}
	for i in S:
		if i[0] == '!':
			i = i[1:]
		if i in M:
			print(i)
			return
		else:
			M[i] = 1

	print('satisfiable')
	

if __name__ == '__main__':
	main()
