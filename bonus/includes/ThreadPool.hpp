//
// ThreadPool.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Thu Apr 20 12:58:20 2017 Valentin Gérard
// Last update Thu Apr 20 12:58:52 2017 Valentin Gérard
//

#ifndef THREADPOOL_HPP_
# define THREADPOOL_HPP_

# include <vector>
# include <thread>
# include <cstdbool>
# include <condition_variable>
# include <queue>

# include "Decryption.hpp"

namespace Plazza
{
  class ThreadPool;

  class Worker
  {
   private:
    ThreadPool &_pool;
    std::thread	_workerThread;
    bool 	_idle;

   public:
    Worker(ThreadPool &pool);
    Worker(const Worker &other) = delete;
    Worker &operator=(const Worker &other) = delete;
    ~Worker();

    void run();
    void processCommand(const std::string &command);
  };

  class ThreadPool
  {
   private:
    int _poolSize;
    bool _running;
    std::vector<Plazza::Worker *> _workers;
    std::queue<std::string> _pendingCommands;
    std::condition_variable _workerAvailable;
    std::condition_variable _doWork;
    std::mutex _doWorkMutex;
    std::mutex _workerAvailableMutex;

   public:
    ThreadPool(int poolSize);
    ThreadPool(const ThreadPool &other) = delete;
    ThreadPool &operator=(const ThreadPool &other) = delete;
    ~ThreadPool();

    int getPendingCommandsSize() const;
    void setRunning(bool state);

    bool isRunning() const;
    std::string	fetchNextCommand();
    void workerAvailableNotify();
    void pushNewCommand(const std::string &command);
    void notifyWorker();
    void notifyAllWorker();
    void waitWorkerAvailable();
  };

}

#endif /* !THREADPOOL_HPP_ */
