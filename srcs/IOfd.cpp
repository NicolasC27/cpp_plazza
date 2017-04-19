//
// IOfd.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Wed Apr 19 15:38:21 2017 Valentin Gérard
// Last update Wed Apr 19 15:38:22 2017 Valentin Gérard
//

# include <fcntl.h>
# include <unistd.h>
#include "IOfd.hpp"

Common::IOfd::IOfd(const std::string &fileName, int flags)
{
  this->_fd = open(fileName.c_str(), flags);
  if (this->_fd == -1)
    throw IOfdException(strerror(errno));
}

Common::IOfd::~IOfd()
{
  close(this->_fd);
}

void	Common::IOfd::write(const std::string &data)
{
  int	count = 0;
  int	writeCount;

  do
    {
      writeCount = ::write(this->_fd, data.c_str() + count, data.size() - count);
      if (writeCount == -1)
	throw (IOfdException(strerror(errno)));
      count += writeCount;
    } while ((unsigned) count < data.size());
}

std::string	Common::IOfd::read()
{
  std::string	data;
  std::int32_t	length;
  int		readCount;
  int 		count = 0;

  if (::read(this->_fd, &length, sizeof(length)) <= 0)
    throw IOfdException(strerror(errno));
  data.resize(length);
  do
    {
      readCount = ::read(this->_fd, &data[count], data.size() - count);
      if (readCount == -1)
	throw IOfdException(strerror(errno));
      count += readCount;
    }
  while (readCount > 0);
  return (data);
}