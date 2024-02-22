/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:26:40 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:54:05 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("default"), _signed(false),grade_s(150), grade_e(150)
{
    if (grade_s > 150 || grade_e > 150)
        throw Form::GradeTooLowException();
    if (grade_s < 1 || grade_e < 1)
        throw Form::GradeTooHighException();
}

Form::Form(std::string const name, int const grade_s, int const grade_e):name(name), _signed(false),grade_s(grade_s), grade_e(grade_e)
{
    if (grade_s > 150 || grade_e > 150)
        throw Form::GradeTooLowException();
    if (grade_s < 1 || grade_e < 1)
        throw Form::GradeTooHighException();
}

Form::Form(Form const &copy):name(copy.name), _signed(copy._signed), grade_s(copy.grade_s), grade_e(copy.grade_e)
{
}

Form &Form::operator=(Form const &copy)
{
    _signed = copy._signed;
    return (*this);
}

Form::~Form()
{
}

std::string const Form::getName() const
{
    return (name);
}

bool Form::getSigned() const
{
    return (_signed);
}

int Form::getGrade_s() const
{
    return (grade_s);
}

int Form::getGrade_e() const
{
    return (grade_e);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() > grade_s)
        throw Form::GradeTooLowException();
    _signed = true;
}


const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Garde too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "name is : " << form.getName() << std::endl;
    out << "sign is : " << form.getSigned() << std::endl;
    out << "grade to sign is : " << form.getGrade_s() << std::endl;
    out << "grade to execute is : " << form.getGrade_e() << std::endl;
    return (out);
}
