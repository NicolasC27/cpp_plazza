//
// Fork.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 16 12:45:21 2017 Valentin Gérard
// Last update Sun Apr 16 12:47:05 2017 Valentin Gérard
//

#ifndef FORK_HPP_
# define FORK_HPP_

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "Exception.hpp"

namespace Plazza
{

  class Fork
  {
   private:
    pid_t _pid;
    bool _joined;

   public:
    Fork();
    // Supprime ou modifier les copies en move
    /*Fork(const Fork &other);
    Fork &operator=(const Fork &other);*/
    ~Fork();

    pid_t getPid() const;

    bool isParent() const;
    bool isChild() const;
    void join();
  };

}
#endif /* !FORK_HPP */
