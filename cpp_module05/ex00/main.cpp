/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:16:32 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 16:16:06 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("b", 151);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        {
        Bureaucrat b2("b2", 3);
        std::cout << b2;
        b2.incrementGrade();
        std::cout << b2;
        b2.incrementGrade();
        std::cout << b2;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
}