/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:54:34 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:40:58 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string const name, int grade): name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): name(copy.name), grade(copy.grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
    grade = copy.grade;
    return (*this);
}


std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Grade too low");
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::incrementGrade()
{
    if (grade > 1)
       grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    if (grade < 150)
        grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (out);
}

void Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);
    if (form.getSigned() == true)
        std::cout << name << " signed " << form.getName() << std::endl;
    else
        std::cout << name << " couldn’t sign " << form.getSigned() << " because " << "garde too low" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " can't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
