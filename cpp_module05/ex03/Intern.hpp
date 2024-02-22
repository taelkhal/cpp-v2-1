/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 02:31:36 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/27 15:40:22 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP


#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(std::string const name);
        Intern(Intern const &copy);
        Intern &operator=(Intern const &copy);
        ~Intern();
        AForm *makeForm(std::string form, std::string target);
        class FormNotFoundException: public std::exception
        {
            public:
                const char *what() const throw();
        };
};


#endif