import copy

def main():
	N = int(input())
	A = list(map(int, input().split()))
	tm = copy.copy(A)
	for _ in range(N-1):
		tm = [max(i,j) for i,j in zip(tm[0::2],tm[1::2])]
	print(1+A.index(min(tm)))


if __name__ == '__main__':
	main()
    
