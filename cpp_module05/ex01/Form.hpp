/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:09:17 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:09:04 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form
{
    private:
        std::string const name;
        bool _signed;
        int const grade_s;
        int const grade_e;
    public:
        Form();
        Form(std::string const name, int const grade_s, int const grade_e);
        Form(Form const &copy);
        Form &operator=(Form const &copy);
        ~Form();
        std::string const getName() const;
        bool getSigned() const;
        int getGrade_s() const;
        int getGrade_e() const;
        void beSigned(Bureaucrat bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif