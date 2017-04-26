//
// NamedPipe.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 16 14:11:02 2017 Valentin Gérard
// Last update Sun Apr 16 14:11:03 2017 Valentin Gérard
//

#include <fcntl.h>
#include "NamedPipe.hpp"

Plazza::NamedPipe::NamedPipe(const std::string &fileName) : _fileName(fileName)
{
  if (mkfifo(this->_fileName.c_str(), S_IRWXU | S_IRGRP | S_IWGRP) == -1)
    throw NamedPipeException(strerror(errno));
  this->_fileIO = new Common::IOfd(this->_fileName, O_RDWR);
}

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
  this->_fileIO->write(data);
}

std::string	Plazza::NamedPipe::reader()
{
  return this->_fileIO->read();
}