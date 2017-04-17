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
  run();
}

plazza::PlazzaCore::~PlazzaCore()
{
  _files.erase(_files.begin(), _files.end());
}

void plazza::PlazzaCore::run()
{
  std::string command;

  while (std::getline(std::cin, command))
	{
	  ManageCommand(command);
	  std::cout.flush();
	}
}

void plazza::PlazzaCore::createNewData(std::string data)
{
  Data *newData = new Data(data);

  _files.push_back(newData);
}

void plazza::PlazzaCore::ManageCommand(std::string basic_string)
{
  size_t pos;
  std::string save;

  pos = 0;
  while ((pos = basic_string.find(';')) != std::string::npos || !basic_string.empty())
	{
	  if (pos == std::string::npos)
		pos = basic_string.size();
	  save = basic_string.substr(0, pos);
	  createNewData(save);
	  basic_string.erase(0, pos + 1);
	}
}


