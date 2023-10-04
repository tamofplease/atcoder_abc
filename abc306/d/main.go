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

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n int
	fmt.Fscan(r, &n)
	prev := []int64{0, 0}
	cur := []int64{0, 0}
	var ans int64
	x := make([]int64, 0)
	y := make([]int64, 0)

	for i := 0; i < n; i++ {
		var xx, yy int64
		fmt.Fscan(r, &xx)
		fmt.Fscan(r, &yy)
		x = append(x, xx)
		y = append(y, yy)
	}
	for i := 0; i < n; i++ {
		if x[i] == 1 {
			cur[0] = prev[0]
			cur[1] = max64(prev[0]+y[i], prev[1])
		} else {
			cur[0] = max64(prev[1]+y[i], max64(prev[0]+y[i], prev[0]))
			cur[1] = prev[1]
		}
		ans = max64(ans, max64(cur[0], cur[1]))
		prev, cur = cur, prev
	}
	fmt.Fprintln(w, ans)
}
