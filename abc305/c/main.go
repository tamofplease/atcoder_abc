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
	var h, w int
	fmt.Scanf("%d %d", &h, &w)
	grid := make([]string, 0)
	for i := 0; i < h; i++ {
		var s string
		fmt.Scanf("%s", &s)
		grid = append(grid, s)
	}
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if grid[i][j] == '#' {
				continue
			}
			cnt := 0
			if i != 0 && grid[i-1][j] == '#' {
				cnt++
			}
			if i != h-1 && grid[i+1][j] == '#' {
				cnt++
			}
			if j != 0 && grid[i][j-1] == '#' {
				cnt++
			}
			if j != w-1 && grid[i][j+1] == '#' {
				cnt++
			}
			if cnt > 1 {
				fmt.Println(i+1, j+1)
				return
			}
		}
	}
}
