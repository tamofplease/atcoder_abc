N = int(input())
count = 0
for i in range(1, N+1):
    st = str(i)
    so = oct(i)
    if "7" in st:
        continue
    elif "7" in so:
        continue
    else:
        count += 1
print(count)

