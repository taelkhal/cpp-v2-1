/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:03:24 by taelkhal          #+#    #+#             */
/*   Updated: 2024/01/30 17:40:46 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Generate.hpp"

Generate::Generate() {}

Generate::Generate(Generate const &g)
{
    (void)g;
}

Generate &Generate::operator=(Generate const &g)
{
    (void)g;
    return (*this);
}

Generate::~Generate() {}

Base *generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else if (random == 2)
        return new C();
    else
        return NULL;
}

void identify(Base* p)
{
    if (p == dynamic_cast<A*>(p))
        std::cout << "Type is A" << std::endl;
    else if (p == dynamic_cast<B*>(p))
        std::cout << "Type is B" << std::endl;
    else if (p == dynamic_cast<C*>(p))
        std::cout << "Type is C" << std::endl;
    else
        std::cout << "Type not found" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type is A" << std::endl;
    }
    catch(std::bad_cast)
    { }
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type is B" << std::endl;
    }
    catch(std::bad_cast)
    { }
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type is B" << std::endl;
    }
    catch(std::bad_cast)
    { }
}