/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:12:11 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/20 02:12:11 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int main(int ac, char **av)
// {
//     if (ac < 1)
//     {
//         std::cout << "Error" << std::endl;
//         exit (0);
//     }
//     PmergeMe a;

//     std::string s = 
//     for (int i = 0;i < av)
//         a.run_pmergeme(av[i])

// }

void merge_v(std::vector<int> &arr, std::vector<std::pair<int, int> > &pairs,int start)
{
    // std::vector<int> arr1 = arr;
    // std::vector<std::pair<int, int>> pairs;
    std::vector<int>::iterator it = arr.begin() + start;
    // std::vector<std::pair<int, int>>::iterator it_p;

    if (it == arr.end())
        return ;
    pairs.push_back(std::make_pair(arr[start], arr[start + 1]));
    // it_p = pairs.begin();
    std::vector<std::pair<int, int> >::iterator it_p = pairs.begin() + (pairs.size() - 1);
    // std::cout << it_p->first << it_p->second << std::endl;
    if (it_p->first > it_p->second)
        std::swap(it_p->first, it_p->second);
    // std::cout << it_p->first << it_p->second << std::endl;

    // if (arr.size() ==  1)
    // 
    // std::cout << pairs.back().first << pairs.back().second << std::endl;
    start += 2;
    merge_v(arr, pairs, start);
}

void merge_q(std::deque<int> &arr, std::deque<std::pair<int, int> > &pairs,int start)
{
    // std::vector<int> arr1 = arr;
    // std::vector<std::pair<int, int>> pairs;
    std::deque<int>::iterator it = arr.begin() + start;
    // std::vector<std::pair<int, int>>::iterator it_p;

    if (it == arr.end())
        return ;
    pairs.push_back(std::make_pair(arr[start], arr[start + 1]));
    // it_p = pairs.begin();
    std::deque<std::pair<int, int> >::iterator it_p = pairs.begin() + (pairs.size() - 1);
    // std::cout << it_p->first << it_p->second << std::endl;
    if (it_p->first > it_p->second)
        std::swap(it_p->first, it_p->second);
    // std::cout << it_p->first << it_p->second << std::endl;

    // if (arr.size() ==  1)
    // 
    // std::cout << pairs.back().first << pairs.back().second << std::endl;
    start += 2;
    merge_q(arr, pairs, start);
}

void check_input(std::string str)
{
    std::string s = "0 1 2 3 4 5 6 7 8 9";
    for (size_t i = 0; i < str.size(); i++)
    {
        size_t pos = s.find(str[i]);
        if (pos == std::string::npos)
        {
            std::cout << "Error" << std::endl;
            exit (0);
        }
    }

}
int main(int ac, char **av)
{
    std::vector<int> arr_v, largest_v, smallest_v;
    std::deque<int> arr_d, largest_d, smallest_d;
    std::vector<std::pair<int, int> > pairs_v;
    std::deque<std::pair<int, int> > pairs_d;



    int nb;

    for(int i = 1; i < ac; i++)
    {
        // std::cout << av[i] << std::endl;
        std::string str = av[i];
        for(size_t j = 0; str[j]; j++)
        {
            check_input(str);
            // if (str[j] == '-' && str[j + 1] == '-')
            // {
            //     std::cout << "Error: invalid number" << std::endl;
            //     exit (1);
            // }
            // if (str[j] == '-')
            //     break;
            // if (!std::isdigit(str[j]))
            // {
            //     std::cout << "Error: invalid number" << std::endl;
            //     exit (1);
            // }
        }
        // nb = stoi(str);
        nb = atoi(av[i]);
        if (nb < 0)
        {
            std::cout << "Error: negative number" << std::endl;
            exit (1);
        }

        // std::cout << nb << std::endl;
        arr_v.push_back(nb);
        arr_d.push_back(nb);
        // std::cout << arr_v[i - 1] << std::endl;
        // std::cout << arr_v[i - 1] << std::endl;
    }
    std::cout << "Before: ";
    for (size_t j = 0; j < arr_v.size(); j++)
        std::cout << arr_v[j] << " ";
    std::cout << std::endl;
    int last_v = 0;
    int check = 0;
    if (arr_v.size() % 2 != 0)
    {
        last_v = arr_v[arr_v.size() - 1];
        arr_v.pop_back();
        check = 1;
    }
    int last_d = 0;
    int check_d = 0;
    if (arr_d.size() % 2 != 0)
    {
        last_d = arr_d[arr_d.size() - 1];
        arr_d.pop_back();
        check_d = 1;
    }
    clock_t start_v = clock();
    // std::cout << start << std::endl;
    merge_v(arr_v, pairs_v, 0);
    std::vector<std::pair<int, int> >::iterator it_p;
    for (it_p = pairs_v.begin(); it_p != pairs_v.end(); it_p++)
    {
        smallest_v.push_back(it_p->first);
        largest_v.push_back(it_p->second);
    }
    std::vector<int>::iterator it_l;
    std::sort(largest_v.begin(), largest_v.end());
    for (size_t i = 0; i < smallest_v.size(); i++)
    {
        it_l = std::lower_bound(largest_v.begin(), largest_v.end(), smallest_v[i]);
        largest_v.insert(it_l, smallest_v[i]);
    }
    if (check == 1)
    {
        it_l = std::lower_bound(largest_v.begin(), largest_v.end(), last_v);
        largest_v.insert(it_l, last_v);
    }
    clock_t end_v = clock();
    double time_v = (end_v - start_v) / (CLOCKS_PER_SEC / 100000.0);
    arr_v.erase(arr_v.begin(), arr_v.end());
    for (size_t i = 0;i < largest_v.size(); i++)
        arr_v.push_back(largest_v[i]);
    // for (size_t j = 0; j < arr_v.size(); j++)
    // {
    //     std::cout << arr_v[j] << std::endl;
    // }
    ///////////////////////////deque/////////////////////
    clock_t start_d = clock();
    merge_q(arr_d, pairs_d, 0);
    std::deque<std::pair<int, int> >::iterator its_d;
    for (its_d = pairs_d.begin(); its_d != pairs_d.end(); its_d++)
    {
        smallest_d.push_back(its_d->first);
        largest_d.push_back(its_d->second);
    }
    std::deque<int>::iterator itl_d;
    std::sort(largest_d.begin(), largest_d.end());
    for (size_t i = 0; i < smallest_d.size(); i++)
    {
        itl_d = std::lower_bound(largest_d.begin(), largest_d.end(), smallest_d[i]);
        largest_d.insert(itl_d, smallest_d[i]);
    }
    if (check_d == 1)
    {
        itl_d = std::lower_bound(largest_d.begin(), largest_d.end(), last_d);
        largest_d.insert(itl_d, last_d);
    }
    clock_t end_d = clock();
    double time_d = (end_d - start_d) / (CLOCKS_PER_SEC / 100000.0);
    arr_d.erase(arr_d.begin(), arr_d.end());
    for (size_t i = 0;i < largest_d.size(); i++)
        arr_d.push_back(largest_d[i]);
    std::cout << "After: ";
    for (size_t j = 0; j < arr_v.size(); j++)
        std::cout << arr_v[j] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << arr_v.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_v << " us" <<std::endl;
    std::cout << "Time to process a range of " << arr_d.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << time_d << " us" <<std::endl;
}
