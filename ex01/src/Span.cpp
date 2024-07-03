/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/07/04 00:01:59 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0), _array(0)
{}

Span::Span(int size) : _size(size), _array(0)
{}

Span::Span(const Span& obj) : _size(obj._size), _array(obj._size)
{
  *this = obj;
}

const char* Span::arrayOverflowing::what(void) const throw()
{
  return ("\e[1;138;5;182mError: The array is overflowing.\e[0m");
}

const char* Span::invalidArrayIndex::what(void) const throw()
{
  return ("\e[1;138;5;182mError: Invalid array index. Array indices must be non-negative.\e[0m");
}

void  Span::addNumber(const int& element)
{
  this->_array.push_back(element);
  return ;
}

unsigned int Span::shortestSpan(void)
{
  std::vector<unsigned int>  copy(this->_array);
  std::vector<int>  diff(this->_size);

  std::sort(copy.begin(), copy.end());
  std::adjacent_difference(copy.begin(), copy.end(), diff.begin());
  return (*std::min_element(diff.begin(), diff.end()));
}

unsigned int Span::longestSpan(void)
{
  std::vector<unsigned int>  copy(this->_array);

  std::sort(copy.begin(), copy.end());
  return (copy.back() - copy.front());
}

Span& Span::operator=(const Span& obj)
{
  if (this != &obj)
  {
    this->_size = obj._size;
    std::vector<unsigned int> array(this->_size);
    this->_array = array;
    for (unsigned int index = 0; index < this->_size; index++)
      this->_array[index] = obj._array[index];
  }
  else
    std::cout << "\e[1;31mAnimal Error: "
              << "Attempted self-assignment in copy assignment operator"
              << "\e[0m" << std::endl;
  return (*this);
}
