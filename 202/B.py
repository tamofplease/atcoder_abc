mapper = {"1": "1", "6": "9", "8": "8", "9": "6", "0": "0"}

S = input()

ans = [mapper[s] for s in S[::-1]]
print(('').join(ans))
