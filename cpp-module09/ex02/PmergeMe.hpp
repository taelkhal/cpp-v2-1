/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:00:28 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/20 02:00:28 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<unsigned int> arr_v;
        std::deque<unsigned int> arr_d;
    public:
        PmergeMe();
        ~PmergeMe();
        void run_pmergeme(std::string str);
};


#endif