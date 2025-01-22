/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:15:24 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/21 21:28:50 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
   private:
        std::string name;
    public:
        void announce(void);
        ~Zombie(void);
        void setName(std::string);
};

Zombie* zombieHorde(int N, std::string name);


#endif