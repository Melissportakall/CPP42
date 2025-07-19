/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:13:14 by melisportak       #+#    #+#             */
/*   Updated: 2025/07/19 12:13:16 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : id(0), name("") {}

Data::Data(const Data& other) : id(other.id), name(other.name) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
    }
    return *this;
}

Data::~Data() {} 