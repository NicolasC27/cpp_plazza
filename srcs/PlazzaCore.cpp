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
#include <numeric>
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
  Data *newData;
  std::string save;
  std::list<std::string> list;
  std::list<std::string> information;
  size_t pos;
  pos = 0;

  while ((pos = data.find(' ')) != std::string::npos || (pos = data.find('\t')) != std::string::npos || !data.empty())
	{
	  if (pos == std::string::npos)
		pos = data.size();
	  save = data.substr(0, pos);
	  if (save == std::string("PHONE_NUMBER") || save == std::string("EMAIL_ADDRESS") ||
		  save == std::string("IP_ADDRESS"))
		information.push_front(save);
	  else
		list.push_front(save);
	  data.erase(0, pos + 1);
	}
  for (std::list<std::string>::iterator lists = list.begin(); lists != list.end(); ++lists)
	{
	  newData = new Data((*lists), information);
	  _files.push_back(newData);
	}
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


