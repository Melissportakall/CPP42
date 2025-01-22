/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:19:15 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/22 20:29:00 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon& weapon;
    public:
        HumanA(std::string, Weapon&);
        ~HumanA(void);
        void attack(void);
};

#endif