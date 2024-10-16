/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:57:17 by mportaka          #+#    #+#             */
/*   Updated: 2024/10/16 15:07:17 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

class Contact{
    private:
    std::string  Name;
    std::string  Surname;
    std::string  Nickname;
    std::string  Phonenum;
    std::string  Secret;

    public:
    void set_Name(std::string);
    void set_Surname(std::string);
    void set_Nickname(std::string);
    void set_Phonenum(std::string);
    void set_Secret(std::string);

    std::string get_Name(void);
    std::string get_Surname(void);
    std::string get_Nickname(void);
    std::string get_Phonenum(void);
    std::string get_Secret(void);
};

class PhoneBook{
    private:

    public:
    Contact contact[8];
    int index;
    int fixed;

    void ADD(void);
    void SEARCH(void);
    void EXIT(void);

    std::string getstring(void);
};

#endif