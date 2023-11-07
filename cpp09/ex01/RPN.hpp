/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:55 by emajuri           #+#    #+#             */
/*   Updated: 2023/11/07 16:32:14 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>

class RPN
{
    public:
        RPN();
        RPN(RPN const& ref);
        RPN&    operator=(RPN const& ref);
        ~RPN();

        void    calculate(std::string calc);
    private:
        std::stack<int>  numbers;

        bool    validate(std::string calc) const;
        int     getTop();
};