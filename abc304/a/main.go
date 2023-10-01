package main

import (
	"fmt"
	"math"
)

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var N int
	fmt.Scan(&N)

	m := math.MaxInt32
	arr := make([]string, 0)
	ar := make([]int, 0)

	for i := 0; i < N; i++ {
		var s string
		var a int
		fmt.Scanf("%s %d", &s, &a)
		arr = append(arr, s)
		ar = append(ar, a)
		m = Min(m, a)
	}

	idx := 0

	for i := 0; i < N; i++ {
		if ar[i] == m {
			idx = i
			break
		}
	}

	for i := 0; i < N; i++ {
		fmt.Println(arr[idx])
		idx += 1
		idx %= N
	}
}
