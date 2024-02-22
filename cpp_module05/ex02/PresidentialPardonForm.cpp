/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:31:09 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:58:28 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("default", 25, 5)
{
    target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target):AForm("PresidentialPardonForm", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):AForm("PresidentialPardonForm", 25, 5)
{
    target = copy.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
    target = copy.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == true)
    {
        if (executor.getGrade() <= this->getGrade_e())
        {
            std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
            return ;
        }
        else
        {
            std::cout << executor.getName() << " can't execute" << std::endl;
            throw AForm::GradeTooLowException();
        }
    }
    else
        throw AForm::FormNotSignedException();
}
