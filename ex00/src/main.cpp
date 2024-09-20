/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/09/20 13:09:53 by csakamot         ###   ########.fr       */
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
    std::cout << "\033[38;5;120mElement " << element << " found position : "
              << it - array.begin() << " (counting from zero)\033[0m"
              << std::endl;
  }
  else
    std::cout << "\e[38;5;196mElement not found.\e[0m" << std::endl;
  draw_terminal_line();
  it = easyfind(array, 10);
  if ( it != array.end() )
  {
    std::cout << "\033[38;5;120mElement " << element << " found position : "
              << it - array.begin() << " (counting from zero)\033[0m"
              << std::endl;
  }
  else
    std::cout << "\e[38;5;196mElement not found.\e[0m" << std::endl;
  draw_terminal_line();
  return (EXIT_SUCCESS);
}
