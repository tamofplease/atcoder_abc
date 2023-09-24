package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdin)
	defer w.Flush()
	var n int
	var s, t string
	fmt.Fscan(r, &n)
	fmt.Fscan(r, &s)
	fmt.Fscan(r, &t)

	for i := 0; i < n; i++ {
		if s[i] == t[i] {
			continue
		}
		if (s[i] == '0' && t[i] == 'o') || (s[i] == 'o' && t[i] == '0') {
			continue
		}
		if (s[i] == '1' && t[i] == 'l') || (s[i] == 'l' && t[i] == '1') {
			continue
		}
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
}
