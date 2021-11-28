n, x = map(int, input().split())

a = list(map(int, input().split()))

su = sum([item - 1 if (index+1) % 2 == 0 else item for index, item in  enumerate(a)])
print('Yes') if su <= x else print('No')
