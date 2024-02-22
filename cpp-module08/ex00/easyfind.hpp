/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:02:32 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/12 18:18:35 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>

void easyfind(T &arr, int nb)
{
    typename T::iterator i;

    i = std::find(arr.begin(), arr.end(), nb);
    if (i != arr.end())
    {
        std::cout << nb << " found"<< std::endl;
        return ;
    }
    std::cout << nb << " not found" << std::endl;
}

#endif