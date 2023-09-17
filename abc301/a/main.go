package main

import "fmt"

func main() {
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)

	a, t := 0, 0
	for _, c := range s {
		if c == 'A' {
			a++
		} 
		if c == 'T' {
			t++
		}
	}
	if a > t {
		fmt.Println("A")
		return
	} else  if t > a {
		fmt.Println("T")
		return
	}
	a, t = 0, 0
	for _, c := range s {
		if c == 'A' {
			a++
		} 
		if c == 'T' {
			t++
		}
		if a == n / 2 {
			fmt.Println("A")
			return
		}
		if t == n / 2 {
			fmt.Println("T")
			return
		}
	}
}