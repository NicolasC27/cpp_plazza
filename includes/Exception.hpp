//
// Exception.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 16 13:25:24 2017 Valentin Gérard
// Last update Sun Apr 16 13:25:51 2017 Valentin Gérard
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <string>
# include <stdexcept>
# include <cerrno>
# include <cstring>

namespace Common
{

  class PlazzaException : public std::exception
  {
   protected:
    std::string _message;

   public:
    PlazzaException(const std::string &message) throw();
    virtual ~PlazzaException() throw();

    virtual const char *what() const throw();
  };

  class IOfdException : public PlazzaException
  {
   public:
    IOfdException(const std::string &message) throw();
    virtual ~IOfdException() throw();
  };

}

namespace Plazza
{

  typedef Common::PlazzaException PlazzaException;

  class ForkException : public PlazzaException
  {
   public:
    ForkException(const std::string &message) throw();
    virtual ~ForkException() throw();
  };

  class NamedPipeException : public PlazzaException
  {
   public:
    NamedPipeException(const std::string &message) throw();
    virtual ~NamedPipeException() throw();
  };

}

#endif /* !EXCEPTION_HPP_ */
