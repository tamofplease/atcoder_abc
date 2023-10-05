package main

type Polinomino struct {
	row1 string
	row2 string
	row3 string
	row4 string
}

func getBeginIndex(row string) int {
	for i := 0; i < 4; i++ {
		if row[i] == '#' {
			return i
		}
	}
	return 0
}

func getEndIndex(row string) int {
	for i := 3; i >= 0; i-- {
		if row[i] == '#' {
			return i
		}
	}
	return 3
}

func (f *Polinomino) width() int {
	f.row1
	return
}

func (f *Polinomino) height() int {
	return 4
}

func main() {
}
