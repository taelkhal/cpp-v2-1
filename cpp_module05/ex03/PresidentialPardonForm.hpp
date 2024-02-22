/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:29:45 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/29 14:51:24 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP



#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
        void execute(Bureaucrat const & executor) const;
        ~PresidentialPardonForm();
};


#endif