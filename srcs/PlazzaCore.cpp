//
// PlazzaCore.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
//
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
//
// Started on  Mon Apr 17 13:38:07 2017 Valentin Gérard
// Last update Mon Apr 17 13:38:07 2017 Valentin Gérard
//

#include "PlazzaCore.hpp"

Plazza::PlazzaCore::PlazzaCore(int nbThreads) : _nbThreads(nbThreads)
{}

Plazza::PlazzaCore::PlazzaCore(const PlazzaCore &other)
{
  this->_nbThreads = other._nbThreads;
}

Plazza::PlazzaCore& Plazza::PlazzaCore::operator=(const PlazzaCore &other)
{
  if (&other != this)
    this->_nbThreads = other._nbThreads;
  return (*this);
}

Plazza::PlazzaCore::~PlazzaCore()
{}

void		Plazza::PlazzaCore::run()
{
  std::string	command;

  while (std::getline(std::cin, command))
    {
      //ManageCommand(command);
      std::cout << command << std::endl;
    }
}

/*void plazza::PlazzaCore::createNewData(std::string data)
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
}*/