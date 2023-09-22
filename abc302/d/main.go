package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func Max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdin)
	defer w.Flush()
	var n, m int
	var d int64
	fmt.Fscanf(r, "%d %d %d", &n, &m, &d)

	var a, b []int64
	for i := 0; i < n ; i++ {
		var tmp int64
		fmt.Fscan(r, &tmp)
		a = append(a, tmp)
	}
	for i := 0 ; i < m ; i++ {
		var tmp int64
		fmt.Fscan(r, &tmp)
		b = append(b, tmp)
	}
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	sort.Slice(b, func(i, j int) bool { return b[i] < b[j] })

	var ans int64 = -1

	left := 0
	right := 0
	for i := 0 ; i < n ; i++ {
		mi := a[i] - d
		ma := a[i] + d
		for left < m && b[left] < mi {
			left++
		}
		for right < m && b[right] <= ma {
			right++
		}
		if right - left > 0 {
			ans = Max(ans, b[right - 1] + a[i])
		}
	}
	fmt.Println(ans)
}