import math
fact = [math.factorial(i) for i in range(1, 11)]
P = int(input())
ans = 0
for i in range(len(fact)):
    j = 10 - i - 1
    target = fact[j]
    num = min(100, P // target)
    P -= num * target
    ans += num
print(ans)
