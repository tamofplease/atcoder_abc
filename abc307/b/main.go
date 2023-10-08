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

func isPalindrome(s *string, t *string) bool {
	st := *s + *t
	for i := 0; i < len(st)/2; i++ {
		if st[i] != st[len(st)-i-1] {
			return false
		}
	}
	return true
}

func main() {
	var n int
	fmt.Scan(&n)

	s := make([]string, 0)
	for i := 0; i < n; i++ {
		var ss string
		fmt.Scan(&ss)
		s = append(s, ss)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if isPalindrome(&s[i], &s[j]) {
				fmt.Println("Yes")
				return
			}
		}
	}
	fmt.Println("No")
}
