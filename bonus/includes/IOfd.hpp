//
// IOfd.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Wed Apr 19 15:38:41 2017 Valentin Gérard
// Last update Wed Apr 19 15:40:49 2017 Valentin Gérard
//

#ifndef IOFD_HPP_
# define IOFD_HPP_

# include "Exception.hpp"

namespace Common
{

  class IOfd
  {
  private:
    int _fd;

    void writeSize(std::int32_t size);
    std::int32_t readSize();

  public:
    IOfd(const std::string &fileName, int flags);
    IOfd(const IOfd &other) = delete;
    IOfd &operator=(const IOfd &other) = delete;
    ~IOfd();

    int getFd() const;

    void write(const std::string &data);
    std::string read();
  };

}

#endif /* !IOFD_HPP */


