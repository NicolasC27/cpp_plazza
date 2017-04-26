//
// PlazzaProcess.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Fri Apr 21 13:36:39 2017 Valentin Gérard
// Last update Fri Apr 21 13:37:10 2017 Valentin Gérard
//

#ifndef PLAZZAPROCESS_HPP_
# define PLAZZAPROCESS_HPP_

# define JOBSPENDING 2
# define PIPECOMMAND "PlazzaCommand.fifo"
# define PIPEFEEDBACK "PlazzaFeedBack.fifo"

#include <iostream>
#include <unistd.h>
#include <fcntl.h>

# include "Fork.hpp"
# include "Semaphore.hpp"

namespace Plazza
{

  class PlazzaProcess
  {
   private:
    Fork _fork;
    Semaphore _semaphore;

    fd_set getFdSet(int fd);
    void setTimeOut(struct timeval &timeOut, __time_t seconds, __useconds_t useconds);

   public:
    PlazzaProcess(int poolSize);
    ~PlazzaProcess();

    void run(int poolSize);
  };

}

#endif /* !PLAZZAPROCESS_HPP_ */
