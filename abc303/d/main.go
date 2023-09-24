package main

import (
	"fmt"
	"math"
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

type Status struct {
	on bool
}

func main() {
	var x, y, z int64
	var s string

	fmt.Scanf("%d %d %d", &x, &y, &z)
	fmt.Scan(&s)

	prevStatus := make(map[bool]int64)
	curStatus := make(map[bool]int64)

	prevStatus[false] = 0
	prevStatus[true] = math.MaxInt64 - math.MaxInt32
	curStatus[false] = math.MaxInt64 - math.MaxInt32
	curStatus[true] = math.MaxInt64 - math.MaxInt32

	for _, c := range s {
		curStatus[false] = math.MaxInt64 - math.MaxInt32
		curStatus[true] = math.MaxInt64 - math.MaxInt32
		for key, value := range prevStatus {
			if c == 'A' {
				if key {
					curStatus[true] = min64(curStatus[true], value+x)
					curStatus[false] = min64(curStatus[false], value+x+z)
					curStatus[false] = min64(curStatus[false], value+z+y)
				}
				if !key {
					curStatus[false] = min64(curStatus[false], value+y)
					curStatus[true] = min64(curStatus[true], value+y+z)
					curStatus[true] = min64(curStatus[true], value+x+z)
				}
			}

			if c == 'a' {
				if key {
					curStatus[true] = min64(curStatus[true], value+y)
					curStatus[false] = min64(curStatus[false], value+y+z)
					curStatus[false] = min64(curStatus[false], value+z+x)
				}
				if !key {
					curStatus[false] = min64(curStatus[false], value+x)
					curStatus[true] = min64(curStatus[true], value+x+z)
					curStatus[true] = min64(curStatus[true], value+y+z)
				}
			}
		}
		prevStatus[false] = curStatus[false]
		prevStatus[true] = curStatus[true]
	}

	fmt.Println(min64(curStatus[true], curStatus[false]))
}
