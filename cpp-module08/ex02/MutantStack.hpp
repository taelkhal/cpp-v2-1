/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:17:09 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/12 18:53:15 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){
         std::stack<T>();
        }
        MutantStack(MutantStack const &other)
        {
            this->c = other.c;
        }
        MutantStack &operator=(MutantStack const &other)
        {
            this->c = other.c;
            return *this;
        }
        ~MutantStack(){}
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void)
        {
            return this->c.begin();
        }
        iterator end(void)
        {
            return this->c.end();
        }
};
#endif