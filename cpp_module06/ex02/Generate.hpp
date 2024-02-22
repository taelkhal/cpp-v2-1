/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:00:08 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/30 17:39:44 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_HPP
#define GENERATE_HPP


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

class Generate : public Base
{
    public:
        Generate();
        Generate(Generate const &g);
        Generate &operator=(Generate const &g);
        ~Generate();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif