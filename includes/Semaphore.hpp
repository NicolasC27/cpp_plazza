//
// Semaphore.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Fri Apr 21 14:05:34 2017 Valentin Gérard
// Last update Fri Apr 21 14:06:46 2017 Valentin Gérard
//

#ifndef SEMAPHORE_HPP_
# define SEMAPHORE_HPP_

# include <sys/ipc.h>
# include <sys/sem.h>

# include "Exception.hpp"

namespace Plazza
{

  class Semaphore
  {
   private:
    key_t _key;
    int _semid;
    struct sembuf _sb;

   public:
    Semaphore();
    ~Semaphore();

    void lock();
    void unlock();
    bool try_lock();
  };

}

#endif /* !SEMAPHORE_HPP_ */
