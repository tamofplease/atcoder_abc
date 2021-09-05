N, K = map(int, input().split())

A = sorted(list(map(int, input().split())), key=lambda x: -x)
diff = []

# n よりも大きいもので何回満たせるのか
def get_num(n: int):
	tmp = 0
	for a in A:
		if a - n > 0:
			tmp += a - n
		else:
			return tmp
	return tmp


head, tail = 2000000001, 0
mid = (head + tail) // 2
while head - tail > 1:
	mid = (head + tail) // 2
	su = get_num(mid)
	# 満たせる回数が、予定よりも大きい場合は
	if su >= K:
		tail = mid
	else:
		head = mid
ans = count = 0
for i in A:
	if i > head:
		ans += (i - head) * (i + head + 1) // 2
		count += (i - head)
	else:
		break
if head == 1 and K - count > N:
	ans += N
else:
	ans += (K - count) * head
print(ans)

