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

# include <string>
# include <fstream>
# include <iostream>
# include <sys/stat.h>
# include <unistd.h>

# include "Exception.hpp"

namespace Plazza
{

  class NamedPipe
  {
   private:
    std::string	_fileName;

   public:
    NamedPipe(const std::string &fileName);
    // dangerous copy (unlink destructor)
    // Changer le copy en move ou supprimer la copy
    /*NamedPipe(const NamedPipe &other);
    NamedPipe &operator=(const NamedPipe &other);*/
    ~NamedPipe();

    const std::string &getFileName() const;
    void setFileName(const std::string &fileName);

    // change ifstream/ofstream by read()/write()
    // do fd class (iofd)
    void writer(const std::string &data);
    std::string	reader();
  };

}
#endif /* !NAMEDPIPE_HPP_ */
