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

func main() {
	r := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Scan(&n, &m)
	children := make([][]int, 0)
	insurance := make([]int, 0)
	for i := 0; i < n; i++ {
		children = append(children, []int{})
		insurance = append(insurance, -1)
	}
	for i := 1; i < n; i++ {
		var p int
		fmt.Fscan(r, &p)
		if i == 0 {
			continue
		}
		p -= 1
		children[p] = append(children[p], i)
	}
	for i := 0; i < m; i++ {
		var x, y int
		fmt.Fscan(r, &x, &y)
		insurance[x-1] = max(insurance[x-1], y)
	}
	q := make([]int, 0)
	q = append(q, 0)
	ans := 0
	for len(q) != 0 {
		cur := q[0]
		q = q[1:]
		if insurance[cur] >= 0 {
			ans++
		}
		for _, child := range children[cur] {
			insurance[child] = max(insurance[child], insurance[cur]-1)
			q = append(q, child)
		}
	}
	fmt.Println(ans)
}
