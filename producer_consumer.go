package main

import "fmt"
import "time"

func Producer (queue chan<- int) {
        for i:= 0; i < 10; i++ {
                fmt.Println("produce:", i)
                queue <- i
        }
}

func Consumer(queue <-chan int) {
        for i :=0; i < 10; i++ {
                v := <- queue
                fmt.Println("receive:", v)
        }
}

func main() {
        queue := make(chan int, 1)
        go Producer(queue)
        go Consumer(queue)
        time.Sleep(1e9)
}