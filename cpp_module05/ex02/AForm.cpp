/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:10:57 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:56:36 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():name("default"),grade_s(150), grade_e(150)
{
    _signed = false;
    if (grade_s > 150 || grade_e > 150)
        throw AForm::GradeTooLowException();
    if (grade_s < 1 || grade_e < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(std::string const name ,int const grade_s, int const grade_e):name(name), grade_s(grade_s), grade_e(grade_e)
{
    _signed = false;
    if (grade_s > 150 || grade_e > 150)
        throw AForm::GradeTooLowException();
    if (grade_s < 1 || grade_e < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const &copy):name(copy.name), _signed(copy._signed) ,grade_s(copy.grade_s), grade_e(copy.grade_e)
{
}

AForm &AForm::operator=(AForm const &copy) 
{
    _signed = copy._signed;
    return *this;
}

AForm::~AForm()
{
}

std::string const AForm::getName() const
{
    return (name);
}

bool AForm::getSigned() const
{
    return (_signed);
}

int AForm::getGrade_s() const
{
    return (grade_s);
}

int AForm::getGrade_e() const
{
    return (grade_e);
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() > grade_s)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("AForm not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << "name is : " << form.getName() << std::endl;
    out << "sign is : " << form.getSigned() << std::endl;
    out << "grade to sign is : " << form.getGrade_s() << std::endl;
    out << "grade to execute is : " << form.getGrade_e() << std::endl;
    return (out);
}