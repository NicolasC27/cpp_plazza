/*
** Parser.cpp for cpp_plazza in /home/cheval_8/rendu/cpp_plazza/Parser.cpp
**
** Made by Nicolas Chevalier
** Login   <nicolas1.chevalier@epitech.eu>
**
** Started on  ven. avr. 21 15:39:14 2017 Nicolas Chevalier
** Last update ven. avr. 21 15:39:14 2017 Nicolas Chevalier
*/

#include "Parser.hpp"

parser::Parser::Parser()
{
  _files.clear();
}

parser::Parser::~Parser()
{
  _files.erase(_files.begin(), _files.end());
}

void parser::Parser::createNewData(std::string data)
{
  Data *newData;
  std::string save;
  std::list<std::string> list;
  std::list<std::string> information;
  size_t pos = 0;

  setEraseVector(&_files);
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

void parser::Parser::ManageCommand(std::string basic_string)
{
  size_t pos = 0;
  std::string save;

  while ((pos = basic_string.find(';')) != std::string::npos || !basic_string.empty())
	{
	  if (pos == std::string::npos)
		pos = basic_string.size();
	  save = basic_string.substr(0, pos);
	  createNewData(save);
	  basic_string.erase(0, pos + 1);
	}
}

void parser::Parser::setEraseVector(std::vector<Data *> *vector)
{
  vector->erase(vector->begin(), vector->end());
}

const std::vector<parser::Data *> &parser::Parser::getFiles() const
{
  return _files;
}

void parser::Parser::setFiles(const std::vector<parser::Data *> &files)
{
  _files = files;
}



