//
// PlazzaCore.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Mon Apr 17 13:37:20 2017 Valentin Gérard
// Last update Sun Apr 23 10:53:53 2017 Valentin Gérard
//

#ifndef PLAZZACORE_HPP_
# define PLAZZACORE_HPP_

# include <vector>
# include <iostream>

# include "PlazzaProcess.hpp"
# include "Parser.hpp"
# include "NamedPipe.hpp"

namespace Plazza
{

  class PlazzaCore
  {
   private:
    int _nbThreads;
    int _nbCommands;
    std::vector<Plazza::PlazzaProcess *> _slaves;

    unsigned int nbProcessNeeded(int nbCurrentCommands, std::vector<Plazza::PlazzaProcess *>slaves);
    void createNewProcess();
    void writeCommands(const std::vector<parser::Data *> files, Plazza::NamedPipe &commandPipe);
    void deleteProcess();

   public:
    PlazzaCore(int nbThreads);
    PlazzaCore(const PlazzaCore &other) = delete;
    PlazzaCore &operator=(const PlazzaCore &other) = delete;
    ~PlazzaCore();

    void run();
  };

}

#endif /* !PLAZZACORE_HPP_ */
