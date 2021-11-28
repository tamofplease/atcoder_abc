def main():
    N, W = map(int, input().split())
    S, T, P = [], [], []
    for _ in range(N):
        s, t, p = map(int, input().split())
        S.append(s), T.append(t), P.append(p)

    counter = [0 for _ in range(2 * 10 ** 5 + 1)]

    for s, t, p in zip(S, T, P):
        counter[s] += p
        counter[t] -= p
    tmp = 0
    for i in counter:
        tmp += i
        if tmp > W:
            print("No")
            return
    print("Yes")


if __name__ == "__main__":
    main()
