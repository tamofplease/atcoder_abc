N = int(input())
ans =[]
if N == 1:
    print(1)
for i in range(1,N):
    if i*i > N:
        break
    j = N // i
    if j * i == N:
        print(i)
        if i != j:
            ans.append(j)
        
for i in ans[::-1]:
    print(i)
