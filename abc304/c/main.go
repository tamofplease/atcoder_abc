package main

import (
	"fmt"
	"math"
)

func getDistance(ax, ay, bx, by int) float64 {
	return math.Sqrt(float64(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by))))
}

func main() {
	var n, d int
	fmt.Scanf("%d %d", &n, &d)
	xa := make([]int, 0)
	ya := make([]int, 0)
	ans := make([]bool, 0)
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scanf("%d %d", &x, &y)
		xa = append(xa, x)
		ya = append(ya, y)
		ans = append(ans, false)
	}
	ans[0] = true

	nxt := make([]int, 0)
	nxt = append(nxt, 0)

	for i := 0; i < n; i++ {
		if len(nxt) <= i {
			break
		}
		k := nxt[i]
		for j := 0; j < n; j++ {
			if k == j {
				continue
			}
			distance := getDistance(xa[k], ya[k], xa[j], ya[j])
			if distance <= float64(d) && !ans[j] {
				ans[j] = true
				nxt = append(nxt, j)
			}
		}
	}
	for i := 0; i < n; i++ {
		if ans[i] {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
