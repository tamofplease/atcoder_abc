package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n, m int
	var d int64
	fmt.Scanf("%d %d %d", n, m, d)

	var a, b []int64
	for i := 0; i < n ; i++ {
		var tmp int64
		fmt.Scan(&tmp)
		a = append(a, tmp)
	}
	for i := 0 ; i < m ; i++ {
		var tmp int64
		fmt.Scan(&tmp)
		b = append(b, tmp)
	}
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	sort.Slice(b, func(i, j int) bool { return b[i] < b[j] })

	ans := math.MaxInt64

	var left, right int
	for i := 0 ; i < n ; i++ {
		for right < m && (b[right] - a[i]) <= d {
			right++
		}
		for left < m && (a[i] - b[left]) <= d {
			left++
		}
		ans = int(math.Min)(b[right] + a[i], ans)


	}


}