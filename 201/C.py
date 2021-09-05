S = input()    

ans = 0

for i in range(10000):
    I = str(i).zfill(4)
    flag = True
    checker = [c == 'o' for c in S]
    for j in range(10):
        if S[j] == 'x' and str(j) in I:
            flag = False
        if checker[j] and not str(j) in I:
            flag = False
            
    ans += flag

print(ans)
