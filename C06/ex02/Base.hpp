/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:14:14 by melisportak       #+#    #+#             */
/*   Updated: 2025/07/19 12:14:15 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base();
};
class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif 