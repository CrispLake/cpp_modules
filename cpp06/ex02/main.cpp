/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:59:27 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 15:02:21 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base    gen;
    Base*   p;
    for (int i = 0; i < 10; i++)
    {
        p = gen.generate();
        gen.identify(p);
        gen.identify(*p);
        delete p;
    }
    return 0;
}
