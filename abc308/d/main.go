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

func rec(grid *[]string, been *[][]bool, idx, r, c int) bool {
	(*been)[r][c] = true
	base := "snuke"
	if (*grid)[r][c] != base[idx] {
		return false
	}
	nxt := []int{
		0, 1, 0, -1, 0,
	}
	for i := 0; i < 4; i++ {
		nr := nxt[i] + r
		nc := nxt[i+1] + c
		if 0 <= nr && nr < len(*grid) && 0 <= nc && nc < len((*grid)[0]) && !(*been)[nr][nc] && (*grid)[nr][nc] == base[(idx+1)%5] {
			if nr == (len(*grid)-1) && nc == (len((*grid)[0])-1) || rec(grid, been, (idx+1)%5, nr, nc) {
				return true
			}
		}
	}
	return false
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var h, w int
	fmt.Scan(&h, &w)
	s := make([]string, 0)

	for i := 0; i < h; i++ {
		var ss string
		fmt.Fscan(r, &ss)
		s = append(s, ss)
	}
	been := make([][]bool, 0)
	for i := 0; i < h; i++ {
		bb := make([]bool, 0)
		for j := 0; j < w; j++ {
			bb = append(bb, false)
		}
		been = append(been, bb)
	}

	if s[0][0] == 's' && rec(&s, &been, 0, 0, 0) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
