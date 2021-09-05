import math

def main():
	N, M = map(int, input().split())
	if M == 0:
		print(1)
		return
	elif N==M:
		print(0)
		return
	A = sorted(list(map(int, input().split())))	
	dfs = [A[i] - A[i-1] - 1 for i in range(1, M)]
	if A[0] != 1:
		dfs = [A[0] - 0 - 1] + dfs
	if A[-1] != N:
		dfs = dfs + [N-A[-1]]
	df = max(1,min(dfs))
	print(sum([math.ceil(i / df) for i in dfs]))

if __name__ == '__main__':
	main()
