/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:50:53 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 16:22:13 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern()
{
}

Intern::Intern(std::string const name)
{
    (void)name;
}

Intern::Intern(Intern const &copy)
{
    (void)copy;
}

Intern &Intern::operator=(Intern const &copy)
{
    (void)copy;
    return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    int form_i = -1;
    std::string forms[3] = {"shrubbery creation","robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == form)
            form_i = i;
    }
    switch (form_i)
    {
        case 0:
        {
            std::cout << "Intern creates " << form << std::endl;
            return new ShrubberyCreationForm(target);
        }
        case 1:
        {
            std::cout << "Intern creates " << form << std::endl;
            return new RobotomyRequestForm(target);
        }
        case 2:
        {
            std::cout << "Intern creates " << form << std::endl;
            return new PresidentialPardonForm(target);
        }
        default:
            throw FormNotFoundException();
    }
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}