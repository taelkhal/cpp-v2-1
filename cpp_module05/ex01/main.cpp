/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:15:34 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:10:33 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("b", 10);
        Form f("f", 10, 1);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        f.beSigned(b);
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}