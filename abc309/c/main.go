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
	r := bufio.NewReader(os.Stdin)
	var n, k int
	fmt.Scan(&n, &k)
	ma := make(map[int]int64)
	ke := make([]int, 0)
	var su int64
	for i := 0; i < n; i++ {
		var aa int
		var bb int64
		fmt.Fscan(r, &aa)
		fmt.Fscan(r, &bb)
		su += bb
		ma[aa] += bb
		ke = append(ke, aa)
	}
	sort.Slice(ke, func(i, j int) bool {
		return ke[i] < ke[j]
	})
	if su <= int64(k) {
		fmt.Println(1)
		return
	}
	for idx, i := range ke {
		if idx != 0 && ke[idx-1] == ke[idx] {
			continue
		}
		su -= ma[i]
		if su <= int64(k) {
			fmt.Println(i + 1)
			return
		}
	}
}
