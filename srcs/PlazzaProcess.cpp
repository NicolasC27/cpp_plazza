//
// PlazzaProcess.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Fri Apr 21 13:37:21 2017 Valentin Gérard
// Last update Fri Apr 21 13:37:22 2017 Valentin Gérard
//

#include "IOfd.hpp"
#include "ThreadPool.hpp"
#include "PlazzaProcess.hpp"

Plazza::PlazzaProcess::PlazzaProcess(int poolSize)
{
  if (this->_fork.isChild())
    {
      try
	{
	  run(poolSize);
	  exit(0);
	}
      catch (std::exception &exception)
	{
	  std::cerr << exception.what() << std::endl;
	  exit(1);
	}
    }
}

Plazza::PlazzaProcess::~PlazzaProcess()
{}

void			Plazza::PlazzaProcess::run(int poolSize)
{
  struct timeval	timeOut;
  ThreadPool		threadPool(poolSize);
  Common::IOfd		iOfd(PIPECOMMAND, O_RDONLY);
  Common::IOfd		iOfdFeed(PIPEFEEDBACK, O_WRONLY);
  std::string		currentCommand;
  fd_set		fdSet = getFdSet(iOfd.getFd());

  while (threadPool.isRunning())
    {
      setTimeOut(timeOut, 5, 0);
      if (select(iOfd.getFd() + 1, &fdSet, 0, 0, &timeOut) <= 0)
	{
	  threadPool.setRunning(false);
	  threadPool.notifyAllWorker();
	}
      else
	{
	  if (this->_semaphore.try_lock())
	    {
	      try
		{
		  currentCommand = iOfd.read();
		  if (currentCommand.empty())
		    throw Common::IOfdException(strerror(errno));
		  threadPool.pushNewCommand(currentCommand);
		  threadPool.notifyWorker();
		  iOfdFeed.write("D");
		}
	      catch (std::exception &exception)
		{
		  std::cerr << exception.what() << std::endl;
		}
	      this->_semaphore.unlock();
	    }
	}
      if (threadPool.getPendingCommandsSize() > poolSize * JOBSPENDING)
	threadPool.waitWorkerAvailable();
    }
}

fd_set		Plazza::PlazzaProcess::getFdSet(int fd)
{
  fd_set	fdSet;

  FD_ZERO(&fdSet);
  FD_SET(fd, &fdSet);
  return fdSet;
}

void Plazza::PlazzaProcess::setTimeOut(struct timeval &timeOut, __time_t seconds, __useconds_t useconds)
{
  timeOut.tv_sec = seconds;
  timeOut.tv_usec = useconds;
}
