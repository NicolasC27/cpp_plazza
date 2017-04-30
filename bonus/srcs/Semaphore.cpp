//
// Semaphore.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Fri Apr 21 14:07:00 2017 Valentin Gérard
// Last update Fri Apr 21 14:07:07 2017 Valentin Gérard
//

#include <iostream>
#include <sys/shm.h>
#include "../includes/Semaphore.hpp"

Plazza::Semaphore::Semaphore()
{
  this->_key = ftok("./", 0);
  if (this->_key == -1)
    throw SemaphoreException(strerror(errno));
  this->_semid = semget(this->_key, 1, SHM_R | SHM_W );
  if (this->_semid == -1)
    throw SemaphoreException(strerror(errno));
  semctl(this->_semid, 0, SETVAL, 1);
}

Plazza::Semaphore::~Semaphore()
{}

void Plazza::Semaphore::lock()
{
  this->_sb.sem_num = 0;
  this->_sb.sem_flg = SEM_UNDO;
  this->_sb.sem_op = -1;
  if (semop(this->_semid, &this->_sb, 1) == -1)
    throw SemaphoreException(strerror(errno));
}

void Plazza::Semaphore::unlock()
{
  this->_sb.sem_num = 0;
  this->_sb.sem_flg = SEM_UNDO;
  this->_sb.sem_op = 1;
  if (semop(this->_semid, &this->_sb, 1) == -1)
    throw SemaphoreException(strerror(errno));
}

bool Plazza::Semaphore::try_lock()
{
  this->_sb.sem_num = 0;
  this->_sb.sem_flg = IPC_NOWAIT;
  this->_sb.sem_op = -1;
  return semop(this->_semid, &this->_sb, 1) != -1;
}
