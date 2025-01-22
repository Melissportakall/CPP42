/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:57:53 by mportaka          #+#    #+#             */
/*   Updated: 2024/10/16 12:54:31 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) 
{
    if (argc > 1) 
    {
        for (int i = 1; i < argc; i++) 
        {
            int k = 0;
            while (argv[i][k] != '\0') 
            {
                std::cout << (char)(std::toupper(argv[i][k])); 
                k++;
            }
            
        }
         std::cout << std::endl; 
    }
    else 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0; 
}
