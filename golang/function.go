package main

import "fmt"

func main() {

	fmt.Println("Hello, World!")

	/* 函数
	func function_name( [parameter list] ) [return_types]
	{
		   函数体
	}
	*/
	function_test();
}

/*-----------函数部分 begin-------------------------*/
func swapV2(x *int, y *int) {
	var temp int
	temp = *x    /* 保持 x 地址上的值 */
	*x = *y      /* 将 y 值赋给 x */
	*y = temp    /* 将 temp 值赋给 y */
}

// 返回多个值
func swap(x, y string) (string, string) {
	return y, x
}

func getSequence() func() int {
	i:=0
	return func() int {
		i += 1
		return i
	}
}

// 函数
func function_test() {
	/* 返回两个函数 */
	a, b := swap("World", "hello")
	fmt.Printf("返回两个变量 a : %s b : %s\n", a, b )

	var x = 10
	var y = 20

	fmt.Printf("交换前，x 的值 : %d\n", x )
	fmt.Printf("交换前，y 的值 : %d\n", y )

	/* go 默认是值传递 引用传递 例子*/
	swapV2(&x, &y)

	fmt.Printf("交换后，x 的值 : %d\n", x )
	fmt.Printf("交换后，y 的值 : %d\n", y )

	/* nextNumber 为一个函数，函数 i 为 0 */
	nextNumber := getSequence()

	/* 调用 nextNumber 函数，i 变量自增 1 并返回 */
	fmt.Println(nextNumber())
	fmt.Println(nextNumber())
	fmt.Println(nextNumber())

	/* 创建新的函数 nextNumber1，并查看结果 */
	nextNumber1 := getSequence()
	fmt.Println(nextNumber1())
	fmt.Println(nextNumber1())

	/* 函数方法 */
	/* func (variable_name variable_data_type) function_name() [return_type]{
		   // 函数体
		}
	*/

	var c1 Circle
	c1.radius = 10.00
	fmt.Println("Area of Circle(c1) = ", c1.getArea())
}

/* 定义函数 */
type Circle struct {
	  radius float64
}

//该 method 属于 Circle 类型对象中的方法
func (c Circle) getArea() float64 {
	//c.radius 即为 Circle 类型对象中的属性
	return 3.14 * c.radius * c.radius
}


/*-----------函数部分 end ----------------------*/

