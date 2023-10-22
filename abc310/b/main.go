package main

import (
	"bufio"
	"fmt"
	"os"
)

// Simple math functions

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func min64(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func max64(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func abs64(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func gcd64(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd64(b, a%b)
}

type Product struct {
	price    int
	features []int
}

func (p *Product) hasAllFeatures(other *Product) bool {
	for _, feature := range (*other).features {
		hasFeature := false
		for _, feat := range (*p).features {
			if feat == feature {
				hasFeature = true
			}
		}
		if !hasFeature {
			return false
		}
	}
	return true
}

func (p *Product) isSuperior(other Product) bool {
	if !p.hasAllFeatures(&other) {
		return false
	}
	if p.price > other.price {
		return false
	}
	return len(p.features) > len((other).features) || p.price < other.price
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Scan(&n, &m)

	products := make([]Product, 0)
	for i := 0; i < n; i++ {
		var price, c int
		fmt.Fscan(r, &price, &c)
		features := make([]int, 0)
		for j := 0; j < c; j++ {
			var f int
			fmt.Fscan(r, &f)
			features = append(features, f)
		}
		products = append(products, Product{
			price:    price,
			features: features,
		})
	}
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if products[i].isSuperior(products[j]) || products[j].isSuperior(products[i]) {
				fmt.Println("Yes")
				return
			}
		}
	}
	fmt.Println("No")
}
