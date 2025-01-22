/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:58:24 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/22 20:31:14 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READFILE_HPP
#define READFILE_HPP

#include <fstream>
#include <iostream>
#include <string>

class ReadFile
{
    private:
    public:
        std::string filename;
        std::string s1;
        std::string s2;
        void read_and_write_file(char **av);
        std::string replace(std::string line, const std::string& s1, const std::string& s2);
};

#endif