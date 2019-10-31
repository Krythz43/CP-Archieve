package main

import "fmt"

func main(){
	var t,x,y int64
	fmt.Scanf("%d\n",&t)
	for t>0 {
		t--
		fmt.Scanf("%d %d\n",&x,&y)
		if x > y + 1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
