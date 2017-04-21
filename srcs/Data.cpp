/*
** Data.cpp for cpp_plazza in /home/cheval_8/rendu/cpp_plazza/Data.cpp
**
** Made by Nicolas Chevalier
** Login   <nicolas1.chevalier@epitech.eu>
**
** Started on  lun. avr. 17 16:49:58 2017 Nicolas Chevalier
** Last update lun. avr. 17 16:49:58 2017 Nicolas Chevalier
*/

#include <Data.hpp>

parser::Data::Data(std::string data, std::list<std::string> information) : _name(data)
{
  std::list<std::string>::const_iterator list = information.begin();

  while (list != information.end())
	{
	  addData((*list));
	  list++;
	}
}

parser::Data::~Data()
{
  _information.erase(_information.begin(), _information.end());
}

std::vector<std::string> const &parser::Data::getData() const
{
  return _information;
}

void parser::Data::addData(const std::string &string)
{
  if (!string.empty())
	_information.push_back(string);
}

void parser::Data::setName(std::string name)
{
  if (!name.empty())
	_name = name;
}

const std::string &parser::Data::getName() const
{
  return _name;
}


