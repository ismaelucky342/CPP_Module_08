#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"
#include <stdexcept>
#include <algorithm>

template <typename T>
int easyfind(T &container, int target) {

	if (container.size() < 1)
		throw std::invalid_argument("\033[31mERROR No arguments\033[0m");

	typename T::iterator result = std::find(container.begin(), container.end(), target);

	if (result != container.end())
		return *result;
	else
		throw std::invalid_argument("\033[31mERROR Not found\033[0m");
}


#endif