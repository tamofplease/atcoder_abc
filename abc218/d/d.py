def main():
	N = int(input())
	z = []	
	ma = {}
	for _ in range(N):
		x, y = map(int, input().split())
		z.append((x,y))
		ma[(x,y)] = True

	ans = []
	for x, y in z:
		for x_2, y_2 in z:
			if x == x_2 or y == y_2:
				continue
			if (x, y_2) in ma and (x_2, y) in ma:
				if x > x_2:
					one, two = x_2, x
				else:
					one, two = x, x_2
				if y > y_2:
					three, four = y_2, y
				else:
					three, four = y, y_2
				ans.append(((one, three), (two, four)))
		
						
	print(len(set(ans)))

if __name__ == '__main__':
	main()
