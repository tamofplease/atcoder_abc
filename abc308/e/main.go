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

func getMex(i, j, k int) int {
	cur := []int{i, j, k}
	sort.Slice(cur, func(i, j int) bool {
		return cur[i] < cur[j]
	})
	mex := 0
	for _, c := range cur {
		if c == mex {
			mex++
		}
	}
	return mex
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(r, &n)
	a := make([]int, 0)
	var s string
	for i := 0; i < n; i++ {
		var aa int
		fmt.Fscan(r, &aa)
		a = append(a, aa)
	}
	fmt.Fscan(r, &s)
	ms := [][]int{{0, 0, 0}}
	xs := [][]int{{0, 0, 0}}
	for i := 0; i < n; i++ {
		curM := make([]int, 3)
		curX := make([]int, 3)
		copy(curM, ms[i])
		copy(curX, xs[i])
		if s[i] == 'M' {
			curM[a[i]]++
		}
		if s[i] == 'X' {
			curX[a[i]]++
		}
		ms = append(ms, curM)
		xs = append(xs, curX)
	}
	ans := 0
	for i := 0; i < n; i++ {
		if s[i] != 'E' {
			continue
		}
		for j := 0; j < 3; j++ {
			if ms[i][j] == 0 {
				continue
			}
			for k := 0; k < 3; k++ {
				if xs[n][k]-xs[i][k] == 0 {
					continue
				}
				mex := getMex(j, a[i], k)
				ans += mex * ms[i][j] * (xs[n][k] - xs[i][k])
			}
		}
	}
	fmt.Println(ans)
}
