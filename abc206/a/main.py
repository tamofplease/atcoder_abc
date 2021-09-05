import math
N = int(input())
if math.floor(N * 1.08) > 206:
    print(":(")
elif math.floor(N * 1.08) == 206:
	print("so-so")
else:
    print("Yay!")
