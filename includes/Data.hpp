/*
** Parser.hpp for cpp_plazza in /home/cheval_8/rendu/cpp_plazza/Data.hpp
**
** Made by Nicolas Chevalier
** Login   <nicolas1.chevalier@epitech.eu>
**
** Started on  lun. avr. 17 16:50:13 2017 Nicolas Chevalier
** Last update lun. avr. 17 16:50:13 2017 Nicolas Chevalier
*/

#ifndef CPP_PLAZZA_DATA_HPP
#define CPP_PLAZZA_DATA_HPP

#include <vector>
#include <iostream>
#include <list>

class Data
{
	std::string _name;
	std::vector<std::string> _information;

	public:
	Data(std::string data);
	virtual ~Data();

	void addData(std::string const &);
	void parseData(std::string data);


	std::vector<std::string> const &getData() const;
};

#endif //CPP_PLAZZA_DATA_HPP
