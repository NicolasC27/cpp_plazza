/*
** Parser.hpp for cpp_plazza in /home/cheval_8/rendu/cpp_plazza/Parser.hpp
**
** Made by Nicolas Chevalier
** Login   <nicolas1.chevalier@epitech.eu>
**
** Started on  ven. avr. 21 15:39:28 2017 Nicolas Chevalier
** Last update ven. avr. 21 15:39:28 2017 Nicolas Chevalier
*/

#ifndef CPP_PLAZZA_PARSER_HPP
#define CPP_PLAZZA_PARSER_HPP

#include <memory>
#include "Data.hpp"

namespace parser
{
	struct command
	{
		std::string name;
		std::vector<std::string> _information;
	};

	class Parser
	{

		std::vector<Data *> _files;
		public:
		Parser();

		virtual ~Parser();

		const std::vector<Data *> &getFiles() const;

		void setFiles(const std::vector<Data *> &files);

		void ManageCommand(std::string basic_string);

		private:
		void setEraseVector(std::vector<Data *> *vector);

		void createNewData(std::string data);

	};

}
#endif //CPP_PLAZZA_PARSER_HPP
