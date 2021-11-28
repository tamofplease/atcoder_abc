from queue import Queue


def main():
	N, Q = map(int, input().split())
	R = {}
	C, D = [], []
	for _ in range(N-1):
		a, b = map(int, input().split())
		if a == b:
			continue
		if a in R:
			R[a].append(b)
		else:
			R[a] = [b]
		if b in R:
			R[b].append(a)
		else:
			R[b] = [a]
	
	for _ in range(Q):
		c, d = map(int, input().split())
		C.append(c), D.append(d)
  
	que=Queue()
	cost = {i+1: -1 for i in range(N)}
	cost[1] = 0
	que.put(1)
	while not que.empty():
		t = que.get()
		nexs = R[t]
		for nxt in nexs:
			if cost[nxt] == -1:
				cost[nxt] = 1 - cost[t]
				que.put(nxt)

	for c, d in zip(C,D):
		if cost[c] == cost[d]:
			print('Town')
		else:
			print('Road')

if __name__ == '__main__':
	main()
