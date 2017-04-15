/*
** main.cpp for cpp_plazza in /home/cheval_8/rendu/cpp_plazza/main.cpp
**
** Made by Nicolas Chevalier
** Login   <nicolas1.chevalier@epitech.eu>
**
** Started on  jeu. avr. 13 17:30:12 2017 Nicolas Chevalier
** Last update jeu. avr. 13 17:30:12 2017 Nicolas Chevalier
*/


#include <cstdio>
#include <iostream>
#include "PlazzaCore.hpp"

int main(int argc, char **argv)
{
  size_t nbThread;

  if (argc != 2)
	{
	  std::cerr << "./plazza [thread's number >= 0]" << std::endl;
	  return (1);
	}
  nbThread = std::atol(argv[1]);
  if (nbThread <= 0)
	{
	  std::cerr << "./plazza [thread's number >= 0]" << std::endl;
	  return (1);
	}
  plazza::PlazzaCore(std::atol(argv[1]));

}

