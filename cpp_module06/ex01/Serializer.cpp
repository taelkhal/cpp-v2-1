/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:59:59 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/29 18:20:16 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t n;

    n = reinterpret_cast<uintptr_t>(ptr);
    return n;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr;

    ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}