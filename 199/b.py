N = int(input())
A = [ int(i) for i in input().split()]
B = [ int(i) for i in input().split()] 

maxA = max(A)
minB = min(B)
print(max(0, minB - maxA + 1))
