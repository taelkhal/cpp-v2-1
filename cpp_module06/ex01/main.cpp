/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:11:14 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/29 18:41:31 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data;
    ptr->n = 19;
    std::cout << ptr->n << std::endl;
    uintptr_t p = Serializer::serialize(ptr);
    std::cout << p << std::endl;
    // std::cout << ptr << std::endl;
    Data *ptr1 = Serializer::deserialize(p);
    std::cout << ptr1 << std::endl;
}