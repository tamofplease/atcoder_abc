X, Y, A, B = map(int, input().split())

tmp = X
ans = 0
head = X + B
while tmp * A <= X + B and tmp * A < Y:
    tmp *= A
    ans += 1

print(ans + ((Y - 1 - tmp) // B))

