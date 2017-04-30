//
// main.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Tue Apr 25 23:52:37 2017 Valentin Gérard
// Last update Tue Apr 25 23:52:40 2017 Valentin Gérard
//

#include <cstring>
#include <memory>
#include "PlazzaCore.hpp"

void	usage()
{
  std::cout << "+-------------+" << std::endl;
  std::cout << "| PLAZZA HELP |" << std::endl;
  std::cout << "+-------------+\n" << std::endl;
  std::cout << "USAGE" << std::endl;
  std::cout << "\t./plazza [nbThreads] -> Number of threads in a ThreadPool.\n" << std::endl;
  std::cout << "EXAMPLE" << std::endl;
  std::cout << "\t./plazza 0 or -1 : NOK" << std::endl;
  std::cout << "\t./plazza 5 : OK" << std::endl;
}

int	main(int argc, char **argv)
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

