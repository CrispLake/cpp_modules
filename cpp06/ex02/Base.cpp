/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:50:25 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 15:22:09 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{}

Base*   Base::generate()
{
    int random;
    static bool seeded = false;

    if (!seeded)
        std::srand(std::time(NULL));
    seeded = true;
    random = std::rand();
    if (random % 3 == 0)
    {
        std::cout << "Creating A\n";
        return (new A());
    }
    else if (random % 3 == 1)
    {
        std::cout << "Creating B\n";
        return (new B());
    }
    else
    {
        std::cout << "Creating C\n";
        return (new C());
    }
}

void    Base::identify(Base* p)
{
    try
    {
        A a = dynamic_cast<A&>(*p);
        std::cout << "It was type A\n";
    }
    catch(...)
    {
        try
        {
            B b = dynamic_cast<B&>(*p);
            std::cout << "It was type B\n";
        }
        catch(...)
        {
            try
            {
                C c = dynamic_cast<C&>(*p);
                std::cout << "It was type C\n";
            }
            catch(...)
            {
                std::cout << "It was not type A, B or C\n";
            }
            
        }
    }
}

void    Base::identify(Base& p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "It was type A\n";
    }
    catch(...)
    {
        try
        {
            B b = dynamic_cast<B&>(p);
            std::cout << "It was type B\n";
        }
        catch(...)
        {
            try
            {
                C c = dynamic_cast<C&>(p);
                std::cout << "It was type C\n";
            }
            catch(...)
            {
                std::cout << "It was not type A, B or C\n";
            }
            
        }
    }
}