/*
** main.cpp for cpp_plazza in /home/cheval_8/rendu/cpp_plazza/main.cpp
**
** Made by Nicolas Chevalier
** Login   <nicolas1.chevalier@epitech.eu>
**
** Started on  jeu. avr. 13 17:30:12 2017 Nicolas Chevalier
** Last update jeu. avr. 13 17:30:12 2017 Nicolas Chevalier
*/

#include <cstring>
#include <memory>
#include "PlazzaCore.hpp"

void	usage()
{
  std::cout << "---------------" << std::endl;
  std::cout << "| PLAZZA HELP |" << std::endl;
  std::cout << "---------------\n" << std::endl;
  std::cout << "USAGE" << std::endl;
  std::cout << "\t./plazza [nbThreads] -> Number of threads in a ThreadPool.\n" << std::endl;
  std::cout << "EXAMPLE" << std::endl;
  std::cout << "\t./plazza 0 or -1 : NOK" << std::endl;
  std::cout << "\t./plazza 5 : OK" << std::endl;
}

int main(int argc, char **argv)
{
  int	nbThreads;

  if (argc != 2 || (nbThreads = atoi(argv[1])) <= 0)
    return (usage(), EXIT_FAILURE);
  else if (strcmp(argv[1], "-h") == 0)
    return (usage(), EXIT_SUCCESS);

  try
    {
      std::unique_ptr<Plazza::PlazzaCore> core(new Plazza::PlazzaCore(nbThreads));
      core->run();
    }
  catch (const std::exception &exception)
    {
      std::cerr << exception.what() << std::endl;
      return (EXIT_FAILURE);
    }

  return (EXIT_SUCCESS);
}

