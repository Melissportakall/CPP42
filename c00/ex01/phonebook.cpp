/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:07:24 by mportaka          #+#    #+#             */
/*   Updated: 2024/10/16 16:47:35 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <limits>
#include <iostream>
#include <string>


void Contact::set_Name(std::string Name) 
{
    this->Name = Name;
}
void Contact::set_Surname(std::string Surname)
{
    this->Surname = Surname; 
}
void Contact::set_Nickname(std::string Nickname)
{
    this->Nickname = Nickname;
}
void Contact::set_Phonenum(std::string Phonenum)
{
    this->Phonenum = Phonenum;
}
void Contact::set_Secret(std::string Secret)
{
    this->Secret = Secret;
}


std::string Contact::get_Name(void)
{
    return this->Name;
}
std::string Contact::get_Surname(void)
{
    return this->Surname;
}
std::string Contact::get_Nickname(void)
{
    return this->Nickname;
}
std::string Contact::get_Phonenum(void)
{
    return this->Phonenum;
}
std::string Contact::get_Secret(void)
{
    return this->Secret;
}

std::string formatInput(const std::string& input) {
    std::string formatted = input;

    // Eğer girdi 10 karakterden uzun ise, ilk 9 karakteri al ve sonuna "." ekle
    if (formatted.length() > 10) {
        formatted = formatted.substr(0, 9) + ".";
    }

    // Sağdaya dayalı yap
    while (formatted.length() < 10) {
        formatted = " " + formatted; // Boşluk ekleyerek sağa dayalı yap
    }

    return formatted; // Formatlanmış girdi döndür
}


void PhoneBook::ADD(void)
{
    std::cout <<" Please enter personal knowledges ..." << std::endl;
    if(index < 8)
    {
        std::cout <<" Enter name: ";
        std::string name = getstring();
        std::cout <<" Enter surname: ";
        std::string surname = getstring();
        std::cout <<" Enter nickname: ";
        std::string nickname = getstring();
        std::cout <<" Enter phone number: ";
        std::string phonenum = getstring();
        std::cout <<" Enter secret: ";
        std::string secret = getstring();
        

        if(name.empty() || surname.empty() || nickname.empty() || phonenum.empty() || secret.empty())
        {
            std::cout << "person didn't add" << std::endl;
            return; // Fonksiyondan çık
        }
        

        contact[index].set_Name(name);
        contact[index].set_Surname(surname);
        contact[index].set_Nickname(nickname);
        contact[index].set_Phonenum(phonenum);
        contact[index].set_Secret(secret);

        index++;
        if(fixed <= 7)
            fixed++;
        if(index == 8)
        index = 0;
    }
    std::cout << " Person Added " << std::endl;
    std::cout << "Please Enter New Command: ";
}
void PhoneBook::SEARCH(void)
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     index|      name|   surname|  nickname|" << std::endl;
    std::cout << " ------- ------------  ----------  --------- " << std::endl;
    for(int i = 0;i < fixed;i++)
    {
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "|         " << i << "|" << formatInput(contact[i].get_Name()) << "|" << formatInput(contact[i].get_Surname()) << "|" << formatInput(contact[i].get_Nickname()) << "|" << std::endl;
        std::cout << " ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯ ¯¯¯¯¯¯¯¯¯¯" << std::endl;
    }
    std::cout << "Enter index: ";
    int i; 
    std::cin >> i;
    if (std::cin.fail() || i < 0 || i >= fixed)
        std::cout << "Invalid index" << std::endl;
    else {
        std::cout << "First name: " << contact[i].get_Name() << std::endl;
        std::cout << "Surname: " << contact[i].get_Surname() << std::endl;
        std::cout << "Nickname: " << contact[i].get_Nickname() << std::endl;
        std::cout << "Phone number: " << contact[i].get_Phonenum() << std::endl;
        std::cout << "Darkest secret: " << contact[i].get_Secret() << std::endl;
    }
    std::cout << "Please Enter New Command:";
    
}

void PhoneBook::EXIT(void){
    std::cout << "Exiting..." << std::endl;
}

std::string PhoneBook::getstring(void) {
    std::string str;
    std::cin.clear(); // std::cin durumunu temizler
    fflush(stdin); // Giriş akışındaki kalan karakterleri temizler
    std::getline(std::cin, str); // std::cin'den bir satır okur ve str'ye atar
    return str; // str'yi döndürür
}

int main()
{
    PhoneBook phonebook;
    phonebook.index = 0;
    phonebook.fixed = 0;
    
    std::cout << "Welcome Phonebook" << std::endl;
    std::cout << "Please enter ADD-SEARCH-EXIT" << std::endl;
    
    while(1)
    {
        std::string command = phonebook.getstring();
        if(command == "ADD")
        {
            phonebook.ADD();
        }
        else if(command == "SEARCH")
        {
            phonebook.SEARCH();
        }
        else if(command == "EXIT")
        {
            phonebook.EXIT();
            break;
        }
    }
}