/*
** PlazzaCore.hpp for cpp_plazza in /home/cheval_8/rendu/cpp_plazza/PlazzaCore.hpp
**
** Made by Nicolas Chevalier
** Login   <nicolas1.chevalier@epitech.eu>
**
** Started on  jeu. avr. 13 18:21:11 2017 Nicolas Chevalier
** Last update jeu. avr. 13 18:21:11 2017 Nicolas Chevalier
*/

#ifndef CPP_PLAZZA_PLAZZACORE_HPP
#define CPP_PLAZZA_PLAZZACORE_HPP

#include <cstdio>
#include <vector>
#include <iostream>
#include "Data.hpp"

namespace plazza
{
	class PlazzaCore
	{
		private:
		size_t nbThreads;
		std::vector<Data *> _files;

		public:
		PlazzaCore(size_t nbThreads);

		virtual ~PlazzaCore();

		void run();
		void ManageCommand(std::string basic_string);

		void createNewData(std::string data);
	};
}
#endif //CPP_PLAZZA_PLAZZACORE_HPP
