/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:59:54 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/11 13:43:51 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    try
    {
        Array <int> a(5);
        
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i;
        
        std::cout << "a[1] = " << a[0] << std::endl;
        std::cout << "a[1] = " << a[1] << std::endl;
        std::cout << "a[2] = " << a[2] << std::endl;
        std::cout << "a[3] = " << a[3] << std::endl;
        std::cout << "a[4] = " << a[4] << std::endl;
        std::cout << "size = " << a.size() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
