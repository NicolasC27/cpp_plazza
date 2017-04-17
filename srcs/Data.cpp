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

Data::Data(std::string data)
{
  parseData(data);
}

Data::~Data()
{
  _information.erase(_information.begin(), _information.end());
}


std::vector<std::string> const &Data::getData() const
{
  return _information;
}

void Data::addData(const std::string &string)
{
  _information.push_back(string);
}

void Data::parseData(std::string data)
{
  size_t pos = 0;
  std::string save;
  size_t first = 0;


  while ((pos = data.find(' ')) != std::string::npos || (pos = data.find('\t')) != std::string::npos || !data.empty())
	{
	  if (pos == std::string::npos)
		pos = data.size();
	  save = data.substr(0, pos);
	  if (first == 0)
		{
		  first = 1;
		  _name = save;
		} else
		{
		  _information.push_back(save);
		}
	  data.erase(0, pos + 1);

	}
}


