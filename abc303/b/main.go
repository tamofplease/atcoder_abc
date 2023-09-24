package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	w := bufio.NewWriter(os.Stdout)
	r := bufio.NewReader(os.Stdin)
	defer w.Flush()
	var n, m int
	fmt.Fscanf(r, "%d %d", &n, &m)

	a := make([][]bool, 0, 51)
	for i := 0; i < n; i++ {
		a = append(a, make([]bool, 51))
	}

	for i := 0; i < m; i++ {
		prev := -1
		for j := 0; j < n; j++ {
			var cur int
			fmt.Fscan(r, &cur)
			cur -= 1
			if prev != -1 {
				a[prev][cur] = true
				a[cur][prev] = true
			}
			prev = cur
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if i == j {
				continue
			}
			if !a[i][j] {
				ans += 1
			}
		}
	}
	fmt.Println(ans)
}
