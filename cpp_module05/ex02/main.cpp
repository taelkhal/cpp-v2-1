/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:37:26 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:22:10 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 5);
        ShrubberyCreationForm form("form");
        RobotomyRequestForm form1("form");
        PresidentialPardonForm form2("form");

        bureaucrat.signForm(form);
        bureaucrat.signForm(form1);
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form);
        bureaucrat.executeForm(form1);
        bureaucrat.executeForm(form2);

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}