/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisportakal <melisportakal@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:56:35 by melisportak       #+#    #+#             */
/*   Updated: 2025/01/22 20:40:51 by melisportak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readfile.hpp"
#include <iostream>
#include <fstream>
#include <string>

std::string ReadFile::replace(std::string line, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
    return line;
}

void read_and_write_file(char **av){
    ReadFile a;
    a.filename = av[1];
    a.s1 = av[2];
    a.s2 = av[3];

    std::ifstream originalFile(a.filename);
    if (!originalFile.is_open()) {
        std::cerr << "Unable to open original file" << std::endl;
        return;
    }
    std::ofstream copyFile((a.filename + ".replace"));
    if (!copyFile.is_open()) {
        std::cerr << "Unable to create or open replacement file" << std::endl;
        return;
    }
    std::string line;



    while (getline(originalFile, line)) {
        copyFile << a.replace(line, a.s1, a.s2) << std::endl;
    }

    originalFile.close();
    copyFile.close();
}

int main(int ac, char **av){
    if(ac != 4){
        std::cout << "please enter a FILENAME and two STRINGS thanks" << std::endl;
        return(0);
    }
    read_and_write_file(av);
}