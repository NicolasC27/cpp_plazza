//
// Exception.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 16 13:26:07 2017 Valentin Gérard
// Last update Sun Apr 16 13:26:09 2017 Valentin Gérard
//

#include "Exception.hpp"

Plazza::PlazzaException::PlazzaException(const std::string &message) throw() : _message(message)
{}

const char *Plazza::PlazzaException::what() const throw()
{
  return this->_message.c_str();
}

Plazza::PlazzaException::~PlazzaException() throw()
{}

Plazza::ForkException::ForkException(const std::string &message) throw() : PlazzaException(message)
{}

Plazza::ForkException::~ForkException() throw()
{}

Plazza::NamedPipeException::NamedPipeException(const std::string &message) throw() : PlazzaException(message)
{}

Plazza::NamedPipeException::~NamedPipeException() throw()
{}
