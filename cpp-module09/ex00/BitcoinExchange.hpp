/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:31:28 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/16 18:42:23 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

class BitcoinExchange
{
    private:
        std::string date;
        std::string pipe;
        std::map<std::string, float> data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void parse_file(std::string file);
        void get_value(std::string date, float p);
        void check_date(std::string date);
        void check_price(std::string date, std::string x);
        
        
        
};

#endif