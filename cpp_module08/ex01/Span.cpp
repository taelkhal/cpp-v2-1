/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:36:39 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/11 17:02:22 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    N = 0;
    arr.resize(0);
}

Span::Span(unsigned int N)
{
    this->N = N;
    arr.reserve(N);
}

Span::Span(Span const &other)
{
    *this = other;
}

Span &Span::operator=(Span const &other)
{
    this->N = other.N;
    this->arr = other.arr;
    return *this;
}

Span::~Span()
{
}


void Span::addNumber(unsigned int N)
{
    // std::cout << arr.size() << std::endl;
    // std::cout << N << std::endl;
    if (arr.size() < this->N)
    {
        if (std::find(arr.begin(), arr.end(), N) != arr.end())
            throw ErrorDuplicate();
        else
            arr.push_back(N);
    }
    else
    {
        throw OutOfRange();
    }
}

int Span::shortestSpan()
{
    std::vector<int>::iterator shortestspan;
    
    if (arr.empty() || arr.size() == 1)
        throw ErrorSpan();
    shortestspan = std::min_element(arr.begin(), arr.end());
    return *shortestspan;
}

int Span::longestSpan()
{
    std::vector<int>::iterator longestspan;
    
    if (arr.empty() || arr.size() == 1)
        throw ErrorSpan();
    longestspan = std::max_element(arr.begin(), arr.end());
    return *longestspan;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    int range = std::distance(begin, end);
    std::vector<int>::iterator it;

    if (range + arr.size() > N)
        throw OutOfRange();
    for(it = begin; it != end; it++)
        arr.push_back(*it);
}