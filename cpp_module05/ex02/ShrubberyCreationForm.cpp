/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:26:34 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:21:01 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137)
{
    target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm("ShrubberyCreationForm", 145, 137)
{
    target = copy.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
    target = copy.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == true)
    {
        if (executor.getGrade() <= this->getGrade_e())
        {
            std::ofstream file(target + "_shrubbery");
            if (!file.is_open())
            {
                std::cout << "Error: can't open this file" << std::endl;
                return ;
            }
            file << "      A" << std::endl;
            file << "     @@@" << std::endl;
            file << "    @@@@@" << std::endl;
            file << "   @@@@@@@" << std::endl;
            file << " @@@@@@@@@@@" << std::endl;
            file << "@@@@@@@@@@@@@" << std::endl;
            file << "     AA       " << std::endl;
            file << "    @@@@" << std::endl;
            file << "   @@@@@@" << std::endl;
            file << "  @@@@@@@@" << std::endl;
            file << " @@@@@@@@@@@" << std::endl;
            file << "@@@@@@@@@@@@@" << std::endl;
            file << "     ll" << std::endl;
            file << "     ll" << std::endl;
            file << "     ll" << std::endl;
            file << "     ll" << std::endl;
            file << "     ll" << std::endl;
            file.close();
        }
        else
            throw AForm::GradeTooLowException();
    }
    else
        throw AForm::FormNotSignedException();
}
