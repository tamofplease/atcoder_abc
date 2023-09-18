package main

import "fmt"

func Reverse(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}

func ReverseArray(s []int64) []int64 {
	result := s
	for i, j := 0, len(s) - 1; i < j; i, j = i + 1, j - 1 {
		result[i], result[j] = result[j], result[i]
	}
	return result
}

func main() {
	var s string
	fmt.Scan(&s)
	var n int64
	fmt.Scan(&n)

	var cur int64 = 0
	var m int64 = 1

	s = Reverse(s)

	var candidates []int64 

	for _, c := range s {
		if c == '?' {
			candidates = append(candidates, m)
		}
		if c == '1' {
			cur += m
		}
		m <<= 1
	}

	if cur > n {
		fmt.Println("-1")
		return;
	}

	candidates  = ReverseArray(candidates)

	for _, c := range candidates {
		if cur <= n - c {
			cur += c
		}
	}
	fmt.Println(cur)
}