/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                MutantStack           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/07/08 12:53:32 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>
#include <ctime>

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
  srand(std::time(0));
  {
    draw_terminal_line();
    std::cout << "\033[1;38;5;120m=====default test case=====\033[0m" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "mstadk top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "\033[1;38;5;208mmstack\033[0m" << std::endl;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::cout << "\033[1;38;5;208mstack\033[0m" << std::endl;
    std::stack<int> s(mstack);
    while (s.size())
    {
      std::cout << s.top() << std::endl;
      s.pop();
    }
    draw_terminal_line();
  }
  {
    std::cout << "\033[1;38;5;120m=====Additional test cases=====\033[0m" << std::endl;
    MutantStack<unsigned int> mstack;
    for (int i = 0; i < 5; i++)
      mstack.push(rand());

    MutantStack<unsigned int>::iterator it = mstack.begin();
    MutantStack<unsigned int>::const_iterator cit = mstack.begin();
    MutantStack<unsigned int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<unsigned int>::const_reverse_iterator crit = mstack.rbegin();

    std::cout << "\033[1;38;5;86miterator case\033[0m" << std::endl;
    for (; it != mstack.end(); it++)
      std::cout << *it << std::endl;
    std::cout << "\033[1;38;5;86mconst_iterator case\033[0m" << std::endl;
    for (; cit != mstack.end(); cit++)
      std::cout << *cit << std::endl;
    std::cout << "\033[1;38;5;86mreverse_iterator case\033[0m" << std::endl;
    for (; rit != mstack.rend(); rit++)
      std::cout << *rit << std::endl;
    std::cout << "\033[1;38;5;86mconst_reverse_iterator case\033[0m" << std::endl;
    for (; crit != mstack.rend(); crit++)
      std::cout << *crit << std::endl;
    draw_terminal_line();
  }
  return (EXIT_SUCCESS);
}
