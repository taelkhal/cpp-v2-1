/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:02:38 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/22 16:29:58 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream data_file("data.csv");
    std::string date;
    std::string price;

    if (data_file.is_open())
    {
        std::getline(data_file, date);
        while (std::getline(data_file, date, ','))
        {
            std::getline(data_file, price);
            double nb = std::stod(price);
            data.insert(std::make_pair(date, nb));
        }
    }
    else
        throw std::runtime_error("Error: could not open file.");
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    data = other.data;
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

std::string skip_spaces(std::string str)
{
    std::string str1 = str;

    size_t pos = str1.find_first_not_of(" \t");
    if (pos != std::string::npos)
        str1.erase(0, pos);
    return (str1);
}

std::string skip_spaces_from_last(std::string str)
{
    std::string str1 = str;

    size_t pos = str1.find_last_not_of(" \t");
    if (pos != std::string::npos)
        str1.erase(pos + 1);
    return (str1);
}

bool check_pipe(std::string date)
{
    int pipe = 0;

    for (size_t i = 0; i < date.length(); i++)
    {
        if(date[i] == '|')
        {
            pipe++;
            if (pipe != 1)
                return false;
        }
    }
    if (pipe == 1)
        return true;
    return (false);
}

bool check_point(std::string price)
{
    int point = 0;
    size_t tmp = 0;

    for (size_t i = 0; i < price.length(); i++)
    {
        if (price[i] == '.')
        {
            point++;
            tmp = i;
            if (tmp == 0 || tmp == price.length() - 1 || point != 1)
                return false;       
        }
    }
    return true;
}

void BitcoinExchange::get_value(std::string key, float p)
{
    std::map<std::string, float>::iterator it;
    it = data.find(key);
    
    if (it != data.end())
    {
        float value = it->second;
        std::cout <<  key << " => " << p << " = " << value * p << std::endl;
    }
    else
    {
        it = data.lower_bound(key);
        if (it != data.begin())
        {
            --it;
            float c_value = it->second;
            std::cout << key << " => " << p << " = " << c_value * p <<  std::endl;
        }
    }
}

bool contains_only_valid_characters(std::string str)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        char ch = str[i];
        if (!(ch >= '0' && ch <= '9') && ch != '.')
            return false;
    }
    return true;
}

void BitcoinExchange::check_price(std::string date, std::string key)
{
    std::string price;

    for (size_t i = 0; i < date.size(); i++)
    {
        if(date[i] == '|' && !date[i + 1])
        {
            std::cout << "Error: invalid number." << std::endl;
            return ;
        }
    }
    price = date.substr(13, date.length());
    if (price[0] == '.')
    {
        std::cout << "Error: bad input " << date << std::endl;
        return ;
    }
    if (!contains_only_valid_characters(price))
    {
        std::cout << "Error: bad input " << date << std::endl;
        return ;
    }
    if (price.empty())
    {
        std::cout << "Error: bad input " << date << std::endl;
        return ;
    }
    for (size_t i = 0; i < price.length(); i++)
    {
        if (price[i] == ' ' || price[i] == '\t')
        {
            std::cout << "Error: invalid number." << std::endl;
            return ;
        }
    }
    if (check_point(price) == false)
        std::cout << "Error: invalid number." << std::endl;
    float p = atof(price.c_str());
    if (p < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }
    if (p > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }
    get_value(key, p);
}

void BitcoinExchange::check_date(std::string date)
{
    std::string year, month, day;
    int y, m, d;

    int dashCount = 0;
    for (size_t j = 0; j < date.size(); j++)
    {
        size_t pipe = date.find('|');
        if (j != pipe)
        {
            if (date[j] == '-')
                dashCount++;
        }
        else
            break;
    }
    if (dashCount != 2 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }
    year = date.substr(0, 4);
    month = date.substr(5, 7);
    day = date.substr(8, 10);
    y = stoi(year);
    m = stoi(month);
    d = stoi(day);

    if ((y == 2009 && m == 1 && d == 1) || (y == 2022 && m > 4 && d > 1))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return ;
    }
    if (y < 2009 || y > 2022 || m < 1 || m > 12 || d < 1 || d > 31)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return ;
    }
    else if (m == 1 || m == 3 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (d < 1 || d > 31)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            return ;
        }
    }
    else
    {
        if (m == 2)
        {
            if (d < 1 || d > 29)
            {
                std::cout << "Error: bad input => " << date << std::endl;
                return ;
            }
        }
        if (d < 1 || d > 30)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            return ;
        }
    }
    if (check_pipe(date) == false)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return ;
    }
    std::string key = date.substr(0, 10);
    check_price(date, key);
}

void BitcoinExchange::parse_file(std::string file)
{
    std::ifstream input_f(file);
    std::string line;
    int check = 0;

    if (input_f.is_open())
    {
        std::string date_i;
        std::getline(input_f, date_i);
        if (date_i.empty())
        {
            std::cout << "Error: bad input" << std::endl;
            return ;
        }
        date_i = skip_spaces(date_i);
        date_i = skip_spaces_from_last(date_i);
        if (date_i != "date | value")
            std::cout << "Error: bad input" << std::endl;
        else
            check = 1;
        while (std::getline(input_f, date_i))
        {
            // if (date_i.empty())
            //     std::cout << "Error: bad input(empty line)" << std::endl;
            date_i = skip_spaces(date_i);
            date_i = skip_spaces_from_last(date_i);
            check_date(date_i);
        }
    }
    input_f.close();
}