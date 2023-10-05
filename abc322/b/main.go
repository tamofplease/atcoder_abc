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
	var s, t string
	fmt.Scanf("%d %d", &n, &m)
	fmt.Scan(&s, &t)
	ans := 3
	isPrefix := true
	isSuffix := true
	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			isPrefix = false
		}
	}
	for i := 0; i < n; i++ {
		if s[i] != t[m-n+i] {
			isSuffix = false
		}
	}
	if isPrefix {
		ans -= 2
	}
	if isSuffix {
		ans -= 1
	}
	fmt.Println(ans)
}
