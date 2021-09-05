N = int(input())
A = map(int, input().split())

A = [a % 200 for a in A]

rep = min(8, N)

se = {}
plt = False
for i in range(0, (1 << rep)):
    cur = []
    tm = 0
    for bit in range(rep):
        
        if (i & (1 << bit)):
            cur.append(bit+1)
            tm += A[bit]
            tm %= 200
    
    if tm in se.keys() and len(se[tm]) != 0:
        print('Yes')
        print(len(se[tm]), end=' ')
        for k in se[tm]:
            print(k, end=' ')
        print('')
        print(len(cur), end=' ')
        for k in cur:
            print(k, end=' ')
        print()
        plt = True
        break
    else:
        se[tm] = cur
if not plt:
    print('No')
