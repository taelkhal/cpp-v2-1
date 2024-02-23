/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:02:36 by taelkhal          #+#    #+#             */
/*   Updated: 2024/02/10 14:03:26 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template <class T>

class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array(): array(new T[0]), _size(0){}
        Array(unsigned int n)
        {
            array = new T[n];
            _size = n;
        }
        Array(Array const &other)
        {
            _size = other._size;
            array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                array[i] = other.array[i];
        }
        Array &operator=(Array const &other)
        {
            if (this != &other)
            {
                if (array)
                    delete[] array;
                _size = other._size;
                array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    array[i] = other.array[i];
            }
            return (*this);
        }
        ~Array()
        {
            if (array)
                delete[] array;
        }
        unsigned int size(){return _size;}
        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw OutOfRange();
            return array[index];
        }
        const T &operator[](unsigned int index) const
        {
            if (index >= _size)
                throw OutOfRange();
            return array[index];
        }
        class OutOfRange: public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Out of Range");
                }
        };
};

#endif