
def main():
	a = map(int, input().split())
	ans = ''
	for i in a:
		ans += chr(i + 96)
	print(ans)

if __name__ == '__main__':
	main()

