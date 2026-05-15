/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:20:25 by opapouts          #+#    #+#             */
/*   Updated: 2026/04/30 16:20:27 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

/*************************************************
                   Test Cases                     
*************************************************/
static void	testcase0(void) {
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(10), Fixed(0));
	Point	c(Fixed(0), Fixed(10));
	Point	point(Fixed(1), Fixed(1));
	
	std::cout << "Test0 input is: a(0, 0), b(10, 0), c(0, 10), point(1, 1)" << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "The point is located inside the triangle abc" << std::endl;
	else
		std::cout << "The point is outside the triangle abc" << std::endl;
}
static void	testcase1(void) {
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(10), Fixed(0));
	Point	c(Fixed(0), Fixed(10));
	Point	point(Fixed(15), Fixed(15));
	
	std::cout << "Test1 input is: a(0, 0), b(10, 0), c(0, 10), point(15, 15)" << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "The point is located inside the triangle abc" << std::endl;
	else
		std::cout << "The point is outside the triangle abc" << std::endl;
}
static void	testcase2(void) {
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(10), Fixed(0));
	Point	c(Fixed(0), Fixed(10));
	Point	point(Fixed(5), Fixed(0));
	
	std::cout << "Test2 input is: a(0, 0), b(10, 0), c(0, 10), point(5, 0)" << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "The point is located inside the triangle abc" << std::endl;
	else
		std::cout << "The point is outside the triangle abc" << std::endl;
}
static void	testcase3(void) {
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(10), Fixed(0));
	Point	c(Fixed(0), Fixed(10));
	Point	point(Fixed(10), Fixed(0));
	
	std::cout << "Test3 input is: a(0, 0), b(10, 10), c(0, 10), point(10, 0)" << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "The point is located inside the triangle abc" << std::endl;
	else
		std::cout << "The point is outside the triangle abc" << std::endl;
}
static void	testcase4(void) {
	Point	a(Fixed(-5), Fixed(-5));
	Point	b(Fixed(5), Fixed(-5));
	Point	c(Fixed(0), Fixed(5));
	Point	point(Fixed(0), Fixed(0));
	
	std::cout << "Test4 input is: a(-5, -5), b(5, -5), c(0, 5), point(0, 0)" << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "The point is located inside the triangle abc" << std::endl;
	else
		std::cout << "The point is outside the triangle abc" << std::endl;
}

/*************************************************
                   Main                     
*************************************************/
int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Wrong input choose a number in this range (0->3)" << std::endl;
		return (1);
	}
	if (av[1][0] == '0') {
		testcase0();
		return (0);
	}
	if (av[1][0] == '1') {
		testcase1();
		return (0);
	}
	if (av[1][0] == '2') {
		testcase2();
		return (0);
	}
	if (av[1][0] == '3') {
		testcase3();
		return (0);
	}
	if (av[1][0] == '4') {
		testcase4();
		return (0);
	}
	else {
		std::cout << "Wrong input choose a number in this range (0->4)" << std::endl;
		return (1);
	}
}
