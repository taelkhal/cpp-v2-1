/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:14:37 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:03:18 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif