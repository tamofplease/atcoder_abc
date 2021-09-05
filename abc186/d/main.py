N = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
ans = 0
length = len(A) - 1
for index, num in enumerate(A):
    ans += (length - (index * 2)) * num
print(ans)
