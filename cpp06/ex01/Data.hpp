/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:24:18 by emajuri           #+#    #+#             */
/*   Updated: 2023/10/13 13:36:15 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
    public:
        int const   x;
        int const   y;

        Data();
        Data(Data const& ref);
        ~Data();

    private:

        Data&  operator=(Data const& ref);
};

#endif