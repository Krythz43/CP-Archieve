package main

import "fmt"

func main(){
	var n,m,t int64
	t = 0
	fmt.Scanf("%d %d\n",&n,&m)
	for ;;t++ {
		if n<=t/2 && m<=t/3 && n+m<=t/2+t/3-t/6{
			fmt.Println(t)
			break
		}
	}
}
