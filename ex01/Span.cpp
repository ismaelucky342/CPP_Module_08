/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:32:20 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:31:23 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():
_store(0),
_n_max(0),
_len_stored(0),
_val_min(INT_MAX),
_val_max(INT_MIN) {
}
 
Span::~Span() {
}

Span::Span(unsigned int n): 
_store(0),
_n_max(n),
_len_stored(0),
_val_min(INT_MAX),
_val_max(INT_MIN) {
}

Span::Span(Span const & src): 
_store(src._store),
_n_max(src._n_max),
_len_stored(src._len_stored),
_val_min(src.getValMin()),
_val_max(src.getValMax()) {
}

Span &Span::operator=(Span const & src) {
	if ( this == &src)
		return *this;
	this->_store = src._store;
	this->_n_max = src._n_max;
	this->_len_stored = src._len_stored;
	this->_val_min = src._val_min;
	this->_val_max = src._val_max;
	return *this;
}

int Span::getValMin() const{
	return _val_min;
}

int Span::getValMax() const{
	return _val_max;
}


void Span::addNumber(int num) {
	if (_len_stored >= _n_max)
		throw std::invalid_argument(RED "ERROR: Invalid Arg" RESET);
	_store.push_back(num);
	_len_stored = _store.size();
	if (num < _val_min)
		_val_min = num;
	if (num > _val_max)
		_val_max = num;
}


int &Span::operator[](unsigned int i) {
	if (i < _len_stored)
		return this->_store[i];
	else
		throw std::out_of_range(RED "ERROR: Index is out of bounds" RESET);
}
int Span::shortestSpan() {
	if (_len_stored == 0 || _len_stored == 1)
		throw std::invalid_argument(RED "ERROR: There are not enough numbers" RESET);
	std::vector<int> sorted_store = _store;
	std::sort(sorted_store.begin(), sorted_store.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted_store.size() - 1; ++i) {
		int diff = sorted_store[i + 1] - sorted_store[i];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() {
	if (_len_stored == 0 || _len_stored == 1)
		throw std::invalid_argument(RED "ERROR: There are not enough numbers" RESET);

	return _val_max - _val_min;
}

std::vector<int>::iterator Span::begin() {
	return _store.begin();
}

std::vector<int>::iterator Span::end() {
	return _store.end();

}
