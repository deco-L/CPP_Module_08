/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/09/20 13:39:43 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

static size_t get_term_line() {
	winsize	terminal_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size);
	return (terminal_size.ws_col);
}

static void draw_terminal_line() {
	size_t	terminal_col;

	terminal_col = get_term_line();
	for (size_t i = 0; i < terminal_col; i++)
		std::cout << "=";
	std::cout << std::endl;
	return ;
}

int main(void) {
  {
    draw_terminal_line();
    std::cout << "\033[1;38;5;120m+++++normal case+++++\033[0m" << std::endl;
    try {
      Span array = Span(5);
      array.addNumber(6);
      array.addNumber(3);
      array.addNumber(17);
      array.addNumber(9);
      array.addNumber(11);
      std::cout << array.shortestSpan() << std::endl;
      std::cout << array.longestSpan() << std::endl;
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    draw_terminal_line();
  }
  {
    try {
      Span array(200);
      for (int i = 0; i < 200; i++) {
        int element = rand();
        array.addNumber(element);
      }
      std::cout << array.shortestSpan() << std::endl;
      std::cout << array.longestSpan() << std::endl;
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    draw_terminal_line();
  }
  {
    try {
      std::vector<unsigned int> srcArray(200, 0);
      Span array(200);

      for (int i = 0; i < 200; i++)
        srcArray[i] = rand();
      array.addNumbers(srcArray);
      std::cout << array.shortestSpan() << std::endl;
      std::cout << array.longestSpan() << std::endl;
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    draw_terminal_line();
  }
  {
    try {
      std::cout << "\033[1;38;5;120m+++++error case+++++\033[0m" << std::endl;
      Span array(10);
      for (int i = 0; i < 12; i++) {
        array.addNumber(rand());
      }
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    draw_terminal_line();
    try {
      Span array(1);
      for (int i = 0; i < 1; i++) {
        array.addNumber(-10);
      }
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    draw_terminal_line();
  }
  return (EXIT_SUCCESS);
}
