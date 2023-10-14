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
	s := make([]int, 8)
	for i := 0; i < 8; i++ {
		fmt.Scan(&s[i])
	}
	valid := true
	for i := 0; i < 8; i++ {
		if s[i]%25 != 0 {
			valid = false
		}

		if s[i] < 100 || 675 < s[i] {
			valid = false
		}
		if i != 0 && s[i-1] > s[i] {
			valid = false
		}
	}
	if valid {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
