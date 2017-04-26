//
// ThreadPool.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Thu Apr 20 12:59:14 2017 Valentin Gérard
// Last update Thu Apr 20 12:59:31 2017 Valentin Gérard
//

#include <iostream>
#include <cstring>
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
      if (!this->_pool.isRunning())
	return;
      command = this->_pool.fetchNextCommand();
      if (!command.empty())
	{
	  processCommand(command);
	  this->_pool.workerAvailableNotify();
	}
    }
}

void Plazza::Worker::processCommand(const std::string &command)
{
}

Plazza::ThreadPool::ThreadPool(int poolSize) : _poolSize(poolSize), _running(true)
{
  for (int i = 0; i < this->_poolSize; i++)
    this->_workers.push_back(new Plazza::Worker(*this));
}

Plazza::ThreadPool::~ThreadPool()
{
  for (unsigned int i = 0; i < this->_workers.size(); i++)
    delete(this->_workers[i]);
}

int Plazza::ThreadPool::getPendingCommandsSize() const
{
  return (int) this->_pendingCommands.size();
}

void Plazza::ThreadPool::setRunning(bool state)
{
  this->_running = state;
}

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

void Plazza::ThreadPool::pushNewCommand(const std::string &command)
{
  this->_pendingCommands.push(command);
}

void Plazza::ThreadPool::notifyWorker()
{
  this->_doWork.notify_one();
}

void Plazza::ThreadPool::notifyAllWorker()
{
  this->_doWork.notify_all();
}

void Plazza::ThreadPool::waitWorkerAvailable()
{
  std::unique_lock<std::mutex> workerAvailable(this->_workerAvailableMutex);
  this->_workerAvailable.wait(workerAvailable);
}
