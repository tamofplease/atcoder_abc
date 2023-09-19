package main

import "fmt"

func main() {
	var a, b int64
	fmt.Scanf("%d %d", &a, &b)

	ans := a / b
	if a % b != 0 {
		ans += 1
	}
	fmt.Println(ans)
}