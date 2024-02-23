/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:24:11 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/10 18:40:51 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Span
{
    private:
    	unsigned int N;
    	std::vector<int> arr;
    public:
    	Span();
    	Span(unsigned int N);
    	Span(Span const &other);
    	Span &operator=(Span const &other);
    	~Span();
    	void addNumber(unsigned int N);
		class ErrorDuplicate: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Found Duplicated Number");
				}
		};
		class OutOfRange: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Out Of Rnage");
				}
		};
		int shortestSpan();
		int longestSpan();
		class ErrorSpan: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("No Numbers Or Found Just One Number");
				}
		};
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};


#endif