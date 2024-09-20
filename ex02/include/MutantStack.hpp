/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#             */
/*   Updated: 2024/09/20 14:23:03 by csakamot         ###   ########.fr       */
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

  typedef typename std::stack<T>::container_type::iterator                iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
  typedef typename std::stack<T>::container_type::const_iterator          const_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

  iterator  begin( void );
  iterator  end( void );
  reverse_iterator  rbegin( void );
  reverse_iterator  rend( void );
  const_iterator  begin( void ) const;
  const_iterator  end( void ) const;
  const_reverse_iterator  rbegin( void ) const;
  const_reverse_iterator  rend( void ) const;

  MutantStack& operator=( const MutantStack& obj );
};

#include "MutantStack.tpp"
#endif
