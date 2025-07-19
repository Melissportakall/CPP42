/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:13:23 by melisportak       #+#    #+#             */
/*   Updated: 2025/07/19 12:13:24 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.id = 42;
    data.name = "forty-two";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data: id=" << data.id << ", name=" << data.name << std::endl;

    unsigned long raw = Serializer::serialize(&data);
    std::cout << "Serialized (unsigned long): " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << ptr << std::endl;
    std::cout << "Deserialized Data: id=" << ptr->id << ", name=" << ptr->name << std::endl;

    if (ptr == &data)
        std::cout << "Pointer equality: OK" << std::endl;
    else
        std::cout << "Pointer equality: FAIL" << std::endl;

    return 0;
} 