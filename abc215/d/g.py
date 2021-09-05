#!/usr/bin/env python3

import random
N = 10000
W = 10000
print(N, W)
for _ in range(N):
    v = random.randint(1, 100000)
    print(v, end=' ')
print()
