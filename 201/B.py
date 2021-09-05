N = int(input())
li = []
M = {}
ma = 0
se = 0
for i in range(N):
    tm = input().split()
    li.append(tm)
    M[int(tm[1])] = tm[0]
    
for k, v in M.items():
    ma = max(k, ma)
    if ma != k:
        se = max(se, k) 


print(M[se])
