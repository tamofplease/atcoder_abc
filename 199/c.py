N = int(input())
S = input() 
Q = int(input())
T = []
A = []
B = []

for _ in range(Q):
    st_list = [int(i) for i in input().split()]
    T.append(st_list[0])
    A.append(st_list[1] - 1)
    B.append(st_list[2] - 1)

isToggled = False

def getToggled(N, length, index) -> int:
    if N > index:
        return length - N + index + 1
    elif index > (length - N):
        return index - length + N - 1
    else:
        return index
    # a b c d e f
    # 2, 5, 0 => 4
    # 2, 5, 1 => 5
    # 2, 5, 2 => 2
    # 2, 5, 3 => 3
    # 2, 5, 4 => 0
    # 2, 5, 5 => 1
length = len(S)
for index in range(Q):
    if T[index] == 1:
        i = index
        if isToggled:
            targeta = getToggled(N, length-1, A[i]) 
            targetb = getToggled(N, length-1, B[i])
            tma = S[targeta]
            tmb = S[targetb]
            S = S[:targeta] + tmb + S[targeta + 1:]
            S = S[:targetb] + tma + S[targetb + 1:]
        else:
            tma = S[A[i]]
            tmb = S[B[i]]
            S = S[:A[i]] + tmb + S[A[i] + 1:]
            S = S[:B[i]] + tma + S[B[i] + 1:]
    elif T[index] == 2:
        isToggled = not isToggled
if isToggled:
    head = S[:N]
    tail = S[-N:]
    S = S[-N:] + S[N:-N] + S[:N]

print(S)
