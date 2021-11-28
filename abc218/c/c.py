from copy import copy

def isSame(A, B):
	if len(A) != len(B) or len(A[0]) != len(B[0]):
		return False
	for a, b in zip(A, B):
		for c, d in zip(a, b):
			if c != d:
				return False
	return True
		

def show(A):
	for i in range(len(A)):
		print(A[i])

def right_toggle(A):
	res = []
	for x in zip(*A[::-1]):
		res.append(''.join(x))
	return res

def compress(A):
	is_start = False
	top_y, fin_y= 0, 0
	top_x, fin_x = 0,0
	for i, a in enumerate(A):
		for j, c in enumerate(a):
			if c == '#' and not is_start:
				top_y = i
				is_start =True
	is_start = False
	for i, a in enumerate(A[::-1]):
		for j, c in enumerate(a):
			if c == '#' and not is_start:
				fin_y = len(A) - i
				is_start =True
	A = copy(A[top_y:fin_y])

	is_start = False


	for i in range(len(A[0])):
		for j in range(len(A)):
			if A[j][i] == '#' and not is_start:
				top_x = i
				is_start =True
	is_start = False
	for k in range(len(A[0])):
		for j in range(len(A)):
			i = len(A[0]) - k - 1
			if A[j][i] == '#' and not is_start:
				fin_x = i + 1
				is_start =True
	is_start = False
	A = list(map(lambda x: x[top_x: fin_x], A))
	return A
	
	

		
	
def main():
	N = int(input())
	S = [input() for _ in range(N)]
	T = [input() for _ in range(N)]

	for i in range(4):
		s, t = compress(S), compress(T)
		if isSame(s, t):
			print('Yes')
			return
		else:
			S = right_toggle(S)
	print('No')


if __name__ == '__main__':
	main()
