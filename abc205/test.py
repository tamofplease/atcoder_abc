import sys
import math

def solver(n: int, m: int) -> None:
	N = n * math.log(2)
	M = (1/2) * math.log(2 * math.pi) + (m + 1/2) * math.log(m) - m
    if N < M:
        print('Factorial')
    else:
        print('Exponential')

def main(argv):
    n, m = map(int, argv[:2])
    if n == m:
        if n < 4:
            print('Exponential')
        else:
            print('Factorial')
    elif m > n:
        print('Factorial')
    else:
        solver(n , m)

if __name__ == '__main__':
    main(sys.argv[1:])
