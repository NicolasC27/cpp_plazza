//
// ThreadPool.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Mon Apr 17 17:31:27 2017 Valentin Gérard
// Last update Mon Apr 17 17:31:52 2017 Valentin Gérard
//

#ifndef THREADPOOL_HPP_
# define THREADPOOL_HPP_

#include <thread>
#include <vector>

class Worker
{
 private:
  std::thread	_workerThread;

 public:

};

class ThreadPool
{
 private:
  std::vector<Worker>	_workers;
  int	_poolSize;

 public:
  ThreadPool(int poolSize);
  ~ThreadPool();

};

#endif /* !THREADPOOL_HPP_ */
