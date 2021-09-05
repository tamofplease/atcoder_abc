N = int(input())
tmp = 0
# N = (1 + i) * i // 2
i = 0
while True:
    i += 1
    tmp += i
    if tmp >= N:
        break
print(i)
 