//
// PlazzaCore.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
//
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
//
// Started on  Mon Apr 17 13:38:07 2017 Valentin Gérard
// Last update Mon Apr 17 13:38:07 2017 Valentin Gérard
//

#include "Parser.hpp"
#include "PlazzaCore.hpp"

Plazza::PlazzaCore::PlazzaCore(int nbThreads) : _nbThreads(nbThreads)
{}

Plazza::PlazzaCore::PlazzaCore(const PlazzaCore &other)
{
  this->_nbThreads = other._nbThreads;
}

Plazza::PlazzaCore& 	Plazza::PlazzaCore::operator=(const PlazzaCore &other)
{
  if (&other != this)
    this->_nbThreads = other._nbThreads;
  return (*this);
}

Plazza::PlazzaCore::~PlazzaCore()
{}

void					Plazza::PlazzaCore::run()
{
  std::string			command;
  parser::Parser		parse;
  parser::command		infos;

  while (std::getline(std::cin, command))
	{
	  parse.ManageCommand(command);
//	  while ((parse.getCommand()))
//		{
//
//		}
//	  std::cout << parse.getFiles().front()->getName() << std::endl;
//	  std::cout << command << std::endl;
	}
}