package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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

func main() {
	var n int
	w := bufio.NewReader(os.Stdin)
	fmt.Fscan(w, &n)
	a := make([][]int64, 0)
	for i := 0; i < n; i++ {
		aa := make([]int64, 3)
		fmt.Fscan(w, &aa[0], &aa[1])
		aa[2] = int64(i + 1)
		a = append(a, aa)
	}

	sort.Slice(a, func(i, j int) bool {
		tmp := (a[i][0] * (a[j][0] + a[j][1]))
		tmp2 := (a[j][0] * (a[i][0] + a[i][1]))
		if tmp == tmp2 {
			return bool(a[i][2] < a[j][2])
		}
		return tmp > tmp2
	})
	for _, item := range a {
		fmt.Print(item[2], " ")
	}
	fmt.Println()
}
