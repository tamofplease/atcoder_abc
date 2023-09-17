package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var a []int
	for i := 0; i < n; i++ {
		var j int
		fmt.Scan(&j)
		a = append(a, j)
	}

	var ans []int
	prev := -1
	for _, cur := range a {
		if prev == -1 {
			ans = append(ans, cur)
			prev  = cur
			continue
		}
		if cur > prev {
			for i := prev + 1; i <= cur; i++ {
				ans  = append(ans, i)
			}
		}
		if prev > cur {
			for i := prev - 1; i >= cur; i-- {
				ans = append(ans, i)
			}
		}
		prev = cur
	}
	for _, n := range ans {
		fmt.Printf("%v ", n)
	}
	fmt.Println()

}
