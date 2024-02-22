/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:27 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/29 14:51:18 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>


class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat &operator=(Bureaucrat const &copy);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif