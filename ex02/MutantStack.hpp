/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:40:06 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:30:39 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

/*================================INCLUDES=================================*/

#include <deque>
#include <stack>
#include <iostream>
#include <string>
#include <list>
#include <cassert>

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

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(T src) : std::stack<T>(std::deque<T>(src)) {}
		~MutantStack() {}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		MutantStack &operator=(MutantStack const &other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator begin() const {
			return this->c.begin();
		}

		const_iterator end() const {
			return this->c.end();
		}
};

/*================================FUNCTIONS=================================*/

void test_empty_stack();
void test_add_elements();
void test_add_elements_size();
void test_pop_element();
void test_top_stack();
void test_iterator_stack();
void test_copy_stack();
void test_build_within_type();
void test_copy_constructor();
void test_assignment_op();

#endif