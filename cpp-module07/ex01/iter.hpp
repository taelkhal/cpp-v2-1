/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:05:45 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/08 18:18:20 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void ft_print(T &a)
{
    std::cout << a << std::endl;
}

template <typename T, typename T2>

void iter(T *array, size_t length,  void (*f)(T2 &))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

#endif