/*
** PlazzaCore.cpp for cpp_plazza in /home/cheval_8/rendu/cpp_plazza/PlazzaCore.cpp
**
** Made by Nicolas Chevalier
** Login   <nicolas1.chevalier@epitech.eu>
**
** Started on  jeu. avr. 13 18:21:11 2017 Nicolas Chevalier
** Last update jeu. avr. 13 18:21:11 2017 Nicolas Chevalier
*/

#include <iostream>
#include "PlazzaCore.hpp"

plazza::PlazzaCore::PlazzaCore(size_t nbThreads) : nbThreads(nbThreads)
{

}

void plazza::PlazzaCore::run()
{
  std::string command;

  while (std::getline(std::cin, command))
	{
	  std::cout << command;
	}
}
