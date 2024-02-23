/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:25:20 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/20 15:10:38 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other)
{
    rpn = other.rpn;
}

RPN &RPN::operator=(const RPN &other)
{
    rpn = other.rpn;
    return *this;
}

RPN::~RPN(){}

void RPN::run_rpn(std::string str)
{
    long nb1, nb2, nb3;
    std::string n;
    std::string s = str;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        if (str[i] == '(' || str[s.size() - 1] == ')')
        {
            std::cout << "Error" << std::endl;
            exit (0);
        }
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == '*' || s[i] == '-' || s[i] == '+' || s[i] == '/')
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                n = "";
                n += s[i];
                nb1 = strtol(n.c_str(), NULL, 10);
                rpn.push(nb1);
            }
            if (s[i] == '*')
            {
                if(rpn.size() > 1)
                {
                    nb2 = rpn.top();
                    rpn.pop();
                    nb3 = rpn.top();
                    rpn.pop();
                    rpn.push(nb3 * nb2);
                }
                else
                {
                    std::cout << "Error" << std::endl;
                    exit (0);
                }
            }
            if (s[i] == '-')
            {
                if (rpn.size() > 1)
                {
                    nb2 = rpn.top();
                    rpn.pop();
                    nb3 = rpn.top();
                    rpn.pop();
                    rpn.push(nb3 - nb2);
                }
                else
                {
                    while (!rpn.empty())
                    {
                        std::cout << rpn.top() << std::endl;
                        rpn.pop();
                    }
                    std::cout << "Error" << std::endl;
                    exit (0);
                }
            }
            if (s[i] == '+')
            {
                if (rpn.size() > 1)
                {
                    nb2 = rpn.top();
                    rpn.pop();
                    nb3 = rpn.top();
                    rpn.pop();
                    rpn.push(nb3 + nb2);
                }
                else
                {
                    std::cout << "Error" << std::endl;
                    exit (0);
                }
            }
            if(s[i] == '/')
            {
                if (rpn.size() > 1)
                {
                    nb2 = rpn.top();
                    rpn.pop();
                    nb3 = rpn.top();
                    if (nb2 == 0)
                    {
                        std::cout << "Error: divide by zero" << std::endl;
                        exit (0);
                    }
                    rpn.pop();
                    rpn.push(nb3 / nb2);
                }
                else
                {
                    std::cout << "Error" << std::endl;
                    exit (0);
                }
            }
        }
        else
        {
            std::cout << "Error: invalid number" << std::endl;
            exit (0);
        }
    }
    if (rpn.size() != 1)
    {
        std::cout << "Error" << std::endl;
        exit (0);
    }
    std::cout << rpn.top() << std::endl;
}