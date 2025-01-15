/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:25:01 by mrios-he          #+#    #+#             */
/*   Updated: 2024/12/30 10:30:38 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# include <iostream>
# include <cstdlib>
# include <ctime>
# define MAX_VAL 750

template<typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		Array() : _array(NULL), _size(0) {}
		Array(unsigned int n) : _size(n)
		{
			_array = new T[n]();
		}
		Array(const Array& other) : _size(other._size)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		~Array()
		{
			if (_array)
				delete[] _array;
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				T* temp = new T[other._size];
				for (unsigned int i = 0; i < other._size; i++)
					temp[i] = other._array[i];
				
				if (_array)
					delete[] _array;
				_array = temp;
				_size = other._size;
			}
			return *this;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return _array[index];
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::exception();
			return _array[index];
		}

		unsigned int size() const
		{
			return _size;
		}
};

#endif