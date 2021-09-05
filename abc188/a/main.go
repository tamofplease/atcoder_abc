package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var X, Y int
	fmt.Fscan(r, &X, &Y)

	if X > Y && X-Y < 3 {
		fmt.Fprintln(w, "Yes")
	} else if Y > X && Y-X < 3 {
		fmt.Fprintln(w, "Yes")
	} else {
		fmt.Fprintln(w, "No")
	}
}
