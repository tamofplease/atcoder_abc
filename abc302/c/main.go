package main

import "fmt"


func construct(rem map[int]bool, cur []int, result [][]int) [][]int {
	if len(cur) == len(rem) {
		result = append(result, cur)
		return result
	}
	for k, v := range rem {
		if !v {
			continue
		}
		rem[k] = false
		cur = append(cur, k)
		result = construct(rem, cur, result)
		cur  = cur[:len(cur) - 1]
		rem[k] = true
	}
	return result
}

func diffOne(n int, str1, str2 *string) bool {
	diff := 0
	for i := 0 ; i < n; i++ {
		if ((*str1)[i] != (*str2)[i]) {
			diff += 1
		}
	}
	return diff == 1
}

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	result := make([][]int, 0)
	rem := make(map[int]bool)
	var cur []int
	for i := 0 ; i < n ; i++ {
		rem[i] = true
	}
	strings := make([]string, 0, n)
	
	for i := 0 ; i < n ; i++ {
		var s string
		fmt.Scan(&s)
		strings = append(strings, s)
	}
	result = construct(rem, cur, result)
	for _, item := range result {
		fmt.Println(item)
		valid := true
		for i := 0 ; i < n - 1 ; i++ {
			if !diffOne(m, &strings[item[i]], &strings[item[i + 1]]) {
				valid = false
				break
			}
		}
		if valid {
			fmt.Println("Yes")
			return;
		}
	}
	fmt.Println("No")
}