package main

import (
	"fmt"
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
	fmt.Scan(&n)
	memo := make(map[int][]int)
	for i := 0; i < n*3; i++ {
		var a int
		fmt.Scan(&a)
		memo[a-1] = append(memo[a-1], i+1)
	}
	ans := make([][]int, 0)
	for i := 0; i < n; i++ {
		ans = append(ans, []int{memo[i][1], i + 1})
	}
	sort.Slice(ans, func(i, j int) bool { return ans[i][0] < ans[j][0] })
	for _, v := range ans {
		fmt.Printf("%d ", v[1])
	}
	fmt.Println()
}
