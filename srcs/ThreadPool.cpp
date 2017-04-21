//
// ThreadPool.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Thu Apr 20 12:59:14 2017 Valentin Gérard
// Last update Thu Apr 20 12:59:31 2017 Valentin Gérard
//

#include "../includes/ThreadPool.hpp"

Plazza::Worker::Worker(ThreadPool &pool) : _pool(pool), _workerThread(std::thread(&Plazza::Worker::run, this)), _idle(false)
{}

Plazza::Worker::~Worker()
{
  if (this->_workerThread.joinable())
    this->_workerThread.join();
}

void Plazza::Worker::run()
{
  std::string command;

  while (true)
    {
      command = this->_pool.fetchNextCommand();
      if (!command.empty())
	{
	  processCommand(command);
	  this->_pool.workerAvailableNotify();
	}
      if (!this->_pool.isRunning())
      	return ;
    }
}

void Plazza::Worker::processCommand(const std::string &command)
{

}

Plazza::ThreadPool::ThreadPool(int poolSize) : _poolSize(poolSize)
{
  for (int i = 0; i < this->_poolSize; i++)
    this->_workers.push_back(new Plazza::Worker(*this));
}

Plazza::ThreadPool::~ThreadPool()
{}

std::string 	Plazza::ThreadPool::fetchNextCommand()
{
  std::string	command;

  std::unique_lock<std::mutex> doWorkLock(this->_doWorkMutex);
  if (!this->_running)
    return std::string();
  else if (!this->_pendingCommands.empty())
      {
	command = this->_pendingCommands.front();
	this->_pendingCommands.pop();
	return command;
      }
  this->_doWork.wait(doWorkLock);
  if (this->_pendingCommands.empty())
    return std::string();
  command = this->_pendingCommands.front();
  this->_pendingCommands.pop();
  return command;
}

bool Plazza::ThreadPool::isRunning() const
{
  return this->_running;
}

void Plazza::ThreadPool::workerAvailableNotify()
{
  this->_workerAvailable.notify_one();
}
