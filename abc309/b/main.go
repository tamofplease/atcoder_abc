package main

import (
	"fmt"
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
	a := make([]string, 0)
	for i := 0; i < n; i++ {
		var aa string
		fmt.Scan(&aa)
		a = append(a, aa)
	}
	fmt.Printf("%c%s\n", a[1][0], a[0][:n-1])
	for i := 1; i < n-1; i++ {
		fmt.Printf("%c%s%c\n", a[i+1][0], a[i][1:n-1], a[i-1][n-1])
	}
	fmt.Printf("%s%c\n", a[n-1][1:], a[n-2][n-1])
}
