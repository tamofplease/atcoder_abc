package main

import "fmt"

func main() {
	var h, w int
	fmt.Scanf("%d %d", &h, &w)
	var grid []string
	for i := 0 ; i < h ; i++ {
		var s string
		fmt.Scan(&s)
		grid = append(grid, s)
	}

	base := "snuke"

	for i := 0 ; i < h ; i++ {
		for j := 0 ; j < w ; j++ {
			for _, yd := range []int{-1, 1, 0} {
				for _, xd := range []int{-1, 1, 0} {
					cnt := make([][]int, 0, 0)
					for d := 0 ; d < 5 ; d++ {
						cy, cx := i + d * yd, j + d * xd
						if 0 <= cy && cy < h && 0 <= cx && cx < w {
							if grid[cy][cx] != base[d] {
								break;
							}
							cnt = append(cnt, []int{cy + 1, cx + 1})
						}
					}
					if len(cnt) == 5 {
						for _, cc := range cnt {
							fmt.Printf("%d %d\n", cc[0], cc[1])
						}
						return
					}
				}
			}
		}
	}
}