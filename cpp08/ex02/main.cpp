/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:56:24 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/26 12:46:17 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    mstack.push(42);

    std::cout << "\nlist\n";
    std::list<int> listtest;
    listtest.push_back(5);
    listtest.push_back(17);
    std::cout << listtest.back() << std::endl;
    listtest.pop_back();
    std::cout << listtest.size() << std::endl;
    listtest.push_back(3);
    listtest.push_back(5);
    listtest.push_back(737);
    //[...]
    listtest.push_back(0);
    std::list<int>::iterator it2 = listtest.begin();
    std::list<int>::iterator ite2 = listtest.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    listtest.push_back(42);


    std::cout << "\n\n\n";
    std::stack<int> s(mstack);
    MutantStack<int> test(mstack);


    std::cout << "\n\n";
    std::cout << s.top() << std::endl;
    std::cout << test.top() << std::endl;


    std::cout << "\n\n\n";
    const std::list<int> constList(listtest);
    const MutantStack<int> constMutant(mstack);


    MutantStack<int>::const_iterator constit = constMutant.begin();
    MutantStack<int>::const_iterator constite = constMutant.end();
    while (constit != constite)
    {
        std::cout << *constit << std::endl;
        ++constit;
    }
    std::cout << "\n";

    std::list<int>::const_iterator constit2 = constList.begin();
    std::list<int>::const_iterator constite2 = constList.end();
    while (constit2 != constite2)
    {
        std::cout << *constit2 << std::endl;
        ++constit2;
    }

    return 0;
}