package main

import "fmt"

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
	var n, m int
	c := make([]string, 0)
	d := make([]string, 0)
	p := make([]int, 0)
	fmt.Scanf("%d %d", &n, &m)
	for i := 0; i < n; i++ {
		var cc string
		fmt.Scan(&cc)
		c = append(c, cc)
	}
	for i := 0; i < m; i++ {
		var dd string
		fmt.Scan(&dd)
		d = append(d, dd)
	}
	for i := 0; i <= m; i++ {
		var pp int
		fmt.Scan(&pp)
		p = append(p, pp)
	}
	ans := 0
	for i := 0; i < n; i++ {
		idx := -1
		for j := 0; j < m; j++ {
			if d[j] == c[i] {
				idx = j
			}
		}
		ans += p[idx+1]
	}
	fmt.Println(ans)
}
