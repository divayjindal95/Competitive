package main

import "fmt"
//import "math"

func main(){

	n:=10
	arr :=fibonacci(n)
	fmt.Println(arr)

}

func fibonacci(n int) [10]int {
	i:=0
	a:=0
	b:=1
	c:=0
	var arr [10]int
	for i<10{
		c=a+b
		a=b
		b=c
		arr[i]=c
		fmt.Println("%d",c)
		i++
	} 
	return arr
}