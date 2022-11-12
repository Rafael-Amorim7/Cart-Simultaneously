package main

import (
	"fmt"
	"time"
)

type items struct {
	id      int
	product string
	price   float64
}

func Map(data []items, f func(items) float64) []float64 {
	mapped := make([]float64, len(data))
	for i, e := range data {
		mapped[i] = f(e)
	}
	return mapped
}

func Sum(array []float64) float64 {
	var result float64 = 0
	for _, v := range array {
		result += v
	}
	return result
}

func main() {
	start := time.Now()

	go func() {
		cart := []items{
			{id: 1, product: "iPhone", price: 499.0},
			{id: 2, product: "Kindle", price: 179.0},
			{id: 3, product: "Macbook", price: 1199.0},
		}
		cartPrices := Map(cart, func(i items) float64 { return i.price })
		cartSum := Sum(cartPrices)
		fmt.Println("Cart -> ", cart)
		fmt.Println("Sum -> ", cartSum)
	}()

	go func() {
		cart := []items{
			{id: 1, product: "PlayStation 5", price: 499.0},
			{id: 2, product: "Bike", price: 179.0},
			{id: 3, product: "iPad Pro", price: 1099.0},
		}
		cartPrices := Map(cart, func(i items) float64 { return i.price })
		cartSum := Sum(cartPrices)
		fmt.Println("Cart -> ", cart)
		fmt.Println("Sum -> ", cartSum)
	}()

	go func() {
		cart := []items{
			{id: 1, product: "Galaxy S20", price: 599.0},
			{id: 2, product: "Samsung pen", price: 179.0},
			{id: 3, product: "Samsung OLED", price: 1199.0},
		}
		cartPrices := Map(cart, func(i items) float64 { return i.price })
		cartSum := Sum(cartPrices)
		fmt.Println("Cart -> ", cart)
		fmt.Println("Sum -> ", cartSum)
	}()

	time.Sleep(1 * time.Second)
	t := time.Now()
	elapsed := t.Sub(start)
	fmt.Println(elapsed)
}
