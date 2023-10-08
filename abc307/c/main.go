package main

import "fmt"

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

func replaceAtIndex(input string, replacement rune, index int) string {
	if index < 0 || index >= len(input) {
		// 範囲外のインデックスの場合は元の文字列を返す
		return input
	}

	// 文字列をルーン（Unicode文字）のスライスに変換
	runes := []rune(input)

	// 指定したインデックスの文字を置き換え
	runes[index] = replacement

	// スライスを文字列に戻す
	return string(runes)
}

func deepCopy(base []string) []string {
	newArr := make([]string, len(base))
	for idx, item := range base {
		newArr[idx] = item
	}
	return newArr
}

func paste(base []string, sheet []string, sh int, sw int) []string {
	basees := deepCopy(base)
	w := len(sheet[0])
	h := len(sheet)
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if basees[i+sh][j+sw] == '#' {
				continue
			}
			basees[i+sh] = replaceAtIndex(basees[i+sh], rune(sheet[i][j]), j+sw)
		}
	}
	return basees
}

func isSame(base *[]string, sheet *[]string, sh int, sw int) bool {
	isValid := true
	for i := 0; i < len(*sheet); i++ {
		for j := 0; j < len((*sheet)[0]); j++ {
			if (*base)[i+sh][j+sw] != (*sheet)[i][j] {
				isValid = false
			}
		}
	}

	for i := 0; i < len(*base); i++ {
		for j := 0; j < len((*base)[0]); j++ {
			if i < len(*sheet) && j < len((*sheet)[0]) {
				continue
			}
			if (*base)[i][j] == '#' {
				isValid = false
			}
		}
	}

	return isValid
}

func show(base *[]string) {
	for _, row := range *base {
		fmt.Println(row)
	}
	fmt.Println()
}

func main() {
	sheetC := make([]string, 20)
	for i := 0; i < 20; i++ {
		sheetC[i] = "...................."
	}
	var sheetA, sheetB, sheetX []string

	var ha, wa, hb, wb, hx, wx int
	fmt.Scan(&ha, &wa)
	for i := 0; i < ha; i++ {
		var s string
		fmt.Scan(&s)
		sheetA = append(sheetA, s)
	}
	fmt.Scan(&hb, &wb)
	for i := 0; i < hb; i++ {
		var s string
		fmt.Scan(&s)
		sheetB = append(sheetB, s)
	}
	fmt.Scan(&hx, &wx)
	for i := 0; i < hx; i++ {
		var s string
		fmt.Scan(&s)
		sheetX = append(sheetX, s)
	}
	for i := 0; i < hx; i++ {
		for j := 0; j < wx; j++ {
			res := paste(sheetC, sheetA, i, j)
			for k := 0; k < hx; k++ {
				for l := 0; l < wx; l++ {
					res2 := paste(res, sheetB, k, l)
					show(&res2)
					for x := 0; x < 20-hx+1; x++ {
						for y := 0; y < 20-wx+1; y++ {
							if isSame(&res2, &sheetX, x, y) {
								fmt.Println("Yes")
								return
							}
						}
					}
				}
			}
		}
	}
	fmt.Println("No")
}
