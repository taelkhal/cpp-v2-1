/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:01:04 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:44:45 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("default", 72, 45)
{
    target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target): AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm("RobotomyRequestForm", 72, 45)
{
    target = copy.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    target = copy.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == true)
    {
        if (executor.getGrade() <= this->getGrade_e())
        {
            srand(time(NULL));
            if (rand() % 2 == 0)
            {
                std::cout << executor.getName() << " has been robotomized successfully 50% of the time" << std::endl;
                return ;
            }
            else
            {
                std::cout << executor.getName() << " has been robotomized failure" << std::endl;
                return ;
            }
        }
        throw AForm::GradeTooLowException();
    }
    else
        throw AForm::FormNotSignedException();
}
