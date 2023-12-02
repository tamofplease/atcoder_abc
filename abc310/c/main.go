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

func Reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var n int
	fmt.Scan(&n)
	s := make(map[string]int, 0)
	for i := 0; i < n; i++ {
		var ss string
		fmt.Fscan(r, &ss)
		r_s := Reverse(ss)
		_, ok := s[ss]
		if ok {
			s[ss] += 1
			continue
		}
		_, ok2 := s[r_s]
		if ok2 {
			s[r_s] += 1
			continue
		}
		s[ss] = 1
	}
	fmt.Println(len(s))
}
