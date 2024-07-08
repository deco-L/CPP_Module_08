/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/07/08 12:56:20 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <cstdlib>
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
  MutantStack( void );
  MutantStack( const MutantStack& obj );
  ~MutantStack();

  typedef typename std::stack<T>::container_type::iterator iterator;
  // class iterator : public std::iterator
  // {
  // public:
  //   iterator& operator++( void );
  //   iterator  operator++( int );
  //   iterator& operator--( void );
  //   iterator  operator--( int );
  //   bool  operator==( iterator other ) const;
  //   bool  operator!=( iterator other ) const;
  //   reference operator*( void ) const;
  // };

  iterator  begin( void );
  iterator  end( void );

  MutantStack& operator=( const MutantStack& obj );
};

#include "MutantStack.tpp"
#endif
