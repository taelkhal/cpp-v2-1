/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:08:41 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/12 18:24:53 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> arr(5);

    arr.push_back(-4);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(0);
    easyfind(arr, 15);
    easyfind(arr, 99);
    easyfind(arr, 3);
    easyfind(arr, -4);
}