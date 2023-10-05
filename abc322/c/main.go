package main

import (
	"bufio"
	"fmt"
	"os"
)

// Simple math functions

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func min64(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func max64(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func abs64(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func gcd64(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd64(b, a%b)
}

func next(arr *[]int, tgt int) int {
	ng := -1
	ok := len(*arr)
	for ok-ng > 1 {
		mid := (ng + ok) / 2
		if (*arr)[mid] < tgt {
			ng = mid
		} else {
			ok = mid
		}
	}
	return ok
}

func main() {
	var n, m int
	r := bufio.NewReader(os.Stdin)
	fmt.Fscanf(r, "%d %d", &n, &m)
	a := make([]int, 0)
	for i := 0; i < m; i++ {
		var aa int
		fmt.Fscan(r, &aa)
		a = append(a, aa)
	}
	for i := 0; i < n; i++ {
		res := next(&a, i+1)
		fmt.Println(a[res] - i - 1)
	}
}
