/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:15:51 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:28:12 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
    test_empty_stack();
    test_add_elements();
    test_add_elements_size();
    test_pop_element();
    test_top_stack();
    test_iterator_stack();
    test_copy_stack();
    test_build_within_type();
    test_copy_constructor();
    test_assignment_op();
    return 0;
}

void test_empty_stack() {
    MutantStack<int> mstack;
    assert(mstack.empty() && RED "test_empty_stack: KO [❌]: Stack should be empty initially.");
    assert(mstack.size() == 0 && RED "test_empty_stack: KO [❌]: Size should be 0 initially.");
    std::cout << GREEN << "test_empty_stack: OK[✅]" << RESET << std::endl;
}

void test_add_elements() {
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(15);
    assert(!mstack.empty() && RED "test_add_elements: KO [❌]: Stack should not be empty after adding an element.");
    std::cout << GREEN << "test_add_elements: OK[✅]" << RESET << std::endl;
}

void test_add_elements_size() {
    MutantStack<int> mstack;
    std::stack<int> stack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(10);
    stack.push(10);
    stack.push(20);
    stack.push(10);
    assert(!mstack.empty() && RED "test_add_elements_size: KO [❌]: Stack should not be empty after adding an element.");
    assert(mstack.size() == stack.size() && RED "test_add_elements_size: KO [❌]: Size should be 3.");
    assert(mstack.top() == stack.top() && RED "test_add_elements_size: KO [❌]: Last element should be 10.");
    std::cout << GREEN << "test_add_elements_size: OK[✅]" << RESET << std::endl;
}

void test_pop_element() {
    MutantStack<int> mstack;
    mstack.push(15);
    mstack.pop();
    assert(mstack.empty() && RED "test_pop_element: KO [❌]: Stack should be empty after deleting the element.");
    assert(mstack.size() == 0 && RED "test_pop_element: KO [❌]: Size should be 0 after deleting the element.");
    mstack.push(15);
    mstack.push(10);
    mstack.pop();
    assert(!mstack.empty() && RED "test_pop_element: KO [❌]: Stack should not be empty after adding elements.");
    assert(mstack.top() == 15 && RED "test_pop_element: KO [❌]: The top value of the stack should be 15.");
    assert(mstack.size() == 1 && RED "test_pop_element: KO [❌]: Size should be 1 after removing 1 of 2 elements.");
    std::cout << GREEN << "test_pop_element: OK[✅]" << RESET << std::endl;
}

void test_top_stack() {
    MutantStack<int> mstack;
    mstack.push(15);
    assert(!mstack.empty() && RED "test_top_stack: KO [❌]: Stack should not be empty after adding an element.");
    assert(mstack.top() == 15 && RED "test_top_stack: KO [❌]: The top value of the stack should be 15.");
    mstack.push(17);
    assert(mstack.top() == 17 && RED "test_top_stack: KO [❌]: The top value of the stack should be 17.");
    std::cout << GREEN << "test_top_stack: OK[✅]" << RESET << std::endl;
}

void test_iterator_stack() {
    MutantStack<int> mstack;
    std::list<int> lst;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::list<int>::iterator lstit = lst.begin();
    std::list<int>::iterator lstite = lst.end();
    ++it;
    --it;
    while (it != ite && lstit != lstite) {
        assert(*it == *lstit && RED "test_iterator_stack: KO [❌]: Values in stack and list should be equal.");
        ++it;
        ++lstit;
    }
    std::cout << GREEN << "test_iterator_stack: OK[✅]" << RESET << std::endl;
}

void test_copy_stack() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::stack<int> stack(mstack);
    assert(!stack.empty() && RED "test_copy_stack: KO [❌]: Stack should not be empty.");
    assert(mstack.size() == stack.size() && RED "test_copy_stack: KO [❌]: Sizes should be equal.");
    assert(mstack.top() == 17 && RED "test_copy_stack: KO [❌]: Top value should be 17.");
    std::cout << GREEN << "test_copy_stack: OK[✅]" << RESET << std::endl;
}

void test_build_within_type() {
    MutantStack<int> mstack(15);
    assert(mstack.size() == 15);
    mstack.push(5);
    assert(mstack.top() == 5);
}

void test_copy_constructor() {
    MutantStack<int> mstack;
    mstack.push(5);
    MutantStack<int> copystack(mstack);
    assert(copystack.size() == mstack.size());
    assert(copystack.top() == mstack.top());
}

void test_assignment_op() {
    MutantStack<int> mstack;
    MutantStack<int> copystack;
    mstack.push(5);
    copystack = mstack;
    assert(copystack.size() == mstack.size());
    assert(copystack.top() == mstack.top());
}