//
// NamedPipe.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 16 14:11:02 2017 Valentin Gérard
// Last update Sun Apr 16 14:11:03 2017 Valentin Gérard
//

#include "NamedPipe.hpp"
#include <iostream>

Plazza::NamedPipe::NamedPipe(const std::string &fileName) : _fileName(fileName + ".fifo")
{
  if (mkfifo(this->_fileName.c_str(), S_IRWXU | S_IRGRP | S_IWGRP) == -1)
    throw NamedPipeException(strerror(errno));
}

/*Plazza::NamedPipe::NamedPipe(const NamedPipe &other)
{
  this->_fileName = other._fileName;
}

Plazza::NamedPipe &Plazza::NamedPipe::operator=(const NamedPipe &other)
{
  if (&other != this)
    this->_fileName = other._fileName;
  return *this;
}*/

Plazza::NamedPipe::~NamedPipe()
{
  unlink(this->_fileName.c_str());
}

const std::string	&Plazza::NamedPipe::getFileName() const
{
  return this->_fileName;
}

void		Plazza::NamedPipe::writer(const std::string &data)
{
  std::ofstream	fileWriter(this->_fileName.c_str(), std::ofstream::out);

  if (fileWriter.is_open())
    fileWriter << data;
  else
    throw NamedPipeException(strerror(errno));
}

std::string	Plazza::NamedPipe::reader()
{
  std::ifstream	fileReader(this->_fileName.c_str(), std::ifstream::in);
  std::string	data;
  std::string	line;

  if (fileReader.is_open())
    {
      while (std::getline(fileReader, line))
	data += line;
    }
  else
    throw NamedPipeException(strerror(errno));
  return (data);
}