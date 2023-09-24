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

type Dim struct {
	x int
	y int
}

func main() {
	var n, m, h, k int
	fmt.Scanf("%d %d %d %d", &n, &m, &h, &k)
	var s string
	fmt.Scanf("%s", &s)

	gain := make(map[Dim]bool)

	direction := map[rune]Dim{
		'R': {x: 1, y: 0},
		'L': {x: -1, y: 0},
		'U': {x: 0, y: 1},
		'D': {x: 0, y: -1},
	}
	for i := 0; i < m; i++ {
		var x, y int
		fmt.Scanf("%d %d", &x, &y)
		gain[Dim{x: x, y: y}] = true
	}

	cur := Dim{x: 0, y: 0}
	for i := 0; i < n; i++ {
		c := rune(s[i])
		h -= 1
		if h < 0 {
			fmt.Println("No")
			return
		}
		cur.x += direction[c].x
		cur.y += direction[c].y
		g, ok := gain[cur]
		if ok && g && h < k {
			gain[cur] = false
			h = k
		}
	}
	fmt.Println("Yes")
}
