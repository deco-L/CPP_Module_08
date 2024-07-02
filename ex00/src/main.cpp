/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/07/03 00:08:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
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
  draw_terminal_line();
  std::vector<int>            array;
  std::vector<int>::iterator  it;
  int                         element;

  element = 3;
  for (unsigned int index = 0; index < 10; index++)
  {
    array.push_back(index);
  }
  it = easyfind(array, 3);
  if ( it != array.end() )
  {
    std::cout << "Element " << element << " found position : "
              << it - array.begin() << " (counting from zero)"
              << std::endl;
  }
  else
    std::cout << "\e[0;138;5;183mElement not found.\e[0m" << std::endl;
  draw_terminal_line();
  return (EXIT_SUCCESS);
}
