package main

import "fmt"

func quick_sort(*[]int array) {
	
}

func main() {
	s := []int{9,8,7,6,5,4,3,2,1}
	quick_sort(&s)
	for _, num := range s {
		fmt.Println(num)
	}
}