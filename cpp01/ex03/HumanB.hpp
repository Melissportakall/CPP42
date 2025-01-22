/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:03 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/21 14:21:29 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(std::string);
        ~HumanB(void);
        void setWeapon(Weapon&);
        void attack(void);
};

#endif