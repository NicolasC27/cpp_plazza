//
// PlazzaCore.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Mon Apr 17 13:37:20 2017 Valentin Gérard
// Last update Mon Apr 17 13:37:52 2017 Valentin Gérard
//

#ifndef PLAZZACORE_HPP_
# define PLAZZACORE_HPP_

# include <iostream>

//# include "Data.hpp"

namespace Plazza
{

  class PlazzaCore
  {
   private:
    int _nbThreads;
    //std::vector <Data *> _files;

   public:
    PlazzaCore(int nbThreads);
    PlazzaCore(const PlazzaCore &other);
    PlazzaCore &operator=(const PlazzaCore &other);
    ~PlazzaCore();

    void run();
    /*void ManageCommand(std::string basic_string);
      void createNewData(std::string data);*/
  };

}

#endif /* !PLAZZACORE_HPP_ */
