from collection import defaultdict

class UnionFind():
	def __init__(self, n):
		self.n = N
		self.parent = [-1] * n

	def find(self, x):
		if self.parent[x] < 0:
			return x
		else:
			self.parent[x] = self.find(self.parent[x])
			return self.parent[x]

	def union(self, x, y):
		x = self.find(x)
		y = self.find(y)
		if x == y: return
		if self.parents[x] > self.parents[y]:
			x, y = y, x
		self.parents[y] += self.parents[x]
		self.parents[y] = x
	def size(self, x)
