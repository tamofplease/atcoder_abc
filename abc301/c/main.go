package main

import (
	"fmt"
)

func containsRune(s string, r rune) bool {
	for _, char := range s {
		if char == r {
			return true
		}
	}
	return false
}

func main() {
	var s, t string
	fmt.Scanf("%v\n%v", &s, &t)
	ma1 := make(map[rune]int)
	ma2 := make(map[rune]int)

	for _, c := range s {
		ma1[c]++
	}
	for _, c := range t {
		ma2[c]++
	}

	base := "atcoder"

	for i := 0; i < 26; i++ {
		c := rune(i + 'a')
		if containsRune(base, c) {
			continue
		}
		val1 := ma1[c]
		val2 := ma2[c]
		if val1 == val2 {
			continue
		}
		fmt.Println("No")
		return
	}
	s_whild := ma1['@']
	t_whild := ma2['@']

	for _, c := range base {
		val1 := ma1[c]
		val2 := ma2[c]

		if val1 > val2 {
			t_whild -= val1 - val2
		}
		if val2 > val1 {
			s_whild -= val2 - val1
		}
	}
	if s_whild < 0 || t_whild < 0 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}

}
