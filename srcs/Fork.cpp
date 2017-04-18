//
// Fork.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 16 12:47:22 2017 Valentin Gérard
// Last update Sun Apr 16 12:47:24 2017 Valentin Gérard
//

#include "Fork.hpp"

Plazza::Fork::Fork() : _pid(fork()), _joined(false)
{
  if (this->_pid == -1)
    throw ForkException(strerror(errno));
}

/*Plazza::Fork::Fork(const Fork &other)
{
  this->_pid = other._pid;
  this->_joined = other._joined;
}

Plazza::Fork &Plazza::Fork::operator=(const Fork &other)
{
  if (&other != this)
    {
      this->_pid = other._pid;
      this->_joined = other._joined;
    }
  return (*this);
}*/

Plazza::Fork::~Fork()
{
  if (this->isParent() && !this->_joined)
    this->join();
}

pid_t Plazza::Fork::getPid() const
{
  return this->_pid;
}

bool Plazza::Fork::isParent() const
{
  return !this->isChild();
}

bool Plazza::Fork::isChild() const
{
  return this->_pid == 0;
}

void Plazza::Fork::join()
{
  int status;

  if (this->isParent())
    {
      if (wait(&status) == -1)
	throw ForkException(strerror(errno));
      this->_joined = true;
    }
  else
    throw ForkException("Cannot wait in child process");

}