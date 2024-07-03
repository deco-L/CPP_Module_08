/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/07/03 23:38:56 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

class Span
{
private:
  unsigned int              _size;
  std::vector<unsigned int> _array;

public:
  Span( void );
  Span( int size );
  Span( const Span& obj );

  void  addNumber( const int& element );
  unsigned int shortestSpan( void );
  unsigned int longestSpan( void );

  class arrayOverflowing : public std::exception
  {
  public:
    virtual const char* what( void ) const throw();
  };

  class invalidArrayIndex : public std::exception
  {
  public:
    virtual const char* what( void ) const throw();
  };

  Span& operator=( const Span& obj );
};

#endif
