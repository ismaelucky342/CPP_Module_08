/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:06:23 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:27:46 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main () {
	test_find_should_return_target();
	test_find_should_return_exception();
	test_find_then_src_null_should_return_exception();
}

void test_find_should_return_target() {
	int	const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	std::vector<int> src(w, w + w_size);

	int result = easyfind<std::vector<int> >(src, 275);
	assert(result == 275);
	result = easyfind<std::vector<int> >(src, 657);
	assert(result == 657);
	result = easyfind<std::vector<int> >(src, 321);
	assert(result == 321);
	std::cout << GREEN << "test_find_should_return_target: OK[✅]!" << RESET <<  std::endl;
}

void test_find_should_return_exception() {
	int	const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	std::vector<int> src(w, w + w_size);

	try {
		easyfind<std::vector<int> >(src, 10000);
	} catch (std::exception &e) {
		std::string str = RED "ERROR: Not found" RESET;
		assert(str == e.what());
	}
	std::cout << GREEN << "test_find_should_return_exception: OK[✅]!" << RESET <<  std::endl;
}
void test_find_then_src_null_should_return_exception() {
	std::vector<int> src;

	try {

		easyfind<std::vector<int> >(src, 275);
	} catch (std::exception & e) {
		std::string str = RED "ERROR: No arguments" RESET ;
		assert(str == e.what());

	}

	std::cout << GREEN << "test_find_then_src_null_should_return_target: OK[✅]!" << RESET <<  std::endl;
}

