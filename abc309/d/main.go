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
	reader := bufio.NewReader(os.Stdin)
	var n1, n2, m int
	fmt.Scan(&n1, &n2, &m)
	graph := make(map[int][]int)
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		graph[a-1] = append(graph[a-1], b-1)
		graph[b-1] = append(graph[b-1], a-1)
	}
	memo := make([]int, 0)
	for i := 0; i < (n1 + n2); i++ {
		memo = append(memo, m+2)
	}
	memo[0] = 0
	memo[n1+n2-1] = 0

	q := make([]int, 0)
	q = append(q, 0)
	for len(q) != 0 {
		cur := q[0]
		q = q[1:]
		for _, nxt := range graph[cur] {
			if memo[nxt] == m+2 {
				memo[nxt] = memo[cur] + 1
				q = append(q, nxt)
			}
		}
	}
	q = append(q, n1+n2-1)
	for len(q) != 0 {
		cur := q[0]
		q = q[1:]
		for _, nxt := range graph[cur] {
			if memo[nxt] == m+2 {
				memo[nxt] = memo[cur] + 1
				q = append(q, nxt)
			}
		}
	}

	n1Max := 0
	n2Max := 0
	for i := 0; i < n1; i++ {
		n1Max = max(n1Max, memo[i])
	}
	for i := n1; i < n1+n2; i++ {
		n2Max = max(n2Max, memo[i])
	}
	fmt.Println(n1Max + n2Max + 1)
}
