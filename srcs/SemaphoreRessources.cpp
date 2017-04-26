//
// SemaphoreRessources.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Fri Apr 21 14:43:47 2017 Valentin Gérard
// Last update Fri Apr 21 14:43:52 2017 Valentin Gérard
//

#include <sys/shm.h>
#include "SemaphoreRessources.hpp"

Plazza::SemaphoreRessources::SemaphoreRessources()
{
  this->_key = ftok("./", 0);
  if (this->_key == -1)
    throw SemaphoreException(strerror(errno));
  this->_semid = semget(this->_key, 1, IPC_CREAT | SHM_R | SHM_W);
  if (this->_semid == -1)
    throw SemaphoreException(strerror(errno));
  semctl(this->_semid, 0, SETVAL, 1);
}

Plazza::SemaphoreRessources::~SemaphoreRessources()
{
  semctl(this->_semid, 1, IPC_RMID);
}
