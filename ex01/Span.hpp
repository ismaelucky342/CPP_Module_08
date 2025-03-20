/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:27:45 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:31:31 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

/*================================INCLUDES=================================*/

#include <stdexcept>
#include <vector>
#include <stdlib.h>
#include <memory>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <climits>
#define MAX_VAL 20000

/*================================COLORS=====================================*/

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define GRAY "\033[90m"

# define B_BLACK "\033[40m"
# define B_RED "\033[41m"
# define B_GREEN "\033[42m"
# define B_YELLOW "\033[43m"
# define B_BLUE "\033[44m"
# define B_MAGENTA "\033[45m"
# define B_CYAN "\033[46m"
# define B_WHITE "\033[47m"
# define B_GRAY "\033[100m"

/*================================CLASS=====================================*/

class Span {
	private:
		std::vector<int>	_store;
		unsigned int	_n_max;
		unsigned int	_len_stored;
		int				_val_min;
		int				_val_max;
	public:
		Span();
		~Span();
		Span(unsigned int);
		Span(Span const &);
		Span &operator=(Span const &);
		void addNumber(int);
		int shortestSpan();
		int longestSpan();
		int &operator[](unsigned int i);
		int	getValMin() const;
		int	getValMax() const;
		std::vector<int>::iterator begin();
		std::vector<int>::iterator end();
		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end) {
			for (InputIterator it = begin; it != end; ++it) {
				if (_len_stored >= _n_max)
					throw std::overflow_error("ERROR: Span is full");
				_store.push_back(*it);
				_len_stored++;
				if (_len_stored == 1) {
					_val_min = *it;
					_val_max = *it;
				} else {
					_val_min = std::min(_val_min, *it);
					_val_max = std::max(_val_max, *it);
				}
			}
		}
};

/*================================FUNCTIONS=================================*/


#endif