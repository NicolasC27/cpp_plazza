//
// NamedPipe.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 16 14:10:10 2017 Valentin Gérard
// Last update Sun Apr 16 14:10:37 2017 Valentin Gérard
//

#ifndef NAMEDPIPE_HPP_
# define NAMEDPIPE_HPP_

# include <sys/stat.h>
# include <unistd.h>

# include "IOfd.hpp"
# include "Exception.hpp"

namespace Plazza
{

  class NamedPipe
  {
   private:
    std::string		_fileName;
    Common::IOfd	*_fileIO;

   public:
    NamedPipe(const std::string &fileName);
    NamedPipe(const NamedPipe &other) = delete;
    NamedPipe &operator=(const NamedPipe &other) = delete;
    ~NamedPipe();

    const std::string &getFileName() const;
    void setFileName(const std::string &fileName);

    void writer(const std::string &data);
    std::string	reader();
  };

}
#endif /* !NAMEDPIPE_HPP_ */
