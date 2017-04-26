//
// SemaphoreRessources.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Fri Apr 21 14:44:08 2017 Valentin Gérard
// Last update Fri Apr 21 14:44:36 2017 Valentin Gérard
//

#ifndef SEMAPHORERESSOURCES_HPP_
# define SEMAPHORERESSOURCES_HPP_

# include <sys/ipc.h>
# include <sys/sem.h>

# include "Exception.hpp"

namespace Plazza
{

  class SemaphoreRessources
  {
   private:
    key_t _key;
    int _semid;

   public:
    SemaphoreRessources();
    ~SemaphoreRessources();
  };

}

#endif /* !SEMAPHORERESSOURCES_HPP_ */
